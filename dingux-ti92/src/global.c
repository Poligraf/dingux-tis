/*
 *  xtiger port on PSP 
 *
 *  Copyright (C) 2006 Ludovic Jacomme (ludovic.jacomme@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>

#include "global.h"

  TI92_t TI92;
  int    psp_screenshot_mode = 0;

int
ti92_save_configuration(void)
{
  char  chFileName[MAX_PATH + 1];
  FILE* FileDesc;
  int   error = 0;

  strncpy(chFileName, TI92.ti92_home_dir, sizeof(chFileName)-10);
  strcat(chFileName, "/ti92.cfg");

  FileDesc = fopen(chFileName, "w");
  if (FileDesc != (FILE *)0 ) {

    fprintf(FileDesc, "psp_reverse_analog=%d\n", TI92.psp_reverse_analog);
    fprintf(FileDesc, "ti92_render_mode=%d\n"  , TI92.ti92_render_mode);
    fprintf(FileDesc, "ti92_view_fps=%d\n"     , TI92.ti92_view_fps);
    fprintf(FileDesc, "psp_cpu_clock=%d\n"     , TI92.psp_cpu_clock);
    fprintf(FileDesc, "psp_skip_max_frame=%d\n", TI92.psp_skip_max_frame);
    fclose(FileDesc);

  } else {
    error = 1;
  }

  return error;
}

void
myPowerSetClockFrequency(int cpu_clock)
{
  if (TI92.psp_current_clock != cpu_clock) {
    gp2xPowerSetClockFrequency(cpu_clock);
    TI92.psp_current_clock = cpu_clock;
  }
}

int
ti92_parse_configuration(void)
{
  char  chFileName[MAX_PATH + 1];
  char  Buffer[512];
  char *Scan;
  unsigned int Value;
  FILE* FileDesc;

  strncpy(chFileName, TI92.ti92_home_dir, sizeof(chFileName)-10);
  strcat(chFileName, "/ti92.cfg");

  FileDesc = fopen(chFileName, "r");
  if (FileDesc == (FILE *)0 ) return 1;

  while (fgets(Buffer,512, FileDesc) != (char *)0) {

    Scan = strchr(Buffer,'\n');
    if (Scan) *Scan = '\0';
    /* For this #@$% of windows ! */
    Scan = strchr(Buffer,'\r');
    if (Scan) *Scan = '\0';
    if (Buffer[0] == '#') continue;

    Scan = strchr(Buffer,'=');
    if (! Scan) continue;

    *Scan = '\0';
    Value = atoi(Scan+1);

    if (!strcasecmp(Buffer,"ti92_render_mode"))      TI92.ti92_render_mode = Value;
    else
    if (!strcasecmp(Buffer,"ti92_view_fps"))      TI92.ti92_view_fps = Value;
    else
    if (!strcasecmp(Buffer,"psp_cpu_clock"))      TI92.psp_cpu_clock = Value;
    else
    if (!strcasecmp(Buffer,"psp_skip_max_frame")) TI92.psp_skip_max_frame = Value;
    else
    if (!strcasecmp(Buffer,"psp_reverse_analog")) TI92.psp_reverse_analog = Value;
  }

  TI92.psp_skip_cur_frame = 0;

  fclose(FileDesc);

  myPowerSetClockFrequency(TI92.psp_cpu_clock);

  return 0;
}

void
ti92_default_settings()
{
  TI92.psp_reverse_analog = 0;
  TI92.ti92_view_fps      = 0;
  TI92.psp_cpu_clock      = GP2X_DEF_EMU_CLOCK;
  TI92.psp_skip_max_frame = 0;
  TI92.psp_skip_cur_frame = 0;
  TI92.ti92_render_mode = TI92_RENDER_MAX;

  myPowerSetClockFrequency(TI92.psp_cpu_clock);
}

void
ti92_update_save_name()
{
  char        TmpFileName[MAX_PATH];
  struct stat aStat;
  int         index;
  char       *SaveName;
  char       *Scan1;
  char       *Scan2;

  for (index = 0; index < TI92_MAX_SAVE_STATE; index++) {
    TI92.ti92_save_state[index].used  = 0;
    memset(&TI92.ti92_save_state[index].date, 0, sizeof(time_t));

    snprintf(TmpFileName, MAX_PATH, "%s/save/sav_%d.stz", TI92.ti92_home_dir, index);
    if (! stat(TmpFileName, &aStat)) 
    {
      TI92.ti92_save_state[index].used = 1;
      TI92.ti92_save_state[index].date = aStat.st_mtime;
    }
  }
}

void
ti92_kbd_load(void)
{
  char        TmpFileName[MAX_PATH + 1];
  struct stat aStat;

  snprintf(TmpFileName, MAX_PATH, "%s/default.kbd", TI92.ti92_home_dir);
  if (! stat(TmpFileName, &aStat)) {
    psp_kbd_load_mapping(TmpFileName);
  }
}

int
ti92_kbd_save(void)
{
  char TmpFileName[MAX_PATH + 1];
  snprintf(TmpFileName, MAX_PATH, "%s/default.kbd", TI92.ti92_home_dir);
  return( psp_kbd_save_mapping(TmpFileName) );
}

void
ti92_init_resource()
{
  strcpy(TI92.ti92_home_dir, ".");
  strcpy(TI92.psp_screenshot_path, "./scr");

  TI92.psp_screenshot_id   = 0;

  ti92_default_settings();
  psp_kbd_default_settings();
  ti92_parse_configuration();
  ti92_update_save_name();

  ti92_kbd_load();
}

int
ti92_snapshot_save_slot(int save_id)
{
  char      FileName[MAX_PATH+1];
  struct stat aStat;
  int       error;

  error = 1;

  if (save_id < TI92_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s/save/sav_%d.stz", TI92.ti92_home_dir, save_id);
    error = ti92_save_state(FileName);
    if (! error) {
      if (! stat(FileName, &aStat)) 
      {
        TI92.ti92_save_state[save_id].used  = 1;
        TI92.ti92_save_state[save_id].date  = aStat.st_mtime;
      }
    }
  }

  return error;
}

int
ti92_snapshot_load_slot(int load_id)
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  if (load_id < TI92_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s/save/sav_%d.stz", TI92.ti92_home_dir, load_id);
    error = ti92_load_state(FileName);
  }
  return error;
}

int
ti92_snapshot_del_slot(int save_id)
{
  char  FileName[MAX_PATH+1];
  int   error;

  error = 1;

  if (save_id < TI92_MAX_SAVE_STATE) {
    snprintf(FileName, MAX_PATH, "%s/save/sav_%d.stz", TI92.ti92_home_dir, save_id);
    error = remove(FileName);
    if (! error) {
      TI92.ti92_save_state[save_id].used  = 0;
      memset(&TI92.ti92_save_state[save_id].date, 0, sizeof(time_t));
    }
  }

  return error;
}


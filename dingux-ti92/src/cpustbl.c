/*
 *  xtiger port on PSP 
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

#include <stdlib.h>
#include "sysdeps.h"
#include "config.h"
#include "options.h"
#include "memory.h"
#include "newcpu.h"
#include "cputbl.h"
struct cputbl smallcputbl[] = {
{ op_0, 0, 0 },
{ op_10, 0, 16 },
{ op_18, 0, 24 },
{ op_20, 0, 32 },
{ op_28, 0, 40 },
{ op_30, 0, 48 },
{ op_38, 0, 56 },
{ op_39, 0, 57 },
{ op_3c, 0, 60 },
{ op_40, 0, 64 },
{ op_50, 0, 80 },
{ op_58, 0, 88 },
{ op_60, 0, 96 },
{ op_68, 0, 104 },
{ op_70, 0, 112 },
{ op_78, 0, 120 },
{ op_79, 0, 121 },
{ op_7c, 0, 124 },
{ op_80, 0, 128 },
{ op_90, 0, 144 },
{ op_98, 0, 152 },
{ op_a0, 0, 160 },
{ op_a8, 0, 168 },
{ op_b0, 0, 176 },
{ op_b8, 0, 184 },
{ op_b9, 0, 185 },
{ op_100, 0, 256 },
{ op_108, 0, 264 },
{ op_110, 0, 272 },
{ op_118, 0, 280 },
{ op_120, 0, 288 },
{ op_128, 0, 296 },
{ op_130, 0, 304 },
{ op_138, 0, 312 },
{ op_139, 0, 313 },
{ op_13a, 0, 314 },
{ op_13b, 0, 315 },
{ op_13c, 0, 316 },
{ op_140, 0, 320 },
{ op_148, 0, 328 },
{ op_150, 0, 336 },
{ op_158, 0, 344 },
{ op_160, 0, 352 },
{ op_168, 0, 360 },
{ op_170, 0, 368 },
{ op_178, 0, 376 },
{ op_179, 0, 377 },
{ op_17a, 0, 378 },
{ op_17b, 0, 379 },
{ op_180, 0, 384 },
{ op_188, 0, 392 },
{ op_190, 0, 400 },
{ op_198, 0, 408 },
{ op_1a0, 0, 416 },
{ op_1a8, 0, 424 },
{ op_1b0, 0, 432 },
{ op_1b8, 0, 440 },
{ op_1b9, 0, 441 },
{ op_1ba, 0, 442 },
{ op_1bb, 0, 443 },
{ op_1c0, 0, 448 },
{ op_1c8, 0, 456 },
{ op_1d0, 0, 464 },
{ op_1d8, 0, 472 },
{ op_1e0, 0, 480 },
{ op_1e8, 0, 488 },
{ op_1f0, 0, 496 },
{ op_1f8, 0, 504 },
{ op_1f9, 0, 505 },
{ op_1fa, 0, 506 },
{ op_1fb, 0, 507 },
{ op_200, 0, 512 },
{ op_210, 0, 528 },
{ op_218, 0, 536 },
{ op_220, 0, 544 },
{ op_228, 0, 552 },
{ op_230, 0, 560 },
{ op_238, 0, 568 },
{ op_239, 0, 569 },
{ op_23c, 0, 572 },
{ op_240, 0, 576 },
{ op_250, 0, 592 },
{ op_258, 0, 600 },
{ op_260, 0, 608 },
{ op_268, 0, 616 },
{ op_270, 0, 624 },
{ op_278, 0, 632 },
{ op_279, 0, 633 },
{ op_27c, 0, 636 },
{ op_280, 0, 640 },
{ op_290, 0, 656 },
{ op_298, 0, 664 },
{ op_2a0, 0, 672 },
{ op_2a8, 0, 680 },
{ op_2b0, 0, 688 },
{ op_2b8, 0, 696 },
{ op_2b9, 0, 697 },
{ op_400, 0, 1024 },
{ op_410, 0, 1040 },
{ op_418, 0, 1048 },
{ op_420, 0, 1056 },
{ op_428, 0, 1064 },
{ op_430, 0, 1072 },
{ op_438, 0, 1080 },
{ op_439, 0, 1081 },
{ op_440, 0, 1088 },
{ op_450, 0, 1104 },
{ op_458, 0, 1112 },
{ op_460, 0, 1120 },
{ op_468, 0, 1128 },
{ op_470, 0, 1136 },
{ op_478, 0, 1144 },
{ op_479, 0, 1145 },
{ op_480, 0, 1152 },
{ op_490, 0, 1168 },
{ op_498, 0, 1176 },
{ op_4a0, 0, 1184 },
{ op_4a8, 0, 1192 },
{ op_4b0, 0, 1200 },
{ op_4b8, 0, 1208 },
{ op_4b9, 0, 1209 },
{ op_600, 0, 1536 },
{ op_610, 0, 1552 },
{ op_618, 0, 1560 },
{ op_620, 0, 1568 },
{ op_628, 0, 1576 },
{ op_630, 0, 1584 },
{ op_638, 0, 1592 },
{ op_639, 0, 1593 },
{ op_640, 0, 1600 },
{ op_650, 0, 1616 },
{ op_658, 0, 1624 },
{ op_660, 0, 1632 },
{ op_668, 0, 1640 },
{ op_670, 0, 1648 },
{ op_678, 0, 1656 },
{ op_679, 0, 1657 },
{ op_680, 0, 1664 },
{ op_690, 0, 1680 },
{ op_698, 0, 1688 },
{ op_6a0, 0, 1696 },
{ op_6a8, 0, 1704 },
{ op_6b0, 0, 1712 },
{ op_6b8, 0, 1720 },
{ op_6b9, 0, 1721 },
{ op_800, 0, 2048 },
{ op_810, 0, 2064 },
{ op_818, 0, 2072 },
{ op_820, 0, 2080 },
{ op_828, 0, 2088 },
{ op_830, 0, 2096 },
{ op_838, 0, 2104 },
{ op_839, 0, 2105 },
{ op_83a, 0, 2106 },
{ op_83b, 0, 2107 },
{ op_83c, 0, 2108 },
{ op_840, 0, 2112 },
{ op_850, 0, 2128 },
{ op_858, 0, 2136 },
{ op_860, 0, 2144 },
{ op_868, 0, 2152 },
{ op_870, 0, 2160 },
{ op_878, 0, 2168 },
{ op_879, 0, 2169 },
{ op_87a, 0, 2170 },
{ op_87b, 0, 2171 },
{ op_880, 0, 2176 },
{ op_890, 0, 2192 },
{ op_898, 0, 2200 },
{ op_8a0, 0, 2208 },
{ op_8a8, 0, 2216 },
{ op_8b0, 0, 2224 },
{ op_8b8, 0, 2232 },
{ op_8b9, 0, 2233 },
{ op_8ba, 0, 2234 },
{ op_8bb, 0, 2235 },
{ op_8c0, 0, 2240 },
{ op_8d0, 0, 2256 },
{ op_8d8, 0, 2264 },
{ op_8e0, 0, 2272 },
{ op_8e8, 0, 2280 },
{ op_8f0, 0, 2288 },
{ op_8f8, 0, 2296 },
{ op_8f9, 0, 2297 },
{ op_8fa, 0, 2298 },
{ op_8fb, 0, 2299 },
{ op_a00, 0, 2560 },
{ op_a10, 0, 2576 },
{ op_a18, 0, 2584 },
{ op_a20, 0, 2592 },
{ op_a28, 0, 2600 },
{ op_a30, 0, 2608 },
{ op_a38, 0, 2616 },
{ op_a39, 0, 2617 },
{ op_a3c, 0, 2620 },
{ op_a40, 0, 2624 },
{ op_a50, 0, 2640 },
{ op_a58, 0, 2648 },
{ op_a60, 0, 2656 },
{ op_a68, 0, 2664 },
{ op_a70, 0, 2672 },
{ op_a78, 0, 2680 },
{ op_a79, 0, 2681 },
{ op_a7c, 0, 2684 },
{ op_a80, 0, 2688 },
{ op_a90, 0, 2704 },
{ op_a98, 0, 2712 },
{ op_aa0, 0, 2720 },
{ op_aa8, 0, 2728 },
{ op_ab0, 0, 2736 },
{ op_ab8, 0, 2744 },
{ op_ab9, 0, 2745 },
{ op_c00, 0, 3072 },
{ op_c10, 0, 3088 },
{ op_c18, 0, 3096 },
{ op_c20, 0, 3104 },
{ op_c28, 0, 3112 },
{ op_c30, 0, 3120 },
{ op_c38, 0, 3128 },
{ op_c39, 0, 3129 },
{ op_c40, 0, 3136 },
{ op_c50, 0, 3152 },
{ op_c58, 0, 3160 },
{ op_c60, 0, 3168 },
{ op_c68, 0, 3176 },
{ op_c70, 0, 3184 },
{ op_c78, 0, 3192 },
{ op_c79, 0, 3193 },
{ op_c80, 0, 3200 },
{ op_c90, 0, 3216 },
{ op_c98, 0, 3224 },
{ op_ca0, 0, 3232 },
{ op_ca8, 0, 3240 },
{ op_cb0, 0, 3248 },
{ op_cb8, 0, 3256 },
{ op_cb9, 0, 3257 },
{ op_1000, 0, 4096 },
{ op_1010, 0, 4112 },
{ op_1018, 0, 4120 },
{ op_1020, 0, 4128 },
{ op_1028, 0, 4136 },
{ op_1030, 0, 4144 },
{ op_1038, 0, 4152 },
{ op_1039, 0, 4153 },
{ op_103a, 0, 4154 },
{ op_103b, 0, 4155 },
{ op_103c, 0, 4156 },
{ op_1080, 0, 4224 },
{ op_1090, 0, 4240 },
{ op_1098, 0, 4248 },
{ op_10a0, 0, 4256 },
{ op_10a8, 0, 4264 },
{ op_10b0, 0, 4272 },
{ op_10b8, 0, 4280 },
{ op_10b9, 0, 4281 },
{ op_10ba, 0, 4282 },
{ op_10bb, 0, 4283 },
{ op_10bc, 0, 4284 },
{ op_10c0, 0, 4288 },
{ op_10d0, 0, 4304 },
{ op_10d8, 0, 4312 },
{ op_10e0, 0, 4320 },
{ op_10e8, 0, 4328 },
{ op_10f0, 0, 4336 },
{ op_10f8, 0, 4344 },
{ op_10f9, 0, 4345 },
{ op_10fa, 0, 4346 },
{ op_10fb, 0, 4347 },
{ op_10fc, 0, 4348 },
{ op_1100, 0, 4352 },
{ op_1110, 0, 4368 },
{ op_1118, 0, 4376 },
{ op_1120, 0, 4384 },
{ op_1128, 0, 4392 },
{ op_1130, 0, 4400 },
{ op_1138, 0, 4408 },
{ op_1139, 0, 4409 },
{ op_113a, 0, 4410 },
{ op_113b, 0, 4411 },
{ op_113c, 0, 4412 },
{ op_1140, 0, 4416 },
{ op_1150, 0, 4432 },
{ op_1158, 0, 4440 },
{ op_1160, 0, 4448 },
{ op_1168, 0, 4456 },
{ op_1170, 0, 4464 },
{ op_1178, 0, 4472 },
{ op_1179, 0, 4473 },
{ op_117a, 0, 4474 },
{ op_117b, 0, 4475 },
{ op_117c, 0, 4476 },
{ op_1180, 0, 4480 },
{ op_1190, 0, 4496 },
{ op_1198, 0, 4504 },
{ op_11a0, 0, 4512 },
{ op_11a8, 0, 4520 },
{ op_11b0, 0, 4528 },
{ op_11b8, 0, 4536 },
{ op_11b9, 0, 4537 },
{ op_11ba, 0, 4538 },
{ op_11bb, 0, 4539 },
{ op_11bc, 0, 4540 },
{ op_11c0, 0, 4544 },
{ op_11d0, 0, 4560 },
{ op_11d8, 0, 4568 },
{ op_11e0, 0, 4576 },
{ op_11e8, 0, 4584 },
{ op_11f0, 0, 4592 },
{ op_11f8, 0, 4600 },
{ op_11f9, 0, 4601 },
{ op_11fa, 0, 4602 },
{ op_11fb, 0, 4603 },
{ op_11fc, 0, 4604 },
{ op_13c0, 0, 5056 },
{ op_13d0, 0, 5072 },
{ op_13d8, 0, 5080 },
{ op_13e0, 0, 5088 },
{ op_13e8, 0, 5096 },
{ op_13f0, 0, 5104 },
{ op_13f8, 0, 5112 },
{ op_13f9, 0, 5113 },
{ op_13fa, 0, 5114 },
{ op_13fb, 0, 5115 },
{ op_13fc, 0, 5116 },
{ op_2000, 0, 8192 },
{ op_2008, 0, 8200 },
{ op_2010, 0, 8208 },
{ op_2018, 0, 8216 },
{ op_2020, 0, 8224 },
{ op_2028, 0, 8232 },
{ op_2030, 0, 8240 },
{ op_2038, 0, 8248 },
{ op_2039, 0, 8249 },
{ op_203a, 0, 8250 },
{ op_203b, 0, 8251 },
{ op_203c, 0, 8252 },
{ op_2040, 0, 8256 },
{ op_2048, 0, 8264 },
{ op_2050, 0, 8272 },
{ op_2058, 0, 8280 },
{ op_2060, 0, 8288 },
{ op_2068, 0, 8296 },
{ op_2070, 0, 8304 },
{ op_2078, 0, 8312 },
{ op_2079, 0, 8313 },
{ op_207a, 0, 8314 },
{ op_207b, 0, 8315 },
{ op_207c, 0, 8316 },
{ op_2080, 0, 8320 },
{ op_2088, 0, 8328 },
{ op_2090, 0, 8336 },
{ op_2098, 0, 8344 },
{ op_20a0, 0, 8352 },
{ op_20a8, 0, 8360 },
{ op_20b0, 0, 8368 },
{ op_20b8, 0, 8376 },
{ op_20b9, 0, 8377 },
{ op_20ba, 0, 8378 },
{ op_20bb, 0, 8379 },
{ op_20bc, 0, 8380 },
{ op_20c0, 0, 8384 },
{ op_20c8, 0, 8392 },
{ op_20d0, 0, 8400 },
{ op_20d8, 0, 8408 },
{ op_20e0, 0, 8416 },
{ op_20e8, 0, 8424 },
{ op_20f0, 0, 8432 },
{ op_20f8, 0, 8440 },
{ op_20f9, 0, 8441 },
{ op_20fa, 0, 8442 },
{ op_20fb, 0, 8443 },
{ op_20fc, 0, 8444 },
{ op_2100, 0, 8448 },
{ op_2108, 0, 8456 },
{ op_2110, 0, 8464 },
{ op_2118, 0, 8472 },
{ op_2120, 0, 8480 },
{ op_2128, 0, 8488 },
{ op_2130, 0, 8496 },
{ op_2138, 0, 8504 },
{ op_2139, 0, 8505 },
{ op_213a, 0, 8506 },
{ op_213b, 0, 8507 },
{ op_213c, 0, 8508 },
{ op_2140, 0, 8512 },
{ op_2148, 0, 8520 },
{ op_2150, 0, 8528 },
{ op_2158, 0, 8536 },
{ op_2160, 0, 8544 },
{ op_2168, 0, 8552 },
{ op_2170, 0, 8560 },
{ op_2178, 0, 8568 },
{ op_2179, 0, 8569 },
{ op_217a, 0, 8570 },
{ op_217b, 0, 8571 },
{ op_217c, 0, 8572 },
{ op_2180, 0, 8576 },
{ op_2188, 0, 8584 },
{ op_2190, 0, 8592 },
{ op_2198, 0, 8600 },
{ op_21a0, 0, 8608 },
{ op_21a8, 0, 8616 },
{ op_21b0, 0, 8624 },
{ op_21b8, 0, 8632 },
{ op_21b9, 0, 8633 },
{ op_21ba, 0, 8634 },
{ op_21bb, 0, 8635 },
{ op_21bc, 0, 8636 },
{ op_21c0, 0, 8640 },
{ op_21c8, 0, 8648 },
{ op_21d0, 0, 8656 },
{ op_21d8, 0, 8664 },
{ op_21e0, 0, 8672 },
{ op_21e8, 0, 8680 },
{ op_21f0, 0, 8688 },
{ op_21f8, 0, 8696 },
{ op_21f9, 0, 8697 },
{ op_21fa, 0, 8698 },
{ op_21fb, 0, 8699 },
{ op_21fc, 0, 8700 },
{ op_23c0, 0, 9152 },
{ op_23c8, 0, 9160 },
{ op_23d0, 0, 9168 },
{ op_23d8, 0, 9176 },
{ op_23e0, 0, 9184 },
{ op_23e8, 0, 9192 },
{ op_23f0, 0, 9200 },
{ op_23f8, 0, 9208 },
{ op_23f9, 0, 9209 },
{ op_23fa, 0, 9210 },
{ op_23fb, 0, 9211 },
{ op_23fc, 0, 9212 },
{ op_3000, 0, 12288 },
{ op_3008, 0, 12296 },
{ op_3010, 0, 12304 },
{ op_3018, 0, 12312 },
{ op_3020, 0, 12320 },
{ op_3028, 0, 12328 },
{ op_3030, 0, 12336 },
{ op_3038, 0, 12344 },
{ op_3039, 0, 12345 },
{ op_303a, 0, 12346 },
{ op_303b, 0, 12347 },
{ op_303c, 0, 12348 },
{ op_3040, 0, 12352 },
{ op_3048, 0, 12360 },
{ op_3050, 0, 12368 },
{ op_3058, 0, 12376 },
{ op_3060, 0, 12384 },
{ op_3068, 0, 12392 },
{ op_3070, 0, 12400 },
{ op_3078, 0, 12408 },
{ op_3079, 0, 12409 },
{ op_307a, 0, 12410 },
{ op_307b, 0, 12411 },
{ op_307c, 0, 12412 },
{ op_3080, 0, 12416 },
{ op_3088, 0, 12424 },
{ op_3090, 0, 12432 },
{ op_3098, 0, 12440 },
{ op_30a0, 0, 12448 },
{ op_30a8, 0, 12456 },
{ op_30b0, 0, 12464 },
{ op_30b8, 0, 12472 },
{ op_30b9, 0, 12473 },
{ op_30ba, 0, 12474 },
{ op_30bb, 0, 12475 },
{ op_30bc, 0, 12476 },
{ op_30c0, 0, 12480 },
{ op_30c8, 0, 12488 },
{ op_30d0, 0, 12496 },
{ op_30d8, 0, 12504 },
{ op_30e0, 0, 12512 },
{ op_30e8, 0, 12520 },
{ op_30f0, 0, 12528 },
{ op_30f8, 0, 12536 },
{ op_30f9, 0, 12537 },
{ op_30fa, 0, 12538 },
{ op_30fb, 0, 12539 },
{ op_30fc, 0, 12540 },
{ op_3100, 0, 12544 },
{ op_3108, 0, 12552 },
{ op_3110, 0, 12560 },
{ op_3118, 0, 12568 },
{ op_3120, 0, 12576 },
{ op_3128, 0, 12584 },
{ op_3130, 0, 12592 },
{ op_3138, 0, 12600 },
{ op_3139, 0, 12601 },
{ op_313a, 0, 12602 },
{ op_313b, 0, 12603 },
{ op_313c, 0, 12604 },
{ op_3140, 0, 12608 },
{ op_3148, 0, 12616 },
{ op_3150, 0, 12624 },
{ op_3158, 0, 12632 },
{ op_3160, 0, 12640 },
{ op_3168, 0, 12648 },
{ op_3170, 0, 12656 },
{ op_3178, 0, 12664 },
{ op_3179, 0, 12665 },
{ op_317a, 0, 12666 },
{ op_317b, 0, 12667 },
{ op_317c, 0, 12668 },
{ op_3180, 0, 12672 },
{ op_3188, 0, 12680 },
{ op_3190, 0, 12688 },
{ op_3198, 0, 12696 },
{ op_31a0, 0, 12704 },
{ op_31a8, 0, 12712 },
{ op_31b0, 0, 12720 },
{ op_31b8, 0, 12728 },
{ op_31b9, 0, 12729 },
{ op_31ba, 0, 12730 },
{ op_31bb, 0, 12731 },
{ op_31bc, 0, 12732 },
{ op_31c0, 0, 12736 },
{ op_31c8, 0, 12744 },
{ op_31d0, 0, 12752 },
{ op_31d8, 0, 12760 },
{ op_31e0, 0, 12768 },
{ op_31e8, 0, 12776 },
{ op_31f0, 0, 12784 },
{ op_31f8, 0, 12792 },
{ op_31f9, 0, 12793 },
{ op_31fa, 0, 12794 },
{ op_31fb, 0, 12795 },
{ op_31fc, 0, 12796 },
{ op_33c0, 0, 13248 },
{ op_33c8, 0, 13256 },
{ op_33d0, 0, 13264 },
{ op_33d8, 0, 13272 },
{ op_33e0, 0, 13280 },
{ op_33e8, 0, 13288 },
{ op_33f0, 0, 13296 },
{ op_33f8, 0, 13304 },
{ op_33f9, 0, 13305 },
{ op_33fa, 0, 13306 },
{ op_33fb, 0, 13307 },
{ op_33fc, 0, 13308 },
{ op_4000, 0, 16384 },
{ op_4010, 0, 16400 },
{ op_4018, 0, 16408 },
{ op_4020, 0, 16416 },
{ op_4028, 0, 16424 },
{ op_4030, 0, 16432 },
{ op_4038, 0, 16440 },
{ op_4039, 0, 16441 },
{ op_4040, 0, 16448 },
{ op_4050, 0, 16464 },
{ op_4058, 0, 16472 },
{ op_4060, 0, 16480 },
{ op_4068, 0, 16488 },
{ op_4070, 0, 16496 },
{ op_4078, 0, 16504 },
{ op_4079, 0, 16505 },
{ op_4080, 0, 16512 },
{ op_4090, 0, 16528 },
{ op_4098, 0, 16536 },
{ op_40a0, 0, 16544 },
{ op_40a8, 0, 16552 },
{ op_40b0, 0, 16560 },
{ op_40b8, 0, 16568 },
{ op_40b9, 0, 16569 },
{ op_40c0, 0, 16576 },
{ op_40d0, 0, 16592 },
{ op_40d8, 0, 16600 },
{ op_40e0, 0, 16608 },
{ op_40e8, 0, 16616 },
{ op_40f0, 0, 16624 },
{ op_40f8, 0, 16632 },
{ op_40f9, 0, 16633 },
{ op_4180, 0, 16768 },
{ op_4188, 0, 16776 },
{ op_4190, 0, 16784 },
{ op_4198, 0, 16792 },
{ op_41a0, 0, 16800 },
{ op_41a8, 0, 16808 },
{ op_41b0, 0, 16816 },
{ op_41b8, 0, 16824 },
{ op_41b9, 0, 16825 },
{ op_41ba, 0, 16826 },
{ op_41bb, 0, 16827 },
{ op_41bc, 0, 16828 },
{ op_41d0, 0, 16848 },
{ op_41d8, 0, 16856 },
{ op_41e0, 0, 16864 },
{ op_41e8, 0, 16872 },
{ op_41f0, 0, 16880 },
{ op_41f8, 0, 16888 },
{ op_41f9, 0, 16889 },
{ op_41fa, 0, 16890 },
{ op_41fb, 0, 16891 },
{ op_4200, 0, 16896 },
{ op_4210, 0, 16912 },
{ op_4218, 0, 16920 },
{ op_4220, 0, 16928 },
{ op_4228, 0, 16936 },
{ op_4230, 0, 16944 },
{ op_4238, 0, 16952 },
{ op_4239, 0, 16953 },
{ op_4240, 0, 16960 },
{ op_4250, 0, 16976 },
{ op_4258, 0, 16984 },
{ op_4260, 0, 16992 },
{ op_4268, 0, 17000 },
{ op_4270, 0, 17008 },
{ op_4278, 0, 17016 },
{ op_4279, 0, 17017 },
{ op_4280, 0, 17024 },
{ op_4290, 0, 17040 },
{ op_4298, 0, 17048 },
{ op_42a0, 0, 17056 },
{ op_42a8, 0, 17064 },
{ op_42b0, 0, 17072 },
{ op_42b8, 0, 17080 },
{ op_42b9, 0, 17081 },
{ op_4400, 0, 17408 },
{ op_4410, 0, 17424 },
{ op_4418, 0, 17432 },
{ op_4420, 0, 17440 },
{ op_4428, 0, 17448 },
{ op_4430, 0, 17456 },
{ op_4438, 0, 17464 },
{ op_4439, 0, 17465 },
{ op_4440, 0, 17472 },
{ op_4450, 0, 17488 },
{ op_4458, 0, 17496 },
{ op_4460, 0, 17504 },
{ op_4468, 0, 17512 },
{ op_4470, 0, 17520 },
{ op_4478, 0, 17528 },
{ op_4479, 0, 17529 },
{ op_4480, 0, 17536 },
{ op_4490, 0, 17552 },
{ op_4498, 0, 17560 },
{ op_44a0, 0, 17568 },
{ op_44a8, 0, 17576 },
{ op_44b0, 0, 17584 },
{ op_44b8, 0, 17592 },
{ op_44b9, 0, 17593 },
{ op_44c0, 0, 17600 },
{ op_44d0, 0, 17616 },
{ op_44d8, 0, 17624 },
{ op_44e0, 0, 17632 },
{ op_44e8, 0, 17640 },
{ op_44f0, 0, 17648 },
{ op_44f8, 0, 17656 },
{ op_44f9, 0, 17657 },
{ op_44fa, 0, 17658 },
{ op_44fb, 0, 17659 },
{ op_44fc, 0, 17660 },
{ op_4600, 0, 17920 },
{ op_4610, 0, 17936 },
{ op_4618, 0, 17944 },
{ op_4620, 0, 17952 },
{ op_4628, 0, 17960 },
{ op_4630, 0, 17968 },
{ op_4638, 0, 17976 },
{ op_4639, 0, 17977 },
{ op_4640, 0, 17984 },
{ op_4650, 0, 18000 },
{ op_4658, 0, 18008 },
{ op_4660, 0, 18016 },
{ op_4668, 0, 18024 },
{ op_4670, 0, 18032 },
{ op_4678, 0, 18040 },
{ op_4679, 0, 18041 },
{ op_4680, 0, 18048 },
{ op_4690, 0, 18064 },
{ op_4698, 0, 18072 },
{ op_46a0, 0, 18080 },
{ op_46a8, 0, 18088 },
{ op_46b0, 0, 18096 },
{ op_46b8, 0, 18104 },
{ op_46b9, 0, 18105 },
{ op_46c0, 0, 18112 },
{ op_46d0, 0, 18128 },
{ op_46d8, 0, 18136 },
{ op_46e0, 0, 18144 },
{ op_46e8, 0, 18152 },
{ op_46f0, 0, 18160 },
{ op_46f8, 0, 18168 },
{ op_46f9, 0, 18169 },
{ op_46fa, 0, 18170 },
{ op_46fb, 0, 18171 },
{ op_46fc, 0, 18172 },
{ op_4800, 0, 18432 },
{ op_4810, 0, 18448 },
{ op_4818, 0, 18456 },
{ op_4820, 0, 18464 },
{ op_4828, 0, 18472 },
{ op_4830, 0, 18480 },
{ op_4838, 0, 18488 },
{ op_4839, 0, 18489 },
{ op_4840, 0, 18496 },
{ op_4850, 0, 18512 },
{ op_4858, 0, 18520 },
{ op_4860, 0, 18528 },
{ op_4868, 0, 18536 },
{ op_4870, 0, 18544 },
{ op_4878, 0, 18552 },
{ op_4879, 0, 18553 },
{ op_487a, 0, 18554 },
{ op_487b, 0, 18555 },
{ op_4880, 0, 18560 },
{ op_4890, 0, 18576 },
{ op_4898, 0, 18584 },
{ op_48a0, 0, 18592 },
{ op_48a8, 0, 18600 },
{ op_48b0, 0, 18608 },
{ op_48b8, 0, 18616 },
{ op_48b9, 0, 18617 },
{ op_48c0, 0, 18624 },
{ op_48d0, 0, 18640 },
{ op_48d8, 0, 18648 },
{ op_48e0, 0, 18656 },
{ op_48e8, 0, 18664 },
{ op_48f0, 0, 18672 },
{ op_48f8, 0, 18680 },
{ op_48f9, 0, 18681 },
{ op_4a00, 0, 18944 },
{ op_4a10, 0, 18960 },
{ op_4a18, 0, 18968 },
{ op_4a20, 0, 18976 },
{ op_4a28, 0, 18984 },
{ op_4a30, 0, 18992 },
{ op_4a38, 0, 19000 },
{ op_4a39, 0, 19001 },
{ op_4a40, 0, 19008 },
{ op_4a48, 0, 19016 },
{ op_4a50, 0, 19024 },
{ op_4a58, 0, 19032 },
{ op_4a60, 0, 19040 },
{ op_4a68, 0, 19048 },
{ op_4a70, 0, 19056 },
{ op_4a78, 0, 19064 },
{ op_4a79, 0, 19065 },
{ op_4a80, 0, 19072 },
{ op_4a88, 0, 19080 },
{ op_4a90, 0, 19088 },
{ op_4a98, 0, 19096 },
{ op_4aa0, 0, 19104 },
{ op_4aa8, 0, 19112 },
{ op_4ab0, 0, 19120 },
{ op_4ab8, 0, 19128 },
{ op_4ab9, 0, 19129 },
{ op_4c90, 0, 19600 },
{ op_4c98, 0, 19608 },
{ op_4ca0, 0, 19616 },
{ op_4ca8, 0, 19624 },
{ op_4cb0, 0, 19632 },
{ op_4cb8, 0, 19640 },
{ op_4cb9, 0, 19641 },
{ op_4cba, 0, 19642 },
{ op_4cbb, 0, 19643 },
{ op_4cd0, 0, 19664 },
{ op_4cd8, 0, 19672 },
{ op_4ce0, 0, 19680 },
{ op_4ce8, 0, 19688 },
{ op_4cf0, 0, 19696 },
{ op_4cf8, 0, 19704 },
{ op_4cf9, 0, 19705 },
{ op_4cfa, 0, 19706 },
{ op_4cfb, 0, 19707 },
{ op_4e40, 0, 20032 },
{ op_4e50, 0, 20048 },
{ op_4e58, 0, 20056 },
{ op_4e60, 0, 20064 },
{ op_4e68, 0, 20072 },
{ op_4e70, 0, 20080 },
{ op_4e71, 0, 20081 },
{ op_4e72, 0, 20082 },
{ op_4e73, 0, 20083 },
{ op_4e74, 0, 20084 },
{ op_4e75, 0, 20085 },
{ op_4e76, 0, 20086 },
{ op_4e77, 0, 20087 },
{ op_4e90, 0, 20112 },
{ op_4e98, 0, 20120 },
{ op_4ea0, 0, 20128 },
{ op_4ea8, 0, 20136 },
{ op_4eb0, 0, 20144 },
{ op_4eb8, 0, 20152 },
{ op_4eb9, 0, 20153 },
{ op_4eba, 0, 20154 },
{ op_4ebb, 0, 20155 },
{ op_4ed0, 0, 20176 },
{ op_4ed8, 0, 20184 },
{ op_4ee0, 0, 20192 },
{ op_4ee8, 0, 20200 },
{ op_4ef0, 0, 20208 },
{ op_4ef8, 0, 20216 },
{ op_4ef9, 0, 20217 },
{ op_4efa, 0, 20218 },
{ op_4efb, 0, 20219 },
{ op_5000, 0, 20480 },
{ op_5010, 0, 20496 },
{ op_5018, 0, 20504 },
{ op_5020, 0, 20512 },
{ op_5028, 0, 20520 },
{ op_5030, 0, 20528 },
{ op_5038, 0, 20536 },
{ op_5039, 0, 20537 },
{ op_5040, 0, 20544 },
{ op_5048, 0, 20552 },
{ op_5050, 0, 20560 },
{ op_5058, 0, 20568 },
{ op_5060, 0, 20576 },
{ op_5068, 0, 20584 },
{ op_5070, 0, 20592 },
{ op_5078, 0, 20600 },
{ op_5079, 0, 20601 },
{ op_5080, 0, 20608 },
{ op_5088, 0, 20616 },
{ op_5090, 0, 20624 },
{ op_5098, 0, 20632 },
{ op_50a0, 0, 20640 },
{ op_50a8, 0, 20648 },
{ op_50b0, 0, 20656 },
{ op_50b8, 0, 20664 },
{ op_50b9, 0, 20665 },
{ op_50c0, 0, 20672 },
{ op_50c8, 0, 20680 },
{ op_50d0, 0, 20688 },
{ op_50d8, 0, 20696 },
{ op_50e0, 0, 20704 },
{ op_50e8, 0, 20712 },
{ op_50f0, 0, 20720 },
{ op_50f8, 0, 20728 },
{ op_50f9, 0, 20729 },
{ op_5100, 0, 20736 },
{ op_5110, 0, 20752 },
{ op_5118, 0, 20760 },
{ op_5120, 0, 20768 },
{ op_5128, 0, 20776 },
{ op_5130, 0, 20784 },
{ op_5138, 0, 20792 },
{ op_5139, 0, 20793 },
{ op_5140, 0, 20800 },
{ op_5148, 0, 20808 },
{ op_5150, 0, 20816 },
{ op_5158, 0, 20824 },
{ op_5160, 0, 20832 },
{ op_5168, 0, 20840 },
{ op_5170, 0, 20848 },
{ op_5178, 0, 20856 },
{ op_5179, 0, 20857 },
{ op_5180, 0, 20864 },
{ op_5188, 0, 20872 },
{ op_5190, 0, 20880 },
{ op_5198, 0, 20888 },
{ op_51a0, 0, 20896 },
{ op_51a8, 0, 20904 },
{ op_51b0, 0, 20912 },
{ op_51b8, 0, 20920 },
{ op_51b9, 0, 20921 },
{ op_51c0, 0, 20928 },
{ op_51c8, 0, 20936 },
{ op_51d0, 0, 20944 },
{ op_51d8, 0, 20952 },
{ op_51e0, 0, 20960 },
{ op_51e8, 0, 20968 },
{ op_51f0, 0, 20976 },
{ op_51f8, 0, 20984 },
{ op_51f9, 0, 20985 },
{ op_52c0, 0, 21184 },
{ op_52c8, 0, 21192 },
{ op_52d0, 0, 21200 },
{ op_52d8, 0, 21208 },
{ op_52e0, 0, 21216 },
{ op_52e8, 0, 21224 },
{ op_52f0, 0, 21232 },
{ op_52f8, 0, 21240 },
{ op_52f9, 0, 21241 },
{ op_53c0, 0, 21440 },
{ op_53c8, 0, 21448 },
{ op_53d0, 0, 21456 },
{ op_53d8, 0, 21464 },
{ op_53e0, 0, 21472 },
{ op_53e8, 0, 21480 },
{ op_53f0, 0, 21488 },
{ op_53f8, 0, 21496 },
{ op_53f9, 0, 21497 },
{ op_54c0, 0, 21696 },
{ op_54c8, 0, 21704 },
{ op_54d0, 0, 21712 },
{ op_54d8, 0, 21720 },
{ op_54e0, 0, 21728 },
{ op_54e8, 0, 21736 },
{ op_54f0, 0, 21744 },
{ op_54f8, 0, 21752 },
{ op_54f9, 0, 21753 },
{ op_55c0, 0, 21952 },
{ op_55c8, 0, 21960 },
{ op_55d0, 0, 21968 },
{ op_55d8, 0, 21976 },
{ op_55e0, 0, 21984 },
{ op_55e8, 0, 21992 },
{ op_55f0, 0, 22000 },
{ op_55f8, 0, 22008 },
{ op_55f9, 0, 22009 },
{ op_56c0, 0, 22208 },
{ op_56c8, 0, 22216 },
{ op_56d0, 0, 22224 },
{ op_56d8, 0, 22232 },
{ op_56e0, 0, 22240 },
{ op_56e8, 0, 22248 },
{ op_56f0, 0, 22256 },
{ op_56f8, 0, 22264 },
{ op_56f9, 0, 22265 },
{ op_57c0, 0, 22464 },
{ op_57c8, 0, 22472 },
{ op_57d0, 0, 22480 },
{ op_57d8, 0, 22488 },
{ op_57e0, 0, 22496 },
{ op_57e8, 0, 22504 },
{ op_57f0, 0, 22512 },
{ op_57f8, 0, 22520 },
{ op_57f9, 0, 22521 },
{ op_58c0, 0, 22720 },
{ op_58c8, 0, 22728 },
{ op_58d0, 0, 22736 },
{ op_58d8, 0, 22744 },
{ op_58e0, 0, 22752 },
{ op_58e8, 0, 22760 },
{ op_58f0, 0, 22768 },
{ op_58f8, 0, 22776 },
{ op_58f9, 0, 22777 },
{ op_59c0, 0, 22976 },
{ op_59c8, 0, 22984 },
{ op_59d0, 0, 22992 },
{ op_59d8, 0, 23000 },
{ op_59e0, 0, 23008 },
{ op_59e8, 0, 23016 },
{ op_59f0, 0, 23024 },
{ op_59f8, 0, 23032 },
{ op_59f9, 0, 23033 },
{ op_5ac0, 0, 23232 },
{ op_5ac8, 0, 23240 },
{ op_5ad0, 0, 23248 },
{ op_5ad8, 0, 23256 },
{ op_5ae0, 0, 23264 },
{ op_5ae8, 0, 23272 },
{ op_5af0, 0, 23280 },
{ op_5af8, 0, 23288 },
{ op_5af9, 0, 23289 },
{ op_5bc0, 0, 23488 },
{ op_5bc8, 0, 23496 },
{ op_5bd0, 0, 23504 },
{ op_5bd8, 0, 23512 },
{ op_5be0, 0, 23520 },
{ op_5be8, 0, 23528 },
{ op_5bf0, 0, 23536 },
{ op_5bf8, 0, 23544 },
{ op_5bf9, 0, 23545 },
{ op_5cc0, 0, 23744 },
{ op_5cc8, 0, 23752 },
{ op_5cd0, 0, 23760 },
{ op_5cd8, 0, 23768 },
{ op_5ce0, 0, 23776 },
{ op_5ce8, 0, 23784 },
{ op_5cf0, 0, 23792 },
{ op_5cf8, 0, 23800 },
{ op_5cf9, 0, 23801 },
{ op_5dc0, 0, 24000 },
{ op_5dc8, 0, 24008 },
{ op_5dd0, 0, 24016 },
{ op_5dd8, 0, 24024 },
{ op_5de0, 0, 24032 },
{ op_5de8, 0, 24040 },
{ op_5df0, 0, 24048 },
{ op_5df8, 0, 24056 },
{ op_5df9, 0, 24057 },
{ op_5ec0, 0, 24256 },
{ op_5ec8, 0, 24264 },
{ op_5ed0, 0, 24272 },
{ op_5ed8, 0, 24280 },
{ op_5ee0, 0, 24288 },
{ op_5ee8, 0, 24296 },
{ op_5ef0, 0, 24304 },
{ op_5ef8, 0, 24312 },
{ op_5ef9, 0, 24313 },
{ op_5fc0, 0, 24512 },
{ op_5fc8, 0, 24520 },
{ op_5fd0, 0, 24528 },
{ op_5fd8, 0, 24536 },
{ op_5fe0, 0, 24544 },
{ op_5fe8, 0, 24552 },
{ op_5ff0, 0, 24560 },
{ op_5ff8, 0, 24568 },
{ op_5ff9, 0, 24569 },
{ op_6000, 0, 24576 },
{ op_6001, 0, 24577 },
{ op_6100, 0, 24832 },
{ op_6101, 0, 24833 },
{ op_6200, 0, 25088 },
{ op_6201, 0, 25089 },
{ op_6300, 0, 25344 },
{ op_6301, 0, 25345 },
{ op_6400, 0, 25600 },
{ op_6401, 0, 25601 },
{ op_6500, 0, 25856 },
{ op_6501, 0, 25857 },
{ op_6600, 0, 26112 },
{ op_6601, 0, 26113 },
{ op_6700, 0, 26368 },
{ op_6701, 0, 26369 },
{ op_6800, 0, 26624 },
{ op_6801, 0, 26625 },
{ op_6900, 0, 26880 },
{ op_6901, 0, 26881 },
{ op_6a00, 0, 27136 },
{ op_6a01, 0, 27137 },
{ op_6b00, 0, 27392 },
{ op_6b01, 0, 27393 },
{ op_6c00, 0, 27648 },
{ op_6c01, 0, 27649 },
{ op_6d00, 0, 27904 },
{ op_6d01, 0, 27905 },
{ op_6e00, 0, 28160 },
{ op_6e01, 0, 28161 },
{ op_6f00, 0, 28416 },
{ op_6f01, 0, 28417 },
{ op_7000, 0, 28672 },
{ op_8000, 0, 32768 },
{ op_8010, 0, 32784 },
{ op_8018, 0, 32792 },
{ op_8020, 0, 32800 },
{ op_8028, 0, 32808 },
{ op_8030, 0, 32816 },
{ op_8038, 0, 32824 },
{ op_8039, 0, 32825 },
{ op_803a, 0, 32826 },
{ op_803b, 0, 32827 },
{ op_803c, 0, 32828 },
{ op_8040, 0, 32832 },
{ op_8050, 0, 32848 },
{ op_8058, 0, 32856 },
{ op_8060, 0, 32864 },
{ op_8068, 0, 32872 },
{ op_8070, 0, 32880 },
{ op_8078, 0, 32888 },
{ op_8079, 0, 32889 },
{ op_807a, 0, 32890 },
{ op_807b, 0, 32891 },
{ op_807c, 0, 32892 },
{ op_8080, 0, 32896 },
{ op_8090, 0, 32912 },
{ op_8098, 0, 32920 },
{ op_80a0, 0, 32928 },
{ op_80a8, 0, 32936 },
{ op_80b0, 0, 32944 },
{ op_80b8, 0, 32952 },
{ op_80b9, 0, 32953 },
{ op_80ba, 0, 32954 },
{ op_80bb, 0, 32955 },
{ op_80bc, 0, 32956 },
{ op_80c0, 0, 32960 },
{ op_80d0, 0, 32976 },
{ op_80d8, 0, 32984 },
{ op_80e0, 0, 32992 },
{ op_80e8, 0, 33000 },
{ op_80f0, 0, 33008 },
{ op_80f8, 0, 33016 },
{ op_80f9, 0, 33017 },
{ op_80fa, 0, 33018 },
{ op_80fb, 0, 33019 },
{ op_80fc, 0, 33020 },
{ op_8100, 0, 33024 },
{ op_8108, 0, 33032 },
{ op_8110, 0, 33040 },
{ op_8118, 0, 33048 },
{ op_8120, 0, 33056 },
{ op_8128, 0, 33064 },
{ op_8130, 0, 33072 },
{ op_8138, 0, 33080 },
{ op_8139, 0, 33081 },
{ op_8150, 0, 33104 },
{ op_8158, 0, 33112 },
{ op_8160, 0, 33120 },
{ op_8168, 0, 33128 },
{ op_8170, 0, 33136 },
{ op_8178, 0, 33144 },
{ op_8179, 0, 33145 },
{ op_8190, 0, 33168 },
{ op_8198, 0, 33176 },
{ op_81a0, 0, 33184 },
{ op_81a8, 0, 33192 },
{ op_81b0, 0, 33200 },
{ op_81b8, 0, 33208 },
{ op_81b9, 0, 33209 },
{ op_81c0, 0, 33216 },
{ op_81d0, 0, 33232 },
{ op_81d8, 0, 33240 },
{ op_81e0, 0, 33248 },
{ op_81e8, 0, 33256 },
{ op_81f0, 0, 33264 },
{ op_81f8, 0, 33272 },
{ op_81f9, 0, 33273 },
{ op_81fa, 0, 33274 },
{ op_81fb, 0, 33275 },
{ op_81fc, 0, 33276 },
{ op_9000, 0, 36864 },
{ op_9010, 0, 36880 },
{ op_9018, 0, 36888 },
{ op_9020, 0, 36896 },
{ op_9028, 0, 36904 },
{ op_9030, 0, 36912 },
{ op_9038, 0, 36920 },
{ op_9039, 0, 36921 },
{ op_903a, 0, 36922 },
{ op_903b, 0, 36923 },
{ op_903c, 0, 36924 },
{ op_9040, 0, 36928 },
{ op_9048, 0, 36936 },
{ op_9050, 0, 36944 },
{ op_9058, 0, 36952 },
{ op_9060, 0, 36960 },
{ op_9068, 0, 36968 },
{ op_9070, 0, 36976 },
{ op_9078, 0, 36984 },
{ op_9079, 0, 36985 },
{ op_907a, 0, 36986 },
{ op_907b, 0, 36987 },
{ op_907c, 0, 36988 },
{ op_9080, 0, 36992 },
{ op_9088, 0, 37000 },
{ op_9090, 0, 37008 },
{ op_9098, 0, 37016 },
{ op_90a0, 0, 37024 },
{ op_90a8, 0, 37032 },
{ op_90b0, 0, 37040 },
{ op_90b8, 0, 37048 },
{ op_90b9, 0, 37049 },
{ op_90ba, 0, 37050 },
{ op_90bb, 0, 37051 },
{ op_90bc, 0, 37052 },
{ op_90c0, 0, 37056 },
{ op_90c8, 0, 37064 },
{ op_90d0, 0, 37072 },
{ op_90d8, 0, 37080 },
{ op_90e0, 0, 37088 },
{ op_90e8, 0, 37096 },
{ op_90f0, 0, 37104 },
{ op_90f8, 0, 37112 },
{ op_90f9, 0, 37113 },
{ op_90fa, 0, 37114 },
{ op_90fb, 0, 37115 },
{ op_90fc, 0, 37116 },
{ op_9100, 0, 37120 },
{ op_9108, 0, 37128 },
{ op_9110, 0, 37136 },
{ op_9118, 0, 37144 },
{ op_9120, 0, 37152 },
{ op_9128, 0, 37160 },
{ op_9130, 0, 37168 },
{ op_9138, 0, 37176 },
{ op_9139, 0, 37177 },
{ op_9140, 0, 37184 },
{ op_9148, 0, 37192 },
{ op_9150, 0, 37200 },
{ op_9158, 0, 37208 },
{ op_9160, 0, 37216 },
{ op_9168, 0, 37224 },
{ op_9170, 0, 37232 },
{ op_9178, 0, 37240 },
{ op_9179, 0, 37241 },
{ op_9180, 0, 37248 },
{ op_9188, 0, 37256 },
{ op_9190, 0, 37264 },
{ op_9198, 0, 37272 },
{ op_91a0, 0, 37280 },
{ op_91a8, 0, 37288 },
{ op_91b0, 0, 37296 },
{ op_91b8, 0, 37304 },
{ op_91b9, 0, 37305 },
{ op_91c0, 0, 37312 },
{ op_91c8, 0, 37320 },
{ op_91d0, 0, 37328 },
{ op_91d8, 0, 37336 },
{ op_91e0, 0, 37344 },
{ op_91e8, 0, 37352 },
{ op_91f0, 0, 37360 },
{ op_91f8, 0, 37368 },
{ op_91f9, 0, 37369 },
{ op_91fa, 0, 37370 },
{ op_91fb, 0, 37371 },
{ op_91fc, 0, 37372 },
{ op_b000, 0, 45056 },
{ op_b010, 0, 45072 },
{ op_b018, 0, 45080 },
{ op_b020, 0, 45088 },
{ op_b028, 0, 45096 },
{ op_b030, 0, 45104 },
{ op_b038, 0, 45112 },
{ op_b039, 0, 45113 },
{ op_b03a, 0, 45114 },
{ op_b03b, 0, 45115 },
{ op_b03c, 0, 45116 },
{ op_b040, 0, 45120 },
{ op_b048, 0, 45128 },
{ op_b050, 0, 45136 },
{ op_b058, 0, 45144 },
{ op_b060, 0, 45152 },
{ op_b068, 0, 45160 },
{ op_b070, 0, 45168 },
{ op_b078, 0, 45176 },
{ op_b079, 0, 45177 },
{ op_b07a, 0, 45178 },
{ op_b07b, 0, 45179 },
{ op_b07c, 0, 45180 },
{ op_b080, 0, 45184 },
{ op_b088, 0, 45192 },
{ op_b090, 0, 45200 },
{ op_b098, 0, 45208 },
{ op_b0a0, 0, 45216 },
{ op_b0a8, 0, 45224 },
{ op_b0b0, 0, 45232 },
{ op_b0b8, 0, 45240 },
{ op_b0b9, 0, 45241 },
{ op_b0ba, 0, 45242 },
{ op_b0bb, 0, 45243 },
{ op_b0bc, 0, 45244 },
{ op_b0c0, 0, 45248 },
{ op_b0c8, 0, 45256 },
{ op_b0d0, 0, 45264 },
{ op_b0d8, 0, 45272 },
{ op_b0e0, 0, 45280 },
{ op_b0e8, 0, 45288 },
{ op_b0f0, 0, 45296 },
{ op_b0f8, 0, 45304 },
{ op_b0f9, 0, 45305 },
{ op_b0fa, 0, 45306 },
{ op_b0fb, 0, 45307 },
{ op_b0fc, 0, 45308 },
{ op_b100, 0, 45312 },
{ op_b108, 0, 45320 },
{ op_b110, 0, 45328 },
{ op_b118, 0, 45336 },
{ op_b120, 0, 45344 },
{ op_b128, 0, 45352 },
{ op_b130, 0, 45360 },
{ op_b138, 0, 45368 },
{ op_b139, 0, 45369 },
{ op_b140, 0, 45376 },
{ op_b148, 0, 45384 },
{ op_b150, 0, 45392 },
{ op_b158, 0, 45400 },
{ op_b160, 0, 45408 },
{ op_b168, 0, 45416 },
{ op_b170, 0, 45424 },
{ op_b178, 0, 45432 },
{ op_b179, 0, 45433 },
{ op_b180, 0, 45440 },
{ op_b188, 0, 45448 },
{ op_b190, 0, 45456 },
{ op_b198, 0, 45464 },
{ op_b1a0, 0, 45472 },
{ op_b1a8, 0, 45480 },
{ op_b1b0, 0, 45488 },
{ op_b1b8, 0, 45496 },
{ op_b1b9, 0, 45497 },
{ op_b1c0, 0, 45504 },
{ op_b1c8, 0, 45512 },
{ op_b1d0, 0, 45520 },
{ op_b1d8, 0, 45528 },
{ op_b1e0, 0, 45536 },
{ op_b1e8, 0, 45544 },
{ op_b1f0, 0, 45552 },
{ op_b1f8, 0, 45560 },
{ op_b1f9, 0, 45561 },
{ op_b1fa, 0, 45562 },
{ op_b1fb, 0, 45563 },
{ op_b1fc, 0, 45564 },
{ op_c000, 0, 49152 },
{ op_c010, 0, 49168 },
{ op_c018, 0, 49176 },
{ op_c020, 0, 49184 },
{ op_c028, 0, 49192 },
{ op_c030, 0, 49200 },
{ op_c038, 0, 49208 },
{ op_c039, 0, 49209 },
{ op_c03a, 0, 49210 },
{ op_c03b, 0, 49211 },
{ op_c03c, 0, 49212 },
{ op_c040, 0, 49216 },
{ op_c050, 0, 49232 },
{ op_c058, 0, 49240 },
{ op_c060, 0, 49248 },
{ op_c068, 0, 49256 },
{ op_c070, 0, 49264 },
{ op_c078, 0, 49272 },
{ op_c079, 0, 49273 },
{ op_c07a, 0, 49274 },
{ op_c07b, 0, 49275 },
{ op_c07c, 0, 49276 },
{ op_c080, 0, 49280 },
{ op_c090, 0, 49296 },
{ op_c098, 0, 49304 },
{ op_c0a0, 0, 49312 },
{ op_c0a8, 0, 49320 },
{ op_c0b0, 0, 49328 },
{ op_c0b8, 0, 49336 },
{ op_c0b9, 0, 49337 },
{ op_c0ba, 0, 49338 },
{ op_c0bb, 0, 49339 },
{ op_c0bc, 0, 49340 },
{ op_c0c0, 0, 49344 },
{ op_c0d0, 0, 49360 },
{ op_c0d8, 0, 49368 },
{ op_c0e0, 0, 49376 },
{ op_c0e8, 0, 49384 },
{ op_c0f0, 0, 49392 },
{ op_c0f8, 0, 49400 },
{ op_c0f9, 0, 49401 },
{ op_c0fa, 0, 49402 },
{ op_c0fb, 0, 49403 },
{ op_c0fc, 0, 49404 },
{ op_c100, 0, 49408 },
{ op_c108, 0, 49416 },
{ op_c110, 0, 49424 },
{ op_c118, 0, 49432 },
{ op_c120, 0, 49440 },
{ op_c128, 0, 49448 },
{ op_c130, 0, 49456 },
{ op_c138, 0, 49464 },
{ op_c139, 0, 49465 },
{ op_c140, 0, 49472 },
{ op_c148, 0, 49480 },
{ op_c150, 0, 49488 },
{ op_c158, 0, 49496 },
{ op_c160, 0, 49504 },
{ op_c168, 0, 49512 },
{ op_c170, 0, 49520 },
{ op_c178, 0, 49528 },
{ op_c179, 0, 49529 },
{ op_c188, 0, 49544 },
{ op_c190, 0, 49552 },
{ op_c198, 0, 49560 },
{ op_c1a0, 0, 49568 },
{ op_c1a8, 0, 49576 },
{ op_c1b0, 0, 49584 },
{ op_c1b8, 0, 49592 },
{ op_c1b9, 0, 49593 },
{ op_c1c0, 0, 49600 },
{ op_c1d0, 0, 49616 },
{ op_c1d8, 0, 49624 },
{ op_c1e0, 0, 49632 },
{ op_c1e8, 0, 49640 },
{ op_c1f0, 0, 49648 },
{ op_c1f8, 0, 49656 },
{ op_c1f9, 0, 49657 },
{ op_c1fa, 0, 49658 },
{ op_c1fb, 0, 49659 },
{ op_c1fc, 0, 49660 },
{ op_d000, 0, 53248 },
{ op_d010, 0, 53264 },
{ op_d018, 0, 53272 },
{ op_d020, 0, 53280 },
{ op_d028, 0, 53288 },
{ op_d030, 0, 53296 },
{ op_d038, 0, 53304 },
{ op_d039, 0, 53305 },
{ op_d03a, 0, 53306 },
{ op_d03b, 0, 53307 },
{ op_d03c, 0, 53308 },
{ op_d040, 0, 53312 },
{ op_d048, 0, 53320 },
{ op_d050, 0, 53328 },
{ op_d058, 0, 53336 },
{ op_d060, 0, 53344 },
{ op_d068, 0, 53352 },
{ op_d070, 0, 53360 },
{ op_d078, 0, 53368 },
{ op_d079, 0, 53369 },
{ op_d07a, 0, 53370 },
{ op_d07b, 0, 53371 },
{ op_d07c, 0, 53372 },
{ op_d080, 0, 53376 },
{ op_d088, 0, 53384 },
{ op_d090, 0, 53392 },
{ op_d098, 0, 53400 },
{ op_d0a0, 0, 53408 },
{ op_d0a8, 0, 53416 },
{ op_d0b0, 0, 53424 },
{ op_d0b8, 0, 53432 },
{ op_d0b9, 0, 53433 },
{ op_d0ba, 0, 53434 },
{ op_d0bb, 0, 53435 },
{ op_d0bc, 0, 53436 },
{ op_d0c0, 0, 53440 },
{ op_d0c8, 0, 53448 },
{ op_d0d0, 0, 53456 },
{ op_d0d8, 0, 53464 },
{ op_d0e0, 0, 53472 },
{ op_d0e8, 0, 53480 },
{ op_d0f0, 0, 53488 },
{ op_d0f8, 0, 53496 },
{ op_d0f9, 0, 53497 },
{ op_d0fa, 0, 53498 },
{ op_d0fb, 0, 53499 },
{ op_d0fc, 0, 53500 },
{ op_d100, 0, 53504 },
{ op_d108, 0, 53512 },
{ op_d110, 0, 53520 },
{ op_d118, 0, 53528 },
{ op_d120, 0, 53536 },
{ op_d128, 0, 53544 },
{ op_d130, 0, 53552 },
{ op_d138, 0, 53560 },
{ op_d139, 0, 53561 },
{ op_d140, 0, 53568 },
{ op_d148, 0, 53576 },
{ op_d150, 0, 53584 },
{ op_d158, 0, 53592 },
{ op_d160, 0, 53600 },
{ op_d168, 0, 53608 },
{ op_d170, 0, 53616 },
{ op_d178, 0, 53624 },
{ op_d179, 0, 53625 },
{ op_d180, 0, 53632 },
{ op_d188, 0, 53640 },
{ op_d190, 0, 53648 },
{ op_d198, 0, 53656 },
{ op_d1a0, 0, 53664 },
{ op_d1a8, 0, 53672 },
{ op_d1b0, 0, 53680 },
{ op_d1b8, 0, 53688 },
{ op_d1b9, 0, 53689 },
{ op_d1c0, 0, 53696 },
{ op_d1c8, 0, 53704 },
{ op_d1d0, 0, 53712 },
{ op_d1d8, 0, 53720 },
{ op_d1e0, 0, 53728 },
{ op_d1e8, 0, 53736 },
{ op_d1f0, 0, 53744 },
{ op_d1f8, 0, 53752 },
{ op_d1f9, 0, 53753 },
{ op_d1fa, 0, 53754 },
{ op_d1fb, 0, 53755 },
{ op_d1fc, 0, 53756 },
{ op_e000, 0, 57344 },
{ op_e008, 0, 57352 },
{ op_e010, 0, 57360 },
{ op_e018, 0, 57368 },
{ op_e020, 0, 57376 },
{ op_e028, 0, 57384 },
{ op_e030, 0, 57392 },
{ op_e038, 0, 57400 },
{ op_e040, 0, 57408 },
{ op_e048, 0, 57416 },
{ op_e050, 0, 57424 },
{ op_e058, 0, 57432 },
{ op_e060, 0, 57440 },
{ op_e068, 0, 57448 },
{ op_e070, 0, 57456 },
{ op_e078, 0, 57464 },
{ op_e080, 0, 57472 },
{ op_e088, 0, 57480 },
{ op_e090, 0, 57488 },
{ op_e098, 0, 57496 },
{ op_e0a0, 0, 57504 },
{ op_e0a8, 0, 57512 },
{ op_e0b0, 0, 57520 },
{ op_e0b8, 0, 57528 },
{ op_e0d0, 0, 57552 },
{ op_e0d8, 0, 57560 },
{ op_e0e0, 0, 57568 },
{ op_e0e8, 0, 57576 },
{ op_e0f0, 0, 57584 },
{ op_e0f8, 0, 57592 },
{ op_e0f9, 0, 57593 },
{ op_e100, 0, 57600 },
{ op_e108, 0, 57608 },
{ op_e110, 0, 57616 },
{ op_e118, 0, 57624 },
{ op_e120, 0, 57632 },
{ op_e128, 0, 57640 },
{ op_e130, 0, 57648 },
{ op_e138, 0, 57656 },
{ op_e140, 0, 57664 },
{ op_e148, 0, 57672 },
{ op_e150, 0, 57680 },
{ op_e158, 0, 57688 },
{ op_e160, 0, 57696 },
{ op_e168, 0, 57704 },
{ op_e170, 0, 57712 },
{ op_e178, 0, 57720 },
{ op_e180, 0, 57728 },
{ op_e188, 0, 57736 },
{ op_e190, 0, 57744 },
{ op_e198, 0, 57752 },
{ op_e1a0, 0, 57760 },
{ op_e1a8, 0, 57768 },
{ op_e1b0, 0, 57776 },
{ op_e1b8, 0, 57784 },
{ op_e1d0, 0, 57808 },
{ op_e1d8, 0, 57816 },
{ op_e1e0, 0, 57824 },
{ op_e1e8, 0, 57832 },
{ op_e1f0, 0, 57840 },
{ op_e1f8, 0, 57848 },
{ op_e1f9, 0, 57849 },
{ op_e2d0, 0, 58064 },
{ op_e2d8, 0, 58072 },
{ op_e2e0, 0, 58080 },
{ op_e2e8, 0, 58088 },
{ op_e2f0, 0, 58096 },
{ op_e2f8, 0, 58104 },
{ op_e2f9, 0, 58105 },
{ op_e3d0, 0, 58320 },
{ op_e3d8, 0, 58328 },
{ op_e3e0, 0, 58336 },
{ op_e3e8, 0, 58344 },
{ op_e3f0, 0, 58352 },
{ op_e3f8, 0, 58360 },
{ op_e3f9, 0, 58361 },
{ op_e4d0, 0, 58576 },
{ op_e4d8, 0, 58584 },
{ op_e4e0, 0, 58592 },
{ op_e4e8, 0, 58600 },
{ op_e4f0, 0, 58608 },
{ op_e4f8, 0, 58616 },
{ op_e4f9, 0, 58617 },
{ op_e5d0, 0, 58832 },
{ op_e5d8, 0, 58840 },
{ op_e5e0, 0, 58848 },
{ op_e5e8, 0, 58856 },
{ op_e5f0, 0, 58864 },
{ op_e5f8, 0, 58872 },
{ op_e5f9, 0, 58873 },
{ op_e6d0, 0, 59088 },
{ op_e6d8, 0, 59096 },
{ op_e6e0, 0, 59104 },
{ op_e6e8, 0, 59112 },
{ op_e6f0, 0, 59120 },
{ op_e6f8, 0, 59128 },
{ op_e6f9, 0, 59129 },
{ op_e7d0, 0, 59344 },
{ op_e7d8, 0, 59352 },
{ op_e7e0, 0, 59360 },
{ op_e7e8, 0, 59368 },
{ op_e7f0, 0, 59376 },
{ op_e7f8, 0, 59384 },
{ op_e7f9, 0, 59385 },
{ 0, 0, 0 }};

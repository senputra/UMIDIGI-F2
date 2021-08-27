/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include "camera_custom_nvram.h"
#include "ov16880mipiraw_Scene_Capture.h"

const FLASH_CALIBRATION_NVRAM_T ov16880mipiraw_Flash_Calibration_0000 = {
    .engTab = {
        .exp = 10000,
        .afe_gain = 1024,
        .isp_gain = 1024,
        .distance = 0,
        .yTab =     {
           0, 346, 708,1057,1397,1725,2040,2349,2650,2942,3226,3507,3773,4034,4287,4538,4783,6178,6554,6901,7221,7495,7743,7974,8174,8303,8396,
         237, 605, 971,1323,1658,1983,2300,2609,2910,3200,3485,3766,4030,4290,4546,4794,5038,6422,6802,7140,7458,7733,7976,8178,8360,8510,  -1,
         504, 873,1238,1586,1921,2249,2566,2873,3173,3464,3747,4025,4291,4551,4804,5053,5298,6686,7062,7401,7708,7985,8245,8444,8607,8760,  -1,
         761,1132,1493,1841,2176,2503,2821,3129,3429,3719,4003,4280,4546,4806,5056,5306,5548,7195,7564,7901,8204,8504,8730,8939,9100,  -1,  -1,
        1007,1375,1738,2086,2423,2750,3067,3375,3674,3964,4247,4524,4788,5047,5299,5547,5790,7423,7797,8126,8434,8705,8957,9153,9318,  -1,  -1,
        1244,1613,1979,2327,2664,2990,3306,3613,3912,4202,4482,4759,5025,5281,5534,5781,6027,7651,8017,8364,8656,8932,9193,9378,  -1,  -1,  -1,
        1474,1847,2211,2559,2895,3221,3537,3843,4142,4430,4712,4988,5253,5510,5760,6011,6254,8086,8452,8813,9092,9360,9601,9800,  -1,  -1,  -1,
        1698,2071,2435,2784,3118,3445,3760,4066,4365,4654,4934,5210,5475,5731,5984,6231,6475,8290,8655,8994,9304,9571,9810,  -1,  -1,  -1,  -1,
        1918,2290,2654,3003,3338,3662,3979,4283,4583,4870,5151,5427,5690,5946,6199,6446,6691,8502,8858,9197,9500,9767,9999,  -1,  -1,  -1,  -1,
        2130,2503,2866,3214,3550,3874,4189,4494,4792,5081,5361,5638,5900,6160,6410,6657,6898,8693,9054,9397,9690,9960,  -1,  -1,  -1,  -1,  -1,
        2336,2709,3072,3420,3755,4079,4394,4699,4998,5285,5566,5840,6105,6360,6610,6857,7104,8889,9241,9578,9872,  -1,  -1,  -1,  -1,  -1,  -1,
        2535,2907,3270,3617,3953,4277,4591,4896,5195,5481,5760,6036,6300,6555,6807,7052,7297,9075,9436,9752,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        2727,3099,3463,3809,4144,4469,4782,5088,5385,5673,5953,6225,6486,6747,6995,7241,7486,9246,9613,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        2915,3286,3649,3998,4330,4655,4968,5274,5572,5857,6136,6412,6673,6930,7179,7426,7668,9414,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3097,3468,3831,4177,4511,4836,5152,5454,5753,6037,6320,6593,6853,7109,7359,7611,7856,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3275,3645,4009,4356,4689,5013,5328,5635,5928,6216,6497,6770,7029,7287,7538,7786,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        3446,3818,4180,4530,4860,5184,5500,5803,6103,6386,6668,6942,7207,7462,7711,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4405,4775,5151,5862,6181,6511,7118,7408,7690,7970,8235,8490,8739,8991,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4661,5028,5406,6108,6442,6766,7365,7665,7952,8228,8484,8741,8991,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        4896,5277,5658,6349,6691,6996,7607,7913,8185,8449,8718,8980,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5119,5479,5861,6556,6890,7218,7810,8111,8395,8670,8928,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5297,5671,6058,6752,7079,7399,8001,8305,8595,8854,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5471,5835,6233,6928,7271,7562,8179,8462,8756,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5629,5988,6370,7055,7411,7736,8312,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5743,6114,6500,7203,7517,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5858,6221,6594,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        5912,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    }
    },
    .flashWBGain = {

    { 574, 512, 574},  //duty=-1, dutyLt=-1
    { 866, 512, 909},  //duty=0, dutyLt=-1
    { 870, 512, 917},  //duty=1, dutyLt=-1
    { 870, 512, 918},  //duty=2, dutyLt=-1
    { 870, 512, 917},  //duty=3, dutyLt=-1
    { 871, 512, 918},  //duty=4, dutyLt=-1
    { 872, 512, 917},  //duty=5, dutyLt=-1
    { 880, 512, 926},  //duty=6, dutyLt=-1
    { 880, 512, 926},  //duty=7, dutyLt=-1
    { 880, 512, 925},  //duty=8, dutyLt=-1
    { 880, 512, 924},  //duty=9, dutyLt=-1
    { 881, 512, 922},  //duty=10, dutyLt=-1
    { 881, 512, 920},  //duty=11, dutyLt=-1
    { 881, 512, 919},  //duty=12, dutyLt=-1
    { 882, 512, 917},  //duty=13, dutyLt=-1
    { 882, 512, 916},  //duty=14, dutyLt=-1
    { 883, 512, 915},  //duty=15, dutyLt=-1
    { 886, 512, 903},  //duty=16, dutyLt=-1
    { 887, 512, 898},  //duty=17, dutyLt=-1
    { 888, 512, 893},  //duty=18, dutyLt=-1
    { 889, 512, 888},  //duty=19, dutyLt=-1
    { 890, 512, 882},  //duty=20, dutyLt=-1
    { 891, 512, 876},  //duty=21, dutyLt=-1
    { 892, 512, 871},  //duty=22, dutyLt=-1
    { 894, 512, 865},  //duty=23, dutyLt=-1
    { 895, 512, 857},  //duty=24, dutyLt=-1
    { 897, 512, 849},  //duty=25, dutyLt=-1
    { 476, 512,1337},  //duty=-1, dutyLt=0
    { 662, 512,1044},  //duty=0, dutyLt=0
    { 728, 512, 990},  //duty=1, dutyLt=0
    { 761, 512, 969},  //duty=2, dutyLt=0
    { 781, 512, 958},  //duty=3, dutyLt=0
    { 795, 512, 951},  //duty=4, dutyLt=0
    { 811, 512, 956},  //duty=5, dutyLt=0
    { 818, 512, 952},  //duty=6, dutyLt=0
    { 824, 512, 948},  //duty=7, dutyLt=0
    { 829, 512, 944},  //duty=8, dutyLt=0
    { 833, 512, 941},  //duty=9, dutyLt=0
    { 837, 512, 939},  //duty=10, dutyLt=0
    { 840, 512, 936},  //duty=11, dutyLt=0
    { 842, 512, 934},  //duty=12, dutyLt=0
    { 845, 512, 932},  //duty=13, dutyLt=0
    { 847, 512, 929},  //duty=14, dutyLt=0
    { 849, 512, 927},  //duty=15, dutyLt=0
    { 859, 512, 912},  //duty=16, dutyLt=0
    { 861, 512, 907},  //duty=17, dutyLt=0
    { 864, 512, 901},  //duty=18, dutyLt=0
    { 866, 512, 896},  //duty=19, dutyLt=0
    { 867, 512, 890},  //duty=20, dutyLt=0
    { 869, 512, 884},  //duty=21, dutyLt=0
    { 871, 512, 876},  //duty=22, dutyLt=0
    { 873, 512, 870},  //duty=23, dutyLt=0
    { 875, 512, 863},  //duty=24, dutyLt=0
    { 512, 512, 512},  //duty=25, dutyLt=0
    { 478, 512,1341},  //duty=-1, dutyLt=1
    { 598, 512,1114},  //duty=0, dutyLt=1
    { 661, 512,1043},  //duty=1, dutyLt=1
    { 699, 512,1012},  //duty=2, dutyLt=1
    { 725, 512, 993},  //duty=3, dutyLt=1
    { 748, 512, 994},  //duty=4, dutyLt=1
    { 761, 512, 982},  //duty=5, dutyLt=1
    { 773, 512, 975},  //duty=6, dutyLt=1
    { 782, 512, 968},  //duty=7, dutyLt=1
    { 789, 512, 963},  //duty=8, dutyLt=1
    { 796, 512, 959},  //duty=9, dutyLt=1
    { 801, 512, 955},  //duty=10, dutyLt=1
    { 806, 512, 951},  //duty=11, dutyLt=1
    { 810, 512, 948},  //duty=12, dutyLt=1
    { 814, 512, 945},  //duty=13, dutyLt=1
    { 818, 512, 941},  //duty=14, dutyLt=1
    { 821, 512, 939},  //duty=15, dutyLt=1
    { 835, 512, 922},  //duty=16, dutyLt=1
    { 839, 512, 917},  //duty=17, dutyLt=1
    { 841, 512, 910},  //duty=18, dutyLt=1
    { 844, 512, 905},  //duty=19, dutyLt=1
    { 847, 512, 898},  //duty=20, dutyLt=1
    { 849, 512, 892},  //duty=21, dutyLt=1
    { 851, 512, 885},  //duty=22, dutyLt=1
    { 853, 512, 878},  //duty=23, dutyLt=1
    { 855, 512, 871},  //duty=24, dutyLt=1
    { 512, 512, 512},  //duty=25, dutyLt=1
    { 479, 512,1361},  //duty=-1, dutyLt=2
    { 569, 512,1156},  //duty=0, dutyLt=2
    { 624, 512,1083},  //duty=1, dutyLt=2
    { 661, 512,1045},  //duty=2, dutyLt=2
    { 688, 512,1021},  //duty=3, dutyLt=2
    { 710, 512,1017},  //duty=4, dutyLt=2
    { 726, 512,1004},  //duty=5, dutyLt=2
    { 739, 512, 995},  //duty=6, dutyLt=2
    { 750, 512, 986},  //duty=7, dutyLt=2
    { 759, 512, 979},  //duty=8, dutyLt=2
    { 767, 512, 974},  //duty=9, dutyLt=2
    { 774, 512, 969},  //duty=10, dutyLt=2
    { 779, 512, 965},  //duty=11, dutyLt=2
    { 785, 512, 961},  //duty=12, dutyLt=2
    { 789, 512, 957},  //duty=13, dutyLt=2
    { 794, 512, 953},  //duty=14, dutyLt=2
    { 798, 512, 950},  //duty=15, dutyLt=2
    { 798, 512, 940},  //duty=16, dutyLt=2
    { 803, 512, 933},  //duty=17, dutyLt=2
    { 807, 512, 927},  //duty=18, dutyLt=2
    { 810, 512, 920},  //duty=19, dutyLt=2
    { 813, 512, 915},  //duty=20, dutyLt=2
    { 816, 512, 907},  //duty=21, dutyLt=2
    { 819, 512, 900},  //duty=22, dutyLt=2
    { 821, 512, 892},  //duty=23, dutyLt=2
    { 512, 512, 512},  //duty=24, dutyLt=2
    { 512, 512, 512},  //duty=25, dutyLt=2
    { 480, 512,1359},  //duty=-1, dutyLt=3
    { 552, 512,1186},  //duty=0, dutyLt=3
    { 601, 512,1112},  //duty=1, dutyLt=3
    { 636, 512,1071},  //duty=2, dutyLt=3
    { 663, 512,1058},  //duty=3, dutyLt=3
    { 684, 512,1038},  //duty=4, dutyLt=3
    { 700, 512,1024},  //duty=5, dutyLt=3
    { 714, 512,1012},  //duty=6, dutyLt=3
    { 725, 512,1002},  //duty=7, dutyLt=3
    { 735, 512, 995},  //duty=8, dutyLt=3
    { 744, 512, 988},  //duty=9, dutyLt=3
    { 751, 512, 982},  //duty=10, dutyLt=3
    { 758, 512, 977},  //duty=11, dutyLt=3
    { 764, 512, 972},  //duty=12, dutyLt=3
    { 769, 512, 969},  //duty=13, dutyLt=3
    { 774, 512, 964},  //duty=14, dutyLt=3
    { 778, 512, 960},  //duty=15, dutyLt=3
    { 783, 512, 948},  //duty=16, dutyLt=3
    { 788, 512, 942},  //duty=17, dutyLt=3
    { 793, 512, 935},  //duty=18, dutyLt=3
    { 796, 512, 928},  //duty=19, dutyLt=3
    { 800, 512, 920},  //duty=20, dutyLt=3
    { 803, 512, 914},  //duty=21, dutyLt=3
    { 805, 512, 906},  //duty=22, dutyLt=3
    { 808, 512, 899},  //duty=23, dutyLt=3
    { 512, 512, 512},  //duty=24, dutyLt=3
    { 512, 512, 512},  //duty=25, dutyLt=3
    { 481, 512,1358},  //duty=-1, dutyLt=4
    { 541, 512,1208},  //duty=0, dutyLt=4
    { 585, 512,1136},  //duty=1, dutyLt=4
    { 618, 512,1108},  //duty=2, dutyLt=4
    { 643, 512,1078},  //duty=3, dutyLt=4
    { 663, 512,1055},  //duty=4, dutyLt=4
    { 680, 512,1040},  //duty=5, dutyLt=4
    { 694, 512,1028},  //duty=6, dutyLt=4
    { 705, 512,1017},  //duty=7, dutyLt=4
    { 716, 512,1008},  //duty=8, dutyLt=4
    { 725, 512,1001},  //duty=9, dutyLt=4
    { 733, 512, 995},  //duty=10, dutyLt=4
    { 740, 512, 989},  //duty=11, dutyLt=4
    { 746, 512, 984},  //duty=12, dutyLt=4
    { 752, 512, 979},  //duty=13, dutyLt=4
    { 757, 512, 974},  //duty=14, dutyLt=4
    { 762, 512, 970},  //duty=15, dutyLt=4
    { 770, 512, 955},  //duty=16, dutyLt=4
    { 776, 512, 948},  //duty=17, dutyLt=4
    { 780, 512, 942},  //duty=18, dutyLt=4
    { 784, 512, 934},  //duty=19, dutyLt=4
    { 788, 512, 927},  //duty=20, dutyLt=4
    { 791, 512, 921},  //duty=21, dutyLt=4
    { 794, 512, 913},  //duty=22, dutyLt=4
    { 512, 512, 512},  //duty=23, dutyLt=4
    { 512, 512, 512},  //duty=24, dutyLt=4
    { 512, 512, 512},  //duty=25, dutyLt=4
    { 481, 512,1358},  //duty=-1, dutyLt=5
    { 534, 512,1224},  //duty=0, dutyLt=5
    { 574, 512,1154},  //duty=1, dutyLt=5
    { 604, 512,1126},  //duty=2, dutyLt=5
    { 628, 512,1093},  //duty=3, dutyLt=5
    { 647, 512,1071},  //duty=4, dutyLt=5
    { 664, 512,1054},  //duty=5, dutyLt=5
    { 677, 512,1041},  //duty=6, dutyLt=5
    { 689, 512,1029},  //duty=7, dutyLt=5
    { 700, 512,1020},  //duty=8, dutyLt=5
    { 709, 512,1012},  //duty=9, dutyLt=5
    { 717, 512,1005},  //duty=10, dutyLt=5
    { 724, 512, 999},  //duty=11, dutyLt=5
    { 731, 512, 994},  //duty=12, dutyLt=5
    { 737, 512, 988},  //duty=13, dutyLt=5
    { 743, 512, 984},  //duty=14, dutyLt=5
    { 748, 512, 979},  //duty=15, dutyLt=5
    { 748, 512, 970},  //duty=16, dutyLt=5
    { 754, 512, 962},  //duty=17, dutyLt=5
    { 759, 512, 955},  //duty=18, dutyLt=5
    { 763, 512, 947},  //duty=19, dutyLt=5
    { 767, 512, 939},  //duty=20, dutyLt=5
    { 770, 512, 931},  //duty=21, dutyLt=5
    { 773, 512, 924},  //duty=22, dutyLt=5
    { 512, 512, 512},  //duty=23, dutyLt=5
    { 512, 512, 512},  //duty=24, dutyLt=5
    { 512, 512, 512},  //duty=25, dutyLt=5
    { 483, 512,1359},  //duty=-1, dutyLt=6
    { 529, 512,1237},  //duty=0, dutyLt=6
    { 565, 512,1185},  //duty=1, dutyLt=6
    { 593, 512,1139},  //duty=2, dutyLt=6
    { 616, 512,1107},  //duty=3, dutyLt=6
    { 635, 512,1085},  //duty=4, dutyLt=6
    { 650, 512,1066},  //duty=5, dutyLt=6
    { 664, 512,1053},  //duty=6, dutyLt=6
    { 676, 512,1042},  //duty=7, dutyLt=6
    { 687, 512,1032},  //duty=8, dutyLt=6
    { 696, 512,1023},  //duty=9, dutyLt=6
    { 704, 512,1015},  //duty=10, dutyLt=6
    { 712, 512,1009},  //duty=11, dutyLt=6
    { 718, 512,1003},  //duty=12, dutyLt=6
    { 724, 512, 998},  //duty=13, dutyLt=6
    { 730, 512, 993},  //duty=14, dutyLt=6
    { 735, 512, 988},  //duty=15, dutyLt=6
    { 739, 512, 976},  //duty=16, dutyLt=6
    { 745, 512, 967},  //duty=17, dutyLt=6
    { 750, 512, 960},  //duty=18, dutyLt=6
    { 755, 512, 952},  //duty=19, dutyLt=6
    { 758, 512, 945},  //duty=20, dutyLt=6
    { 762, 512, 937},  //duty=21, dutyLt=6
    { 512, 512, 512},  //duty=22, dutyLt=6
    { 512, 512, 512},  //duty=23, dutyLt=6
    { 512, 512, 512},  //duty=24, dutyLt=6
    { 512, 512, 512},  //duty=25, dutyLt=6
    { 483, 512,1359},  //duty=-1, dutyLt=7
    { 525, 512,1247},  //duty=0, dutyLt=7
    { 558, 512,1196},  //duty=1, dutyLt=7
    { 584, 512,1152},  //duty=2, dutyLt=7
    { 606, 512,1120},  //duty=3, dutyLt=7
    { 624, 512,1098},  //duty=4, dutyLt=7
    { 640, 512,1079},  //duty=5, dutyLt=7
    { 653, 512,1064},  //duty=6, dutyLt=7
    { 665, 512,1052},  //duty=7, dutyLt=7
    { 675, 512,1042},  //duty=8, dutyLt=7
    { 685, 512,1032},  //duty=9, dutyLt=7
    { 693, 512,1025},  //duty=10, dutyLt=7
    { 700, 512,1018},  //duty=11, dutyLt=7
    { 707, 512,1011},  //duty=12, dutyLt=7
    { 713, 512,1006},  //duty=13, dutyLt=7
    { 719, 512,1001},  //duty=14, dutyLt=7
    { 725, 512, 995},  //duty=15, dutyLt=7
    { 731, 512, 981},  //duty=16, dutyLt=7
    { 737, 512, 973},  //duty=17, dutyLt=7
    { 742, 512, 965},  //duty=18, dutyLt=7
    { 746, 512, 958},  //duty=19, dutyLt=7
    { 750, 512, 949},  //duty=20, dutyLt=7
    { 754, 512, 942},  //duty=21, dutyLt=7
    { 512, 512, 512},  //duty=22, dutyLt=7
    { 512, 512, 512},  //duty=23, dutyLt=7
    { 512, 512, 512},  //duty=24, dutyLt=7
    { 512, 512, 512},  //duty=25, dutyLt=7
    { 484, 512,1358},  //duty=-1, dutyLt=8
    { 522, 512,1269},  //duty=0, dutyLt=8
    { 552, 512,1206},  //duty=1, dutyLt=8
    { 577, 512,1162},  //duty=2, dutyLt=8
    { 598, 512,1131},  //duty=3, dutyLt=8
    { 615, 512,1107},  //duty=4, dutyLt=8
    { 630, 512,1089},  //duty=5, dutyLt=8
    { 644, 512,1074},  //duty=6, dutyLt=8
    { 655, 512,1062},  //duty=7, dutyLt=8
    { 666, 512,1051},  //duty=8, dutyLt=8
    { 675, 512,1042},  //duty=9, dutyLt=8
    { 683, 512,1033},  //duty=10, dutyLt=8
    { 691, 512,1026},  //duty=11, dutyLt=8
    { 697, 512,1020},  //duty=12, dutyLt=8
    { 704, 512,1014},  //duty=13, dutyLt=8
    { 709, 512,1008},  //duty=14, dutyLt=8
    { 715, 512,1002},  //duty=15, dutyLt=8
    { 723, 512, 987},  //duty=16, dutyLt=8
    { 729, 512, 978},  //duty=17, dutyLt=8
    { 734, 512, 970},  //duty=18, dutyLt=8
    { 739, 512, 962},  //duty=19, dutyLt=8
    { 743, 512, 954},  //duty=20, dutyLt=8
    { 512, 512, 512},  //duty=21, dutyLt=8
    { 512, 512, 512},  //duty=22, dutyLt=8
    { 512, 512, 512},  //duty=23, dutyLt=8
    { 512, 512, 512},  //duty=24, dutyLt=8
    { 512, 512, 512},  //duty=25, dutyLt=8
    { 485, 512,1358},  //duty=-1, dutyLt=9
    { 520, 512,1274},  //duty=0, dutyLt=9
    { 548, 512,1213},  //duty=1, dutyLt=9
    { 572, 512,1171},  //duty=2, dutyLt=9
    { 591, 512,1141},  //duty=3, dutyLt=9
    { 608, 512,1116},  //duty=4, dutyLt=9
    { 623, 512,1098},  //duty=5, dutyLt=9
    { 636, 512,1082},  //duty=6, dutyLt=9
    { 647, 512,1070},  //duty=7, dutyLt=9
    { 657, 512,1058},  //duty=8, dutyLt=9
    { 666, 512,1050},  //duty=9, dutyLt=9
    { 675, 512,1041},  //duty=10, dutyLt=9
    { 682, 512,1034},  //duty=11, dutyLt=9
    { 689, 512,1027},  //duty=12, dutyLt=9
    { 695, 512,1020},  //duty=13, dutyLt=9
    { 701, 512,1014},  //duty=14, dutyLt=9
    { 706, 512,1009},  //duty=15, dutyLt=9
    { 716, 512, 991},  //duty=16, dutyLt=9
    { 722, 512, 983},  //duty=17, dutyLt=9
    { 728, 512, 974},  //duty=18, dutyLt=9
    { 732, 512, 966},  //duty=19, dutyLt=9
    { 512, 512, 512},  //duty=20, dutyLt=9
    { 512, 512, 512},  //duty=21, dutyLt=9
    { 512, 512, 512},  //duty=22, dutyLt=9
    { 512, 512, 512},  //duty=23, dutyLt=9
    { 512, 512, 512},  //duty=24, dutyLt=9
    { 512, 512, 512},  //duty=25, dutyLt=9
    { 485, 512,1375},  //duty=-1, dutyLt=10
    { 518, 512,1282},  //duty=0, dutyLt=10
    { 545, 512,1221},  //duty=1, dutyLt=10
    { 567, 512,1180},  //duty=2, dutyLt=10
    { 586, 512,1149},  //duty=3, dutyLt=10
    { 602, 512,1124},  //duty=4, dutyLt=10
    { 616, 512,1106},  //duty=5, dutyLt=10
    { 629, 512,1091},  //duty=6, dutyLt=10
    { 640, 512,1077},  //duty=7, dutyLt=10
    { 650, 512,1067},  //duty=8, dutyLt=10
    { 659, 512,1057},  //duty=9, dutyLt=10
    { 667, 512,1048},  //duty=10, dutyLt=10
    { 675, 512,1041},  //duty=11, dutyLt=10
    { 681, 512,1034},  //duty=12, dutyLt=10
    { 688, 512,1027},  //duty=13, dutyLt=10
    { 693, 512,1021},  //duty=14, dutyLt=10
    { 699, 512,1015},  //duty=15, dutyLt=10
    { 710, 512, 997},  //duty=16, dutyLt=10
    { 716, 512, 988},  //duty=17, dutyLt=10
    { 721, 512, 979},  //duty=18, dutyLt=10
    { 512, 512, 512},  //duty=19, dutyLt=10
    { 512, 512, 512},  //duty=20, dutyLt=10
    { 512, 512, 512},  //duty=21, dutyLt=10
    { 512, 512, 512},  //duty=22, dutyLt=10
    { 512, 512, 512},  //duty=23, dutyLt=10
    { 512, 512, 512},  //duty=24, dutyLt=10
    { 512, 512, 512},  //duty=25, dutyLt=10
    { 486, 512,1371},  //duty=-1, dutyLt=11
    { 516, 512,1284},  //duty=0, dutyLt=11
    { 542, 512,1227},  //duty=1, dutyLt=11
    { 563, 512,1185},  //duty=2, dutyLt=11
    { 581, 512,1155},  //duty=3, dutyLt=11
    { 597, 512,1133},  //duty=4, dutyLt=11
    { 611, 512,1113},  //duty=5, dutyLt=11
    { 623, 512,1098},  //duty=6, dutyLt=11
    { 634, 512,1085},  //duty=7, dutyLt=11
    { 644, 512,1073},  //duty=8, dutyLt=11
    { 653, 512,1064},  //duty=9, dutyLt=11
    { 661, 512,1055},  //duty=10, dutyLt=11
    { 668, 512,1047},  //duty=11, dutyLt=11
    { 674, 512,1040},  //duty=12, dutyLt=11
    { 681, 512,1033},  //duty=13, dutyLt=11
    { 686, 512,1027},  //duty=14, dutyLt=11
    { 692, 512,1021},  //duty=15, dutyLt=11
    { 705, 512,1000},  //duty=16, dutyLt=11
    { 711, 512, 992},  //duty=17, dutyLt=11
    { 512, 512, 512},  //duty=18, dutyLt=11
    { 512, 512, 512},  //duty=19, dutyLt=11
    { 512, 512, 512},  //duty=20, dutyLt=11
    { 512, 512, 512},  //duty=21, dutyLt=11
    { 512, 512, 512},  //duty=22, dutyLt=11
    { 512, 512, 512},  //duty=23, dutyLt=11
    { 512, 512, 512},  //duty=24, dutyLt=11
    { 512, 512, 512},  //duty=25, dutyLt=11
    { 487, 512,1369},  //duty=-1, dutyLt=12
    { 515, 512,1286},  //duty=0, dutyLt=12
    { 539, 512,1230},  //duty=1, dutyLt=12
    { 559, 512,1191},  //duty=2, dutyLt=12
    { 577, 512,1162},  //duty=3, dutyLt=12
    { 592, 512,1139},  //duty=4, dutyLt=12
    { 606, 512,1120},  //duty=5, dutyLt=12
    { 617, 512,1104},  //duty=6, dutyLt=12
    { 628, 512,1091},  //duty=7, dutyLt=12
    { 638, 512,1080},  //duty=8, dutyLt=12
    { 647, 512,1069},  //duty=9, dutyLt=12
    { 655, 512,1060},  //duty=10, dutyLt=12
    { 662, 512,1053},  //duty=11, dutyLt=12
    { 669, 512,1045},  //duty=12, dutyLt=12
    { 675, 512,1038},  //duty=13, dutyLt=12
    { 680, 512,1032},  //duty=14, dutyLt=12
    { 686, 512,1026},  //duty=15, dutyLt=12
    { 700, 512,1004},  //duty=16, dutyLt=12
    { 512, 512, 512},  //duty=17, dutyLt=12
    { 512, 512, 512},  //duty=18, dutyLt=12
    { 512, 512, 512},  //duty=19, dutyLt=12
    { 512, 512, 512},  //duty=20, dutyLt=12
    { 512, 512, 512},  //duty=21, dutyLt=12
    { 512, 512, 512},  //duty=22, dutyLt=12
    { 512, 512, 512},  //duty=23, dutyLt=12
    { 512, 512, 512},  //duty=24, dutyLt=12
    { 512, 512, 512},  //duty=25, dutyLt=12
    { 487, 512,1368},  //duty=-1, dutyLt=13
    { 514, 512,1289},  //duty=0, dutyLt=13
    { 537, 512,1236},  //duty=1, dutyLt=13
    { 557, 512,1197},  //duty=2, dutyLt=13
    { 573, 512,1167},  //duty=3, dutyLt=13
    { 588, 512,1145},  //duty=4, dutyLt=13
    { 601, 512,1126},  //duty=5, dutyLt=13
    { 613, 512,1111},  //duty=6, dutyLt=13
    { 623, 512,1097},  //duty=7, dutyLt=13
    { 633, 512,1085},  //duty=8, dutyLt=13
    { 642, 512,1075},  //duty=9, dutyLt=13
    { 649, 512,1067},  //duty=10, dutyLt=13
    { 656, 512,1058},  //duty=11, dutyLt=13
    { 663, 512,1050},  //duty=12, dutyLt=13
    { 669, 512,1044},  //duty=13, dutyLt=13
    { 675, 512,1037},  //duty=14, dutyLt=13
    { 680, 512,1031},  //duty=15, dutyLt=13
    { 512, 512, 512},  //duty=16, dutyLt=13
    { 512, 512, 512},  //duty=17, dutyLt=13
    { 512, 512, 512},  //duty=18, dutyLt=13
    { 512, 512, 512},  //duty=19, dutyLt=13
    { 512, 512, 512},  //duty=20, dutyLt=13
    { 512, 512, 512},  //duty=21, dutyLt=13
    { 512, 512, 512},  //duty=22, dutyLt=13
    { 512, 512, 512},  //duty=23, dutyLt=13
    { 512, 512, 512},  //duty=24, dutyLt=13
    { 512, 512, 512},  //duty=25, dutyLt=13
    { 488, 512,1365},  //duty=-1, dutyLt=14
    { 513, 512,1290},  //duty=0, dutyLt=14
    { 535, 512,1239},  //duty=1, dutyLt=14
    { 554, 512,1201},  //duty=2, dutyLt=14
    { 570, 512,1173},  //duty=3, dutyLt=14
    { 585, 512,1150},  //duty=4, dutyLt=14
    { 598, 512,1131},  //duty=5, dutyLt=14
    { 609, 512,1115},  //duty=6, dutyLt=14
    { 619, 512,1102},  //duty=7, dutyLt=14
    { 628, 512,1091},  //duty=8, dutyLt=14
    { 637, 512,1080},  //duty=9, dutyLt=14
    { 645, 512,1071},  //duty=10, dutyLt=14
    { 652, 512,1063},  //duty=11, dutyLt=14
    { 658, 512,1055},  //duty=12, dutyLt=14
    { 664, 512,1048},  //duty=13, dutyLt=14
    { 670, 512,1042},  //duty=14, dutyLt=14
    { 512, 512, 512},  //duty=15, dutyLt=14
    { 512, 512, 512},  //duty=16, dutyLt=14
    { 512, 512, 512},  //duty=17, dutyLt=14
    { 512, 512, 512},  //duty=18, dutyLt=14
    { 512, 512, 512},  //duty=19, dutyLt=14
    { 512, 512, 512},  //duty=20, dutyLt=14
    { 512, 512, 512},  //duty=21, dutyLt=14
    { 512, 512, 512},  //duty=22, dutyLt=14
    { 512, 512, 512},  //duty=23, dutyLt=14
    { 512, 512, 512},  //duty=24, dutyLt=14
    { 512, 512, 512},  //duty=25, dutyLt=14
    { 488, 512,1363},  //duty=-1, dutyLt=15
    { 513, 512,1292},  //duty=0, dutyLt=15
    { 534, 512,1241},  //duty=1, dutyLt=15
    { 552, 512,1206},  //duty=2, dutyLt=15
    { 568, 512,1177},  //duty=3, dutyLt=15
    { 582, 512,1154},  //duty=4, dutyLt=15
    { 594, 512,1136},  //duty=5, dutyLt=15
    { 605, 512,1121},  //duty=6, dutyLt=15
    { 615, 512,1107},  //duty=7, dutyLt=15
    { 624, 512,1095},  //duty=8, dutyLt=15
    { 633, 512,1085},  //duty=9, dutyLt=15
    { 640, 512,1076},  //duty=10, dutyLt=15
    { 647, 512,1068},  //duty=11, dutyLt=15
    { 654, 512,1060},  //duty=12, dutyLt=15
    { 659, 512,1053},  //duty=13, dutyLt=15
    { 512, 512, 512},  //duty=14, dutyLt=15
    { 512, 512, 512},  //duty=15, dutyLt=15
    { 512, 512, 512},  //duty=16, dutyLt=15
    { 512, 512, 512},  //duty=17, dutyLt=15
    { 512, 512, 512},  //duty=18, dutyLt=15
    { 512, 512, 512},  //duty=19, dutyLt=15
    { 512, 512, 512},  //duty=20, dutyLt=15
    { 512, 512, 512},  //duty=21, dutyLt=15
    { 512, 512, 512},  //duty=22, dutyLt=15
    { 512, 512, 512},  //duty=23, dutyLt=15
    { 512, 512, 512},  //duty=24, dutyLt=15
    { 512, 512, 512},  //duty=25, dutyLt=15
    { 492, 512,1347},  //duty=-1, dutyLt=16
    { 512, 512,1291},  //duty=0, dutyLt=16
    { 529, 512,1249},  //duty=1, dutyLt=16
    { 558, 512,1192},  //duty=2, dutyLt=16
    { 571, 512,1171},  //duty=3, dutyLt=16
    { 581, 512,1153},  //duty=4, dutyLt=16
    { 600, 512,1125},  //duty=5, dutyLt=16
    { 609, 512,1114},  //duty=6, dutyLt=16
    { 616, 512,1104},  //duty=7, dutyLt=16
    { 623, 512,1095},  //duty=8, dutyLt=16
    { 630, 512,1085},  //duty=9, dutyLt=16
    { 635, 512,1078},  //duty=10, dutyLt=16
    { 641, 512,1071},  //duty=11, dutyLt=16
    { 646, 512,1064},  //duty=12, dutyLt=16
    { 512, 512, 512},  //duty=13, dutyLt=16
    { 512, 512, 512},  //duty=14, dutyLt=16
    { 512, 512, 512},  //duty=15, dutyLt=16
    { 512, 512, 512},  //duty=16, dutyLt=16
    { 512, 512, 512},  //duty=17, dutyLt=16
    { 512, 512, 512},  //duty=18, dutyLt=16
    { 512, 512, 512},  //duty=19, dutyLt=16
    { 512, 512, 512},  //duty=20, dutyLt=16
    { 512, 512, 512},  //duty=21, dutyLt=16
    { 512, 512, 512},  //duty=22, dutyLt=16
    { 512, 512, 512},  //duty=23, dutyLt=16
    { 512, 512, 512},  //duty=24, dutyLt=16
    { 512, 512, 512},  //duty=25, dutyLt=16
    { 493, 512,1342},  //duty=-1, dutyLt=17
    { 512, 512,1289},  //duty=0, dutyLt=17
    { 529, 512,1248},  //duty=1, dutyLt=17
    { 556, 512,1193},  //duty=2, dutyLt=17
    { 568, 512,1174},  //duty=3, dutyLt=17
    { 579, 512,1156},  //duty=4, dutyLt=17
    { 597, 512,1129},  //duty=5, dutyLt=17
    { 605, 512,1118},  //duty=6, dutyLt=17
    { 612, 512,1108},  //duty=7, dutyLt=17
    { 619, 512,1098},  //duty=8, dutyLt=17
    { 625, 512,1090},  //duty=9, dutyLt=17
    { 631, 512,1082},  //duty=10, dutyLt=17
    { 637, 512,1075},  //duty=11, dutyLt=17
    { 512, 512, 512},  //duty=12, dutyLt=17
    { 512, 512, 512},  //duty=13, dutyLt=17
    { 512, 512, 512},  //duty=14, dutyLt=17
    { 512, 512, 512},  //duty=15, dutyLt=17
    { 512, 512, 512},  //duty=16, dutyLt=17
    { 512, 512, 512},  //duty=17, dutyLt=17
    { 512, 512, 512},  //duty=18, dutyLt=17
    { 512, 512, 512},  //duty=19, dutyLt=17
    { 512, 512, 512},  //duty=20, dutyLt=17
    { 512, 512, 512},  //duty=21, dutyLt=17
    { 512, 512, 512},  //duty=22, dutyLt=17
    { 512, 512, 512},  //duty=23, dutyLt=17
    { 512, 512, 512},  //duty=24, dutyLt=17
    { 512, 512, 512},  //duty=25, dutyLt=17
    { 494, 512,1336},  //duty=-1, dutyLt=18
    { 512, 512,1285},  //duty=0, dutyLt=18
    { 529, 512,1247},  //duty=1, dutyLt=18
    { 555, 512,1195},  //duty=2, dutyLt=18
    { 566, 512,1176},  //duty=3, dutyLt=18
    { 577, 512,1158},  //duty=4, dutyLt=18
    { 594, 512,1131},  //duty=5, dutyLt=18
    { 602, 512,1121},  //duty=6, dutyLt=18
    { 609, 512,1110},  //duty=7, dutyLt=18
    { 616, 512,1101},  //duty=8, dutyLt=18
    { 622, 512,1093},  //duty=9, dutyLt=18
    { 628, 512,1085},  //duty=10, dutyLt=18
    { 512, 512, 512},  //duty=11, dutyLt=18
    { 512, 512, 512},  //duty=12, dutyLt=18
    { 512, 512, 512},  //duty=13, dutyLt=18
    { 512, 512, 512},  //duty=14, dutyLt=18
    { 512, 512, 512},  //duty=15, dutyLt=18
    { 512, 512, 512},  //duty=16, dutyLt=18
    { 512, 512, 512},  //duty=17, dutyLt=18
    { 512, 512, 512},  //duty=18, dutyLt=18
    { 512, 512, 512},  //duty=19, dutyLt=18
    { 512, 512, 512},  //duty=20, dutyLt=18
    { 512, 512, 512},  //duty=21, dutyLt=18
    { 512, 512, 512},  //duty=22, dutyLt=18
    { 512, 512, 512},  //duty=23, dutyLt=18
    { 512, 512, 512},  //duty=24, dutyLt=18
    { 512, 512, 512},  //duty=25, dutyLt=18
    { 495, 512,1329},  //duty=-1, dutyLt=19
    { 512, 512,1282},  //duty=0, dutyLt=19
    { 528, 512,1246},  //duty=1, dutyLt=19
    { 554, 512,1195},  //duty=2, dutyLt=19
    { 565, 512,1176},  //duty=3, dutyLt=19
    { 575, 512,1160},  //duty=4, dutyLt=19
    { 592, 512,1133},  //duty=5, dutyLt=19
    { 600, 512,1122},  //duty=6, dutyLt=19
    { 606, 512,1112},  //duty=7, dutyLt=19
    { 613, 512,1104},  //duty=8, dutyLt=19
    { 619, 512,1095},  //duty=9, dutyLt=19
    { 512, 512, 512},  //duty=10, dutyLt=19
    { 512, 512, 512},  //duty=11, dutyLt=19
    { 512, 512, 512},  //duty=12, dutyLt=19
    { 512, 512, 512},  //duty=13, dutyLt=19
    { 512, 512, 512},  //duty=14, dutyLt=19
    { 512, 512, 512},  //duty=15, dutyLt=19
    { 512, 512, 512},  //duty=16, dutyLt=19
    { 512, 512, 512},  //duty=17, dutyLt=19
    { 512, 512, 512},  //duty=18, dutyLt=19
    { 512, 512, 512},  //duty=19, dutyLt=19
    { 512, 512, 512},  //duty=20, dutyLt=19
    { 512, 512, 512},  //duty=21, dutyLt=19
    { 512, 512, 512},  //duty=22, dutyLt=19
    { 512, 512, 512},  //duty=23, dutyLt=19
    { 512, 512, 512},  //duty=24, dutyLt=19
    { 512, 512, 512},  //duty=25, dutyLt=19
    { 497, 512,1322},  //duty=-1, dutyLt=20
    { 513, 512,1278},  //duty=0, dutyLt=20
    { 529, 512,1242},  //duty=1, dutyLt=20
    { 553, 512,1194},  //duty=2, dutyLt=20
    { 564, 512,1176},  //duty=3, dutyLt=20
    { 573, 512,1160},  //duty=4, dutyLt=20
    { 590, 512,1134},  //duty=5, dutyLt=20
    { 598, 512,1123},  //duty=6, dutyLt=20
    { 605, 512,1114},  //duty=7, dutyLt=20
    { 611, 512,1104},  //duty=8, dutyLt=20
    { 512, 512, 512},  //duty=9, dutyLt=20
    { 512, 512, 512},  //duty=10, dutyLt=20
    { 512, 512, 512},  //duty=11, dutyLt=20
    { 512, 512, 512},  //duty=12, dutyLt=20
    { 512, 512, 512},  //duty=13, dutyLt=20
    { 512, 512, 512},  //duty=14, dutyLt=20
    { 512, 512, 512},  //duty=15, dutyLt=20
    { 512, 512, 512},  //duty=16, dutyLt=20
    { 512, 512, 512},  //duty=17, dutyLt=20
    { 512, 512, 512},  //duty=18, dutyLt=20
    { 512, 512, 512},  //duty=19, dutyLt=20
    { 512, 512, 512},  //duty=20, dutyLt=20
    { 512, 512, 512},  //duty=21, dutyLt=20
    { 512, 512, 512},  //duty=22, dutyLt=20
    { 512, 512, 512},  //duty=23, dutyLt=20
    { 512, 512, 512},  //duty=24, dutyLt=20
    { 512, 512, 512},  //duty=25, dutyLt=20
    { 498, 512,1314},  //duty=-1, dutyLt=21
    { 514, 512,1273},  //duty=0, dutyLt=21
    { 529, 512,1239},  //duty=1, dutyLt=21
    { 553, 512,1191},  //duty=2, dutyLt=21
    { 563, 512,1175},  //duty=3, dutyLt=21
    { 572, 512,1159},  //duty=4, dutyLt=21
    { 589, 512,1134},  //duty=5, dutyLt=21
    { 596, 512,1123},  //duty=6, dutyLt=21
    { 603, 512,1114},  //duty=7, dutyLt=21
    { 512, 512, 512},  //duty=8, dutyLt=21
    { 512, 512, 512},  //duty=9, dutyLt=21
    { 512, 512, 512},  //duty=10, dutyLt=21
    { 512, 512, 512},  //duty=11, dutyLt=21
    { 512, 512, 512},  //duty=12, dutyLt=21
    { 512, 512, 512},  //duty=13, dutyLt=21
    { 512, 512, 512},  //duty=14, dutyLt=21
    { 512, 512, 512},  //duty=15, dutyLt=21
    { 512, 512, 512},  //duty=16, dutyLt=21
    { 512, 512, 512},  //duty=17, dutyLt=21
    { 512, 512, 512},  //duty=18, dutyLt=21
    { 512, 512, 512},  //duty=19, dutyLt=21
    { 512, 512, 512},  //duty=20, dutyLt=21
    { 512, 512, 512},  //duty=21, dutyLt=21
    { 512, 512, 512},  //duty=22, dutyLt=21
    { 512, 512, 512},  //duty=23, dutyLt=21
    { 512, 512, 512},  //duty=24, dutyLt=21
    { 512, 512, 512},  //duty=25, dutyLt=21
    { 499, 512,1308},  //duty=-1, dutyLt=22
    { 515, 512,1266},  //duty=0, dutyLt=22
    { 529, 512,1235},  //duty=1, dutyLt=22
    { 553, 512,1190},  //duty=2, dutyLt=22
    { 563, 512,1172},  //duty=3, dutyLt=22
    { 572, 512,1158},  //duty=4, dutyLt=22
    { 588, 512,1133},  //duty=5, dutyLt=22
    { 512, 512, 512},  //duty=6, dutyLt=22
    { 512, 512, 512},  //duty=7, dutyLt=22
    { 512, 512, 512},  //duty=8, dutyLt=22
    { 512, 512, 512},  //duty=9, dutyLt=22
    { 512, 512, 512},  //duty=10, dutyLt=22
    { 512, 512, 512},  //duty=11, dutyLt=22
    { 512, 512, 512},  //duty=12, dutyLt=22
    { 512, 512, 512},  //duty=13, dutyLt=22
    { 512, 512, 512},  //duty=14, dutyLt=22
    { 512, 512, 512},  //duty=15, dutyLt=22
    { 512, 512, 512},  //duty=16, dutyLt=22
    { 512, 512, 512},  //duty=17, dutyLt=22
    { 512, 512, 512},  //duty=18, dutyLt=22
    { 512, 512, 512},  //duty=19, dutyLt=22
    { 512, 512, 512},  //duty=20, dutyLt=22
    { 512, 512, 512},  //duty=21, dutyLt=22
    { 512, 512, 512},  //duty=22, dutyLt=22
    { 512, 512, 512},  //duty=23, dutyLt=22
    { 512, 512, 512},  //duty=24, dutyLt=22
    { 512, 512, 512},  //duty=25, dutyLt=22
    { 501, 512,1300},  //duty=-1, dutyLt=23
    { 516, 512,1260},  //duty=0, dutyLt=23
    { 530, 512,1230},  //duty=1, dutyLt=23
    { 553, 512,1187},  //duty=2, dutyLt=23
    { 563, 512,1169},  //duty=3, dutyLt=23
    { 512, 512, 512},  //duty=4, dutyLt=23
    { 512, 512, 512},  //duty=5, dutyLt=23
    { 512, 512, 512},  //duty=6, dutyLt=23
    { 512, 512, 512},  //duty=7, dutyLt=23
    { 512, 512, 512},  //duty=8, dutyLt=23
    { 512, 512, 512},  //duty=9, dutyLt=23
    { 512, 512, 512},  //duty=10, dutyLt=23
    { 512, 512, 512},  //duty=11, dutyLt=23
    { 512, 512, 512},  //duty=12, dutyLt=23
    { 512, 512, 512},  //duty=13, dutyLt=23
    { 512, 512, 512},  //duty=14, dutyLt=23
    { 512, 512, 512},  //duty=15, dutyLt=23
    { 512, 512, 512},  //duty=16, dutyLt=23
    { 512, 512, 512},  //duty=17, dutyLt=23
    { 512, 512, 512},  //duty=18, dutyLt=23
    { 512, 512, 512},  //duty=19, dutyLt=23
    { 512, 512, 512},  //duty=20, dutyLt=23
    { 512, 512, 512},  //duty=21, dutyLt=23
    { 512, 512, 512},  //duty=22, dutyLt=23
    { 512, 512, 512},  //duty=23, dutyLt=23
    { 512, 512, 512},  //duty=24, dutyLt=23
    { 512, 512, 512},  //duty=25, dutyLt=23
    { 502, 512,1293},  //duty=-1, dutyLt=24
    { 517, 512,1254},  //duty=0, dutyLt=24
    { 531, 512,1224},  //duty=1, dutyLt=24
    { 512, 512, 512},  //duty=2, dutyLt=24
    { 512, 512, 512},  //duty=3, dutyLt=24
    { 512, 512, 512},  //duty=4, dutyLt=24
    { 512, 512, 512},  //duty=5, dutyLt=24
    { 512, 512, 512},  //duty=6, dutyLt=24
    { 512, 512, 512},  //duty=7, dutyLt=24
    { 512, 512, 512},  //duty=8, dutyLt=24
    { 512, 512, 512},  //duty=9, dutyLt=24
    { 512, 512, 512},  //duty=10, dutyLt=24
    { 512, 512, 512},  //duty=11, dutyLt=24
    { 512, 512, 512},  //duty=12, dutyLt=24
    { 512, 512, 512},  //duty=13, dutyLt=24
    { 512, 512, 512},  //duty=14, dutyLt=24
    { 512, 512, 512},  //duty=15, dutyLt=24
    { 512, 512, 512},  //duty=16, dutyLt=24
    { 512, 512, 512},  //duty=17, dutyLt=24
    { 512, 512, 512},  //duty=18, dutyLt=24
    { 512, 512, 512},  //duty=19, dutyLt=24
    { 512, 512, 512},  //duty=20, dutyLt=24
    { 512, 512, 512},  //duty=21, dutyLt=24
    { 512, 512, 512},  //duty=22, dutyLt=24
    { 512, 512, 512},  //duty=23, dutyLt=24
    { 512, 512, 512},  //duty=24, dutyLt=24
    { 512, 512, 512},  //duty=25, dutyLt=24
    { 503, 512,1284},  //duty=-1, dutyLt=25
    { 512, 512, 512},  //duty=0, dutyLt=25
    { 512, 512, 512},  //duty=1, dutyLt=25
    { 512, 512, 512},  //duty=2, dutyLt=25
    { 512, 512, 512},  //duty=3, dutyLt=25
    { 512, 512, 512},  //duty=4, dutyLt=25
    { 512, 512, 512},  //duty=5, dutyLt=25
    { 512, 512, 512},  //duty=6, dutyLt=25
    { 512, 512, 512},  //duty=7, dutyLt=25
    { 512, 512, 512},  //duty=8, dutyLt=25
    { 512, 512, 512},  //duty=9, dutyLt=25
    { 512, 512, 512},  //duty=10, dutyLt=25
    { 512, 512, 512},  //duty=11, dutyLt=25
    { 512, 512, 512},  //duty=12, dutyLt=25
    { 512, 512, 512},  //duty=13, dutyLt=25
    { 512, 512, 512},  //duty=14, dutyLt=25
    { 512, 512, 512},  //duty=15, dutyLt=25
    { 512, 512, 512},  //duty=16, dutyLt=25
    { 512, 512, 512},  //duty=17, dutyLt=25
    { 512, 512, 512},  //duty=18, dutyLt=25
    { 512, 512, 512},  //duty=19, dutyLt=25
    { 512, 512, 512},  //duty=20, dutyLt=25
    { 512, 512, 512},  //duty=21, dutyLt=25
    { 512, 512, 512},  //duty=22, dutyLt=25
    { 512, 512, 512},  //duty=23, dutyLt=25
    { 512, 512, 512},  //duty=24, dutyLt=25
    { 512, 512, 512},  //duty=25, dutyLt=25
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    { 512, 512, 512},  //duty=0, dutyLt=0
    },    
};

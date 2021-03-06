#ifndef __CAMERA_CUSTOM_LOMO_PARAM_H__
#define __CAMERA_CUSTOM_LOMO_PARAM_H__

#include <stddef.h>
#include "MediaTypes.h"
#include "ispif.h"
#include "CFG_Camera_File_Max_Size.h"
//#include "Nashville_gamma_BR.h"
//#include "Nashville_gamma_G.h"

using namespace NSIspTuning;

#define CUSTOM_LOMO_PARAM_BRIGHTNRSS_NUM       9 //Level range : -4(Weak)~0(Std)~4(Strong)
#define CUSTOM_LOMO_PARAM_CB_NUM               5 //Level range : -2(Weak)~0(Std)~2(Strong)
#define CUSTOM_LOMO_PARAM_CR_NUM               5 //Level range : -2(Weak)~0(Std)~2(Strong)
#define CUSTOM_LOMO_PARAM_CONTRAST_NUM         3 //Level range : -1(Weak)~0(Std)~1(Strong)
#define CUSTOM_LOMO_PARAM_SATURATION_NUM       3 //Level range : -1(Weak)~0(Std)~1(Strong)
#define CUSTOM_LOMO_PARAM_VIGNETTE_NUM         7 //Level range : -3(Weak)~0(Std)~3(Strong)


#define CUSTOM_LOMO_PARAM_BRIGHTNRSS_LEVEL       0 //Level range : -4(Weak)~0(Std)~4(Strong)
#define CUSTOM_LOMO_PARAM_CB_LEVEL               0 //Level range : -2(Weak)~0(Std)~2(Strong)
#define CUSTOM_LOMO_PARAM_CR_LEVEL               0 //Level range : -2(Weak)~0(Std)~2(Strong)
#define CUSTOM_LOMO_PARAM_CONTRAST_LEVEL         0 //Level range : -1(Weak)~0(Std)~1(Strong)
#define CUSTOM_LOMO_PARAM_SATURATION_LEVEL       0 //Level range : -1(Weak)~0(Std)~1(Strong)
#define CUSTOM_LOMO_PARAM_VIGNETTE_LEVEL         0 //Level range : -3(Weak)~0(Std)~3(Strong)




#define member_size(type, member) sizeof(((type *)0)->member)
#define struct_size(type, start, end) \
    ((offsetof(type, end) - offsetof(type, start) + member_size(type, end)))

#define SIZEOF  sizeof


/*******************************************************************************
*
********************************************************************************/
typedef enum
{
        LOMO_NORMAL =0 ,
        LOMO_NASHVILLE,
        LOMO_HEFE,
        LOMO_VALENCIA,
        LOMO_XPROII,
        LOMO_LOFI,
        LOMO_SIERRA,
        LOMO_KELVIN,
        LOMO_WALDEN,
        LOMO_F1977,
        LOMO_TYPE_NUM,
}CAMERA_LOMO_TYPE_ENUM;

#define CUSTOM_LOMO_GGM_TYPE_NUM         LOMO_TYPE_NUM //
#define CUSTOM_LOMO_GGM_CHANNEL       0 //
//#define CUSTOM_LOMO_GGM_CHANNEL_BR       0 //
//#define CUSTOM_LOMO_GGM_CHANNEL_G        1 //
#define CUSTOM_LOMO_GGM_CHANNEL_NUM      2 //
#define CUSTOM_LOMO_GGM_GAIN_NUM         192 //

//enum LomoFilter { Normal, Nashville, Hefe, Valencia, XproII, Lofi, Sierra, Kelvin, Walden, F1977, Mono, Sepia, Aqua, Negative, Blackboard, Whiteboard, Posterize};

/*******************************************************************************
*
********************************************************************************/
// LOMO G2C SHADE
typedef struct
{
    INT32 G2C_SHADE_EN ; // G2C_SHADE_EN
    INT32 G2C_SHADE_P2; // G2C_SHADE_P2
    INT32 G2C_SHADE_P1; //G2C_SHADE_P1
    INT32 G2C_SHADE_P0 ;//G2C_SHADE_P0
} LOMO_G2C_SHADE_T;

#define DATA_11BIT_2COMP (UINT32)(0x800)
#define DATA_11BIT (UINT32)(0x7FF)
#define DATA_11BIT_2COMP_DATA(A) (UINT32)(DATA_11BIT_2COMP+A)&(DATA_11BIT)

typedef enum
{
        LOMO_PARA_G2C_SHADE_con_1 =0 ,
        LOMO_PARA_G2C_SHADE_con_2 ,
        LOMO_PARA_G2C_SHADE_con_3,
        LOMO_PARA_G2C_SHADE_tar ,
        LOMO_PARA_G2C_SHADE_sp,
        LOMO_PARA_G2C_SHADE_NUM

}CAMERA_LOMO_PARA_G2C_SHADE_ENUM;



//int customer_brightness[LOMO_TYPE_NUM-1]= {0, 0, 0, 0, 0, 0, 0, 0, 0};   // level range: -4~4
int customer_color_cb[LOMO_TYPE_NUM-1]   = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // level range: -2~2
int customer_color_cr[LOMO_TYPE_NUM-1]    = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // level range: -2~2
//int customer_contrast[LOMO_TYPE_NUM-1]    = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // level range: -1~1
//int customer_saturation[LOMO_TYPE_NUM-1] = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // level range: -1~1
int customer_vignette[LOMO_TYPE_NUM-1]    = {3, 1, 1, 1, 1, 1, 1, 1, 1};   // level range: -3~3


//pram with level mapping
//double Lomo_B_param[CUSTOM_LOMO_PARAM_BRIGHTNRSS_NUM/*9*/] = {-20*4, -15*4, -10*4, -5*4, 0, 4*4, 8*4, 12*4, 16*4};   // add B of 256
//double Lomo_C_param[CUSTOM_LOMO_PARAM_CONTRAST_NUM/*3*/] = {59.0/64, 1, 69.0/64};                                                         // gain = C
//double Lomo_S_param[CUSTOM_LOMO_PARAM_SATURATION_NUM/*3*/] = {51.0/64, 1, 76.0/64};                                                         // gain = S
double Lomo_V_param[CUSTOM_LOMO_PARAM_VIGNETTE_NUM/*7*/] = {0, 0.4, 0.7, 1, 1.3, 1.7, 2};                                                 // gain = V
double Lomo_cb_param[CUSTOM_LOMO_PARAM_CB_NUM/*5*/] = {-8*2, -4*2, 0, 4*2, 8*2};                                                 // add Cb of 256
double Lomo_cr_param[CUSTOM_LOMO_PARAM_CR_NUM/*5*/] = {-8*2, -4*2, 0, 4*2, 8*2};                                                  // add Cr of 256



ISP_NVRAM_G2C_SHADE_T LomoFilterG2CDefault=
{
      {0x00000000,  //con_1
      0x00000000,  //con_2
      0x000001FF,//0x00000133, //con_3
      0x079f0a5a, //tar
      0x00000000}  //sp
};


#if 1
static LOMO_G2C_SHADE_T loadLomoFilterG2C[LOMO_TYPE_NUM];
LOMO_G2C_SHADE_T LomoFilterG2C[LOMO_TYPE_NUM]=
{
    {0,0,0,0},
    //Normal	G2C_SHADE_EN = 0;
    //G2C_SHADE_P2 = 0;
    //G2C_SHADE_P1 = 0;
    //G2C_SHADE_P0 = 0;
    {1,(-8),(-129),(258)},
    //Nashville	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = -8;
    //G2C_SHADE_P1 = -129;
    //G2C_SHADE_P0 = 258;
    {1,(-297),(125),(245)},
    //Hefe	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = -297;
    //G2C_SHADE_P1 = 125;
    //G2C_SHADE_P0 = 245;
    {1,(74),(-130),(259)},
    //Valencia	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = 74;
    //G2C_SHADE_P1 = -130;
    //G2C_SHADE_P0 = 259;
    {1,(-114),(-162),(262)},
    //XproII	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = -114;
    //G2C_SHADE_P1 = -162;
    //G2C_SHADE_P0 =  262;
    {1,(96),(-232),(264)},
    //Lofi	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = 96;
    //G2C_SHADE_P1 = -232;
    //G2C_SHADE_P0 =  264;
    {1,(-137),(-120),(262)},
    //Sierra	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = -137;
    //G2C_SHADE_P1 = -120;
    //G2C_SHADE_P0 =  257;
    {1,(131),(-284),(261)},
    //Kelvin	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = 131;
    //G2C_SHADE_P1 = -284;
    //G2C_SHADE_P0 =  261;
    {1,(8),(-45),(258)},
    //Walden	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = 8;
    //G2C_SHADE_P1 = -45;
    //G2C_SHADE_P0 =  258;
    {1,(0),(0),(255)},
    //F1977	G2C_SHADE_EN = 1;
    //G2C_SHADE_P2 = 0;
    //G2C_SHADE_P1 = 0;
    //G2C_SHADE_P0 = 255;
};

#if 0
typedef volatile union _DIP_X_REG_G2C_SHADE_CON_1_
{
        volatile struct /* 0x15022858 */
        {
                FIELD  G2C_SHADE_VAR                         : 18;      /*  0..17, 0x0003FFFF */
                FIELD  G2C_SHADE_P0                          : 11;      /* 18..28, 0x1FFC0000 */
                FIELD  G2C_SHADE_EN                          :  1;      /* 29..29, 0x20000000 */
                FIELD  rsv_30                                :  2;      /* 30..31, 0xC0000000 */
        } Bits;
        UINT32 Raw;
}DIP_X_REG_G2C_SHADE_CON_1; /* DIP_X_G2C_SHADE_CON_1, DIP_A_G2C_SHADE_CON_1*/

#endif
#define LOMO_G2C_SHADE_T_PARSER(REG_IDX,LOMO_IDX) ((REG_IDX==LOMO_PARA_G2C_SHADE_con_1)?\
	                                                                                            (((loadLomoFilterG2C[LOMO_IDX].G2C_SHADE_EN&0x1)<<29/*28*/)|\
	                                                                                            ((DATA_11BIT_2COMP_DATA(loadLomoFilterG2C[LOMO_IDX].G2C_SHADE_P0))<<18/*16*/))\
	                                                                                                :((REG_IDX==LOMO_PARA_G2C_SHADE_con_2)?\
	                                                                                                    ((DATA_11BIT_2COMP_DATA((loadLomoFilterG2C[LOMO_IDX].G2C_SHADE_P1))<<0)|\
	                                                                                                    ((DATA_11BIT_2COMP_DATA(loadLomoFilterG2C[LOMO_IDX].G2C_SHADE_P2))<<12))\
	                                                                                                        :0x0)\
	                                                                                        )
#define LOMO_PARA_GET_SHADE(REG_IDX, LOMO_IDX)  (MUINT32)(LomoFilterG2CDefault.set[REG_IDX])|\
	                                                                                  (MUINT32)LOMO_G2C_SHADE_T_PARSER(REG_IDX, LOMO_IDX)

#endif

//#define LOMO_PARA_GET_SHADE(REG_IDX, LOMO_IDX)  (MUINT32)(LomoFilterG2CDefault.set[LOMO_PARA_G2C_SHADE_##REG_IDX])&(MUINT32)LomoFilterG2C[LOMO_IDX].G2C_SHADE_EN

#define TEST_LOMO_PARA_GET_SHADE_con1_NASH LOMO_PARA_GET_SHADE(LOMO_PARA_G2C_SHADE_con_1,LOMO_NASHVILLE)
#define TEST_LOMO_PARA_GET_SHADE_con2_HEFE LOMO_PARA_GET_SHADE(LOMO_PARA_G2C_SHADE_con_2,LOMO_HEFE)
#define TEST_LOMO_G2C_SHADE_T_PARSER_con1_NASH LOMO_G2C_SHADE_T_PARSER(LOMO_PARA_G2C_SHADE_con_1,LOMO_NASHVILLE)

#define NASHVILLE_GGM     "Nashville_gamma.h"
#define HEFE_GGM               "Hefe_gamma.h"
#define VALENCIA_GGM       "Valencia_gamma.h"
#define XPROII_GGM            "XproII_gamma.h"
#define LOFI_GGM               "Lofi_gamma.h"
#define SIERRA_GGM           "Sierra_gamma.h"
#define KELVIN_GGM           "Kelvin_gamma.h"
#define WALDEN_GGM         "Walden_gamma.h"
#define F1977_GGM             "F1977_gamma.h"


MUINT32 LomoFilterGGM[LOMO_TYPE_NUM][CUSTOM_LOMO_GGM_GAIN_NUM]=//const INT32 LomoFilterGGM[LOMO_TYPE_NUM][CUSTOM_LOMO_GGM_CHANNEL_NUM][CUSTOM_LOMO_GGM_GAIN_NUM]=
{

    //Normal	G2C_SHADE_EN = 0;
        #include NASHVILLE_GGM
    //Nashville	G2C_SHADE_EN = 1;
        #include NASHVILLE_GGM
    //Hefe	G2C_SHADE_EN = 1;
        #include HEFE_GGM
    //Valencia	G2C_SHADE_EN = 1;
        #include VALENCIA_GGM
    //XproII	G2C_SHADE_EN = 1;
        #include XPROII_GGM
    //Lofi	G2C_SHADE_EN = 1;
        #include LOFI_GGM
    //Sierra	G2C_SHADE_EN = 1;
        #include SIERRA_GGM
    //Kelvin	G2C_SHADE_EN = 1;
        #include KELVIN_GGM
    //Walden	G2C_SHADE_EN = 1;
        #include WALDEN_GGM
    //F1977	G2C_SHADE_EN = 1;
        #include F1977_GGM
};

#endif // _CAMERA_CUSTOM_LOMO_PARAM_H_


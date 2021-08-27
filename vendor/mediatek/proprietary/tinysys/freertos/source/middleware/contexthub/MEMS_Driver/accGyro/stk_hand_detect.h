#ifndef __STK_HAND_DETECT_H__
#define __STK_HAND_DETECT_H__

enum stkHandDetectAction
{
    HD_NONE_ACTION = 0,
    HD_WAKEUP_SCREENON_ACTION,
    HD_RIGHTLEFT_SIDE_SCREENOFF_ACTION,
    HD_FRONTBACK_LIE_SCREENOFF_ACTION,
    HD_RIGHTLEFT_LIE_SCREENOFF_ACTION,
};

int stk_hand_detect(int16_t *acc);
#endif /* __STK_HAND_DETECT_H__ */
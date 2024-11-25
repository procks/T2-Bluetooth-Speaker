#include "task_bt_key.h"
#include "common/msg.h"
/*******************************************************************
                            AD按键表
*******************************************************************/
#define ADKEY_BT_SHORT		\
                        /*00 2*/    MSG_VOL_DOWN,\
                        /*01 x*/    NO_MSG,\
                        /*02 4*/    MSG_BT_NEXT_FILE,\
                        /*03 1*/    MSG_VOL_UP,\
                        /*04 3*/    MSG_BT_PP,\
                        /*05 x*/    NO_MSG,\
                        /*06 x*/    NO_MSG,\
                        /*07 x*/    NO_MSG,\
                        /*08  */    NO_MSG,\
                        /*09 0*/    NO_MSG,

#define ADKEY_BT_LONG		\
                        /*00 2*/    MSG_VOL_DOWN,\
                        /*01*/    NO_MSG,\
                        /*02 4*/    MSG_CHANGE_WORKMODE,\
                        /*03 1*/    MSG_VOL_UP,\
                        /*04 3*/    MSG_BT_PREV_FILE,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09 0*/    MSG_POWER_OFF,

#define ADKEY_BT_HOLD		\
                        /*00*/    MSG_VOL_DOWN,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    MSG_VOL_UP,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_POWER_OFF_HOLD,

#define ADKEY_BT_LONG_UP	\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    MSG_VOL_KEY_UP,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_POWER_KEY_UP,


const u16 task_bt_ad_table[4][KEY_REG_AD_MAX] = {
    /*短按*/	    {ADKEY_BT_SHORT},
    /*长按*/		{ADKEY_BT_LONG},
    /*连按*/		{ADKEY_BT_HOLD},
    /*长按抬起*/	{ADKEY_BT_LONG_UP},
};

/*******************************************************************
                            I/O按键表
MSG_BT_TRAIN_SCAN_DEVICE\MSG_BT_TRAIN_DEVICE\MSG_BT_SEARCH_DEVICE
*******************************************************************/
#define IOKEY_BT_SHORT		\
                        /*00*/    MSG_BT_SEARCH_DEVICE,\
                        /*01*/    MSG_BT_PREV_FILE,\
                        /*02*/    MSG_BT_NEXT_FILE,\
                        /*03*/    MSG_CHANGE_WORKMODE,\
                        /*04*/    MSG_EQ_MODE,\
                        /*05*/    MSG_BT_PP,\
                        /*06*/    MSG_BT_HID_TAKE_PIC,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    MSG_BT_TRAIN_DEVICE ,

#define IOKEY_BT_LONG		\
                        /*00*/    MSG_POWER_OFF,\
                        /*01*/    MSG_VOL_DOWN,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*09*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,


#define IOKEY_BT_HOLD		\
                        /*00*/    MSG_POWER_OFF_HOLD,\
                        /*01*/    MSG_VOL_DOWN,\
                        /*02*/    MSG_VOL_UP,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define IOKEY_BT_LONG_UP	\
                        /*00*/    MSG_POWER_KEY_UP,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

const u16 task_bt_io_table[4][KEY_REG_IO_MAX] = {
    /*短按*/	    {IOKEY_BT_SHORT},
    /*长按*/		{IOKEY_BT_LONG},
    /*连按*/		{IOKEY_BT_HOLD},
    /*长按抬起*/	{IOKEY_BT_LONG_UP},
};

/*******************************************************************
                            IR按键表
*******************************************************************/
#define IRFF00_BT_KEY_SHORT			\
                                /*00*/    MSG_ECHO_SW,\
							    /*01*/    MSG_CHANGE_WORKMODE,\
								/*02*/    MSG_MUTE,\
								/*03*/    MSG_ECHO_MUSIC_VOL_SW,\
								/*04*/    MSG_ECHO_MUSIC_VOL_SET,\
								/*05*/    MSG_ECHO_MIC_VOL_SET,\
								/*06*/    NO_MSG,\
								/*07*/    MSG_ECHO_DECAY_SET,\
								/*08*/    MSG_ECHO_PITCH_SET,\
								/*09*/    MSG_0,\
                                /*10*/    MSG_ECHO_DEEP_SET,\
								/*11*/    NO_MSG,\
								/*12*/    MSG_1,\
                                /*13*/    NO_MSG ,\
							    /*14*/    NO_MSG,\
								/*15*/    NO_MSG,\
								/*16*/    NO_MSG,\
								/*17*/    NO_MSG ,\
								/*18*/    NO_MSG ,\
								/*19*/    NO_MSG,\
								/*20*/    NO_MSG,

#define IRFF00_BT_KEY_LONG			\
								/*00*/    NO_MSG,\
                                /*01*/    NO_MSG,\
								/*02*/    NO_MSG,\
								/*03*/    NO_MSG,\
								/*04*/    NO_MSG,\
								/*05*/    NO_MSG,\
								/*06*/    NO_MSG,\
								/*07*/    NO_MSG,\
								/*08*/    NO_MSG,\
								/*09*/    NO_MSG,\
                                /*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG,\
								/*16*/    NO_MSG,\
								/*17*/    NO_MSG,\
								/*18*/    NO_MSG,\
								/*19*/    NO_MSG,\
								/*20*/    NO_MSG

#define IRFF00_BT_KEY_HOLD			\
								/*00*/    NO_MSG,\
                                /*01*/    NO_MSG,\
								/*02*/    NO_MSG,\
								/*03*/    NO_MSG,\
								/*04*/    NO_MSG,\
								/*05*/    NO_MSG,\
								/*06*/    NO_MSG,\
								/*07*/    NO_MSG,\
								/*08*/    NO_MSG,\
								/*09*/    NO_MSG,\
                                /*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
								/*14*/    NO_MSG,\
								/*15*/    NO_MSG,\
								/*16*/    NO_MSG,\
								/*17*/    NO_MSG,\
								/*18*/    NO_MSG,\
								/*19*/    NO_MSG,\
								/*20*/    NO_MSG


#define IRFF00_BT_KEY_LONG_UP 		\
								/*00*/    NO_MSG,\
                                /*01*/    NO_MSG,\
								/*02*/    NO_MSG,\
								/*03*/    NO_MSG,\
								/*04*/    NO_MSG,\
								/*05*/    NO_MSG,\
								/*06*/    NO_MSG,\
								/*07*/    NO_MSG,\
								/*08*/    NO_MSG,\
								/*09*/    NO_MSG,\
								/*10*/    NO_MSG,\
								/*11*/    NO_MSG,\
								/*12*/    NO_MSG,\
								/*13*/    NO_MSG,\
                                /*14*/    NO_MSG,\
								/*15*/    NO_MSG,\
								/*16*/    NO_MSG,\
								/*17*/    NO_MSG,\
								/*18*/    NO_MSG,\
								/*19*/    NO_MSG,\
								/*20*/    NO_MSG
const u16 task_bt_ir_table[4][KEY_REG_IR_MAX] = {
    /*短按*/	    {IRFF00_BT_KEY_SHORT},
    /*长按*/		{IRFF00_BT_KEY_LONG},
    /*连按*/		{IRFF00_BT_KEY_HOLD},
    /*长按抬起*/	{IRFF00_BT_KEY_LONG_UP},
};


/*******************************************************************
                            touchkey按键表
*******************************************************************/
#define TOUCHKEY_BT_SHORT		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define TOUCHKEY_BT_LONG		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,


#define TOUCHKEY_BT_HOLD		\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

#define TOUCHKEY_BT_LONG_UP	\
                        /*00*/    NO_MSG,\
                        /*01*/    NO_MSG,\
                        /*02*/    NO_MSG,\
                        /*03*/    NO_MSG,\
                        /*04*/    NO_MSG,\
                        /*05*/    NO_MSG,\
                        /*06*/    NO_MSG,\
                        /*07*/    NO_MSG,\
                        /*08*/    NO_MSG,\
                        /*09*/    NO_MSG,

const u16 task_bt_touch_table[4][KEY_REG_TOUCH_MAX] = {
    /*短按*/	    {TOUCHKEY_BT_SHORT},
    /*长按*/		{TOUCHKEY_BT_LONG},
    /*连按*/		{TOUCHKEY_BT_HOLD},

    /*长按抬起*/	{TOUCHKEY_BT_LONG_UP},
};



/*******************************************************************
                            按键总驱动表
*******************************************************************/
const KEY_REG task_bt_key = {
#if (KEY_AD_RTCVDD_EN||KEY_AD_VDDIO_EN)
    ._ad = task_bt_ad_table,
#endif
#if KEY_IO_EN
    ._io = task_bt_io_table,
#endif
#if KEY_IR_EN
    ._ir = task_bt_ir_table,
#endif
#if KEY_TCH_EN
    ._touch = task_bt_touch_table,
#endif
#if KEY_UART_EN
    ._uart = task_bt_io_table,//task_bt_touch_table,
#endif
};


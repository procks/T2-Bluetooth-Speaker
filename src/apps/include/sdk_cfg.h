/*********************************************************************************************
    *   Filename        : sdk_cfg.h
    *   Description     : Config for Sound Box Case
    *   Author          : Bingquan
    *   Email           : bingquan_cai@zh-jieli.com
    *   Last modifiled  : 2018-4-07 15:36
    *   Copyright:(c)JIELI  2011-2018  @ , All Rights Reserved.
*********************************************************************************************/
#ifndef _CONFIG_
#define _CONFIG_
#include "includes.h"
#include "sdk_const_define.h"
/********               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                  ********/
// Please read this function mutual exclusion description carefully before modifying the configuration, thank you
// Due to the limited resources of AC692X, SDK development currently knows that some of the following functions cannot be used at the same time.
//1. When using the background, you must not use the FM function inside the chip (determined by the hardware specifications)
//2. The background, reverberation, and TWS functions are mutually exclusive, and only one of them can exist (insufficient RAM resources)
//3. The independent camera mode and the background cannot be opened at the same time (the address and name need to be initialized independently)
//4. When the reverberation is turned on, the software EQ and BLE cannot be turned on (insufficient RAM resources)
//5. When TWS is turned on, the software EQ cannot be used (computing speed limit)
//6. FM does not support recording (insufficient RAM resources)
//7. Linein and mic cannot be recorded at the same time (determined by the hardware specifications)
//8. Added one-to-two (can also support the background), but it is mutually exclusive with the reverberation and TWS functions, and only one of them can exist (insufficient RAM resources)
/*******************************************************************************/
/************************************************************************************/
//------------------------------Debug Class Configuration
/********************************************************************************/
//<Enable system print debugging function
#define __DEBUG

#ifdef __DEBUG
//Serial print IO port selection
#define DEBUG_UART_SEL          UART0_TXPA5_RXPA6
//Serial port baud rate selection
#define DEBUG_UART_RATE         460800    //115200
//打印函数
#define log_printf		        printf
#else
#define log_printf(...)
#endif

#define UART_UPDATA_EN          0

/********************************************************************************/
//------------------------------Power supply configuration
/********************************************************************************/
//<电量监测
#define SYS_LVD_EN              1
#define POWER_EXTERN_DETECT_EN  0	//External voltage and power detection, generally used for cigarette lighter to collect vehicle battery voltage
//Optional Configuration：PWR_NO_CHANGE / PWR_LDO15 / PWR_DCDC15
#define PWR_MODE_SELECT        PWR_LDO15
///Bluetooth no connection automatic shutdown timer, u16 type, 0 means no automatic shutdown
#define AUTO_SHUT_DOWN_TIME     10*2*60 //((3*60* 2)/2+10) //Divide by 2 minus the time it takes to enter low power consumption Approximate number
///<Button double click function
#define KEY_DOUBLE_CLICK        1
///<Battery power is low, whether to switch power output configuration
#define SWITCH_PWR_CONFIG		0

#define SYS_VDDIO_LEVEL         1
#define SYS_RTCVDD_LEVEL        1

#define SYS_LDO_REDUCE_LEVEL    2

#define LOW_POWER_NOISE_DEAL    0   //Low power noise processing, this problem exists in the package where VDDIO and HPVDD are tied together

/********************************************************************************/
//------------------------------Sound Effects Configuration
/********************************************************************************/
//EQ config.  //more config in audio_stream.h
//EQ Selection:EQ_RUN_NULL(Do not run EQ) / EQ_RUN_HW (Hardware EQ) / EQ_RUN_SW (Software EQ)
#define EQ_RUN_SEL              EQ_RUN_HW    /*For more sound effect settings, please configure in the audio_stream.h header file*/
//EQ Serial port online debugging enabled
#define EQ_UART_DEBUG           0
//Online EQ adjustment, serial port selection. Optional:UART1_TXPB0_RXPB1  /  UART1_USB_TXDP_RXDM
#define EQ_DEBUG_UART_SEL       UART1_TXPB0_RXPB1    //EQ_UART_DEBUG 为1时有效
#define EQ_DEBUG_UART_RATE      9600
//<Speed ​​and pitch change
// Note that when this function is enabled, the chip performance should be considered, the system frequency should be increased accordingly,
// and try not to open it at the same time as other applications with high CPU usage
#define SPEED_PITCH_EN			0
/********************************************************************************/
//------------------------------DAC Configuration
/********************************************************************************/
//Whether to choose VCMO direct push headphones
#define VCOMO_EN 	            0
//DAC channel selection：DAC_L_R_CHANNEL / DAC_L_CHANNEL / DAC_R_CHANNEL
#define DAC_CHANNEL_SLECT       DAC_L_CHANNEL
//<dac differential output
#define DAC_DIFF_OUTPUT		 	0
//<dac channel merging
#define DAC_SOUNDTRACK_COMPOUND 0
//<dac channel difference
#define DAC_SOUNDTRACK_SUBTRACT 0
//<Talk is switched to differential output (provided that VCOMO_EN is 1)
#define CALL_USE_DIFF_OUTPUT	0
//<Automatic mute
#define DAC_AUTO_MUTE_EN	    1
//<Key Tone
#define TONE_EN     	    	1
//<Non-zero means use the default volume
#define SYS_DEFAULT_VOL         0
//<Non-zero means the prompt tone uses the default volume
#define TONE_DEFAULT_VOL        1

/********************************************************************************/
//------------------------------Peripheral configuration
/********************************************************************************/
#define SDMMC0_EN               0
#define SDMMC1_EN               1
#define USB_DISK_EN             1
#define USB_PC_EN               1
//When the device is online, whether to enter the music mode when powered on. 1: Do not enter the music mode when the device is powered on 0: Enter the music mode when powered on
#define POWERUP_DEV_IGNORE      1
//Whether tasks that do not use the device require shutting down the device, device compatibility should be considered when turning it on.
#define DEV_POWER_OFF_EN        0

//usb_sd pin multiplexing, need to test compatibility
#define USB_SD0_MULT_EN     0   //<Need to test compatibility
#define USB_SD1_MULT_EN     0   //<Need to test compatibility

// ADKEY and SD are reused, and compatibility needs to be tested.
// Note: ADKEY with a lower voltage divider resistance value cannot be used,
// which will affect the SD card. Please ensure that the voltage divider is greater than 1.8V
#define ADKEY_SD_MULT_EN    0   //0 not reuse 1 Reuse sd0 2 Reuse sd1

#if(USB_SD0_MULT_EN == 1)||(USB_SD1_MULT_EN == 1)
#undef USB_PC_EN
#define USB_PC_EN       0
#endif



/********************************************************************************/
//------------------------------Bluetooth Class Configuration
/********************************************************************************/
#include "bluetooth/bluetooth_api.h"

///Optional configuration: 0 (ordinary speaker)/BT_TWS_TRANSMIT (enable speaker pairing)
// If it is only used as a single device, it is recommended not to open the speaker pairing macro.
// If the speaker pairing macro is opened and used as a single device, the baseband will be occupied,
// and the performance of the single device will not be as good as without the speaker pairing macro.
#define BT_TWS                  0//BT_TWS_TRANSMIT
#if BT_TWS
#undef  EQ_RUN_SEL
#define EQ_RUN_SEL              EQ_RUN_NULL/*这个宏不修改，其它更多音效设置请在audio_stream.h头文件配置*/
#endif

///Bluetooth connection number selection 1 /2 One to Two
#if BT_TWS
#define BT_CONNTCT_NUM             2
#define BT_TWS_LINEIN              0  //linein Convert to box play
#else
#define BT_CONNTCT_NUM             1
#define BT_TWS_LINEIN              0
#endif

//Is Bluetooth enabled in background mode?
#if (BT_CONNTCT_NUM == 2)
#define BT_BACKGROUND_EN		0
#else
#define BT_BACKGROUND_EN		0
#endif
#if (BT_BACKGROUND_EN== 0)
///<HID The independent mode of taking photos only supports non-background
#define BT_HID_INDEPENDENT_MODE  0
#endif
//可选配置：NORMAL_MODE/TEST_BQB_MODE/TEST_FCC_MODE/TEST_FRE_OFF_MODE/TEST_BOX_MODE/TEST_PERFOR_MODE
#define BT_MODE             NORMAL_MODE      // TEST_PERFOR_MODE

//模拟配置
#define BT_ANALOG_CFG           0
#define BT_XOSC                 0

//Bluetooth crystal frequency deviation setting 0x0~0xf//If the frequency deviation is positive, increase the value
#define BT_OSC_INTERNAL_L       0x09
#define BT_OSC_INTERNAL_R       0x09

//------------------------------Bluetooth low power consumption settings
//After enabling this function, it can only be a pure Bluetooth function, without display function

//可选配置：SNIFF_EN/SNIFF_TOW_CONN_ENTER_POWERDOWN_EN
#define SNIFF_MODE_CONF	       0//	SNIFF_EN
//可选配置：BT_POWER_DOWN_EN/BT_POWER_OFF_EN
#define BT_LOW_POWER_MODE      0// BT_POWER_DOWN_EN
//可选配置：BT_OSC/RTC_OSCH/RTC_OSCL/LRC_32K
#define LOWPOWER_OSC_TYPE     BT_OSC // LRC_32K
//可选配置：32768L//24000000L//32000L
#define LOWPOWER_OSC_HZ       24000000L//  32000L
//可选配置：BT_BREDR_EN/BT_BLE_EN/(BT_BREDR_EN|BT_BLE_EN)

#if BT_TWS

#undef  SNIFF_MODE_CONF
#define SNIFF_MODE_CONF         0

#undef  BT_LOW_POWER_MODE
#define BT_LOW_POWER_MODE       0

#define BLE_BREDR_MODE          (BT_BREDR_EN)//资源充足的情况，tws 可以开启ble
#else
#define BLE_BREDR_MODE          (BT_BREDR_EN/*|BT_BLE_EN*/)//Resource problem, BLE is enabled, but one-to-two cannot be enabled
#endif

#if (BLE_BREDR_MODE&BT_BLE_EN)
//Optional configuration：O--server ,1--client
#define BLE_GAP_ROLE            0
#endif

#define	BT_PHONE_NUMBER		    0
#define	BT_PHONE_VOL_SYNC       0
//Need battery display but no call function
#define BT_HFP_EN_SCO_DIS		0
//Play the phone's own incoming call reminder tone (provided the phone supports this function)
#define BT_INBAND_RINGTONE		0
//Switch the roles of the boxes, the device connected to the phone becomes the host
#define BT_TWS_ROLE_SWITCH		1

///对耳主从同时按下配对按键才进行配对
#define    BT_TWS_SCAN_ENBLE        0
///主从连接上，同步播连接成功提示音、sync_led_scan
#define    BT_TWS_SYNC_CON_STATE_ENBLE        1
/********************************************************************************/
//------------------------------MUSIC MACRO
/********************************************************************************/
//SMP加密文件支持
#define MUSIC_DECRYPT_EN 		0
//<MP3
#define DEC_TYPE_MP3_ENABLE     1
//<SBC
#define DEC_TYPE_SBC_ENABLE     1
//<AAC
#define DEC_TYPE_AAC_ENABLE		0
//<8K_code_space
#define DEC_TYPE_WAV_ENABLE     0
//<8K_code_space
#define DEC_TYPE_FLAC_ENABLE    0
//<8K_code_space
#define DEC_TYPE_APE_ENABLE     0
//<32K_code_space
#define DEC_TYPE_WMA_ENABLE     0
//<32K_code_space
#define DEC_TYPE_F1A_ENABLE     0
//<2K_code_space
#define DEC_TYPE_NWT_ENABLE     0
//<76K_code_space
#define DEC_TYPE_AMR_ENABLE     0
//<112K_code_space
#define DEC_TYPE_DTS_ENABLE     0

/********************************************************************************/
//------------------------------FM MACRO
/********************************************************************************/
//<标准SDK
#define FM_RADIO_EN             1

//dependency
#if (FM_RADIO_EN == 1)
//<RDA5807FM
#define RDA5807                 0
//<BK1080FM
#define BK1080                  0
//<QN8035FM
#define QN8035                  0
//<芯片内部FM
#if BT_BACKGROUND_EN
//蓝牙RF和收音RF共用，使用后台不能用内部收音
#define FM_INSIDE               0
#else
#define FM_INSIDE               1
#endif
#endif

/********************************************************************************/
//------------------------------AUX MACRO
/********************************************************************************/
#define AUX_AD_ENABLE           1
//aux检测使能
#define AUX_DETECT_EN           1

#if AUX_DETECT_EN
#define AUX_DET_MULTI_AD_KEY    0     //ad_key复用aux检测
#endif

/********************************************************************************/
//------------------------------REC MACRO
///********************************************************************************/
///<Standard SDK recording function
#define REC_EN              0


#if (REC_EN == 1)
///<MIC recording enable
#define MIC_REC_EN		1
#define AUX_REC_EN      1
#define FM_REC_EN       1
#define BT_REC_EN       1

#if (AUX_REC_EN == 1)  //AUX must be a digital channel
#undef AUX_AD_ENABLE
#define AUX_AD_ENABLE   1
#endif

#define REC_PLAY_EN     1
#endif

/********************************************************************************/
//------------------------------RTC MACRO
/********************************************************************************/
//Standard SDK RTC clock mode
#define RTC_CLK_EN              0

//dependency
#if (RTC_CLK_EN == 1)
//<RTC alarm mode
#define RTC_ALM_EN              1
#endif

/********************************************************************************/
//------------------------------ECHO MACRO
/********************************************************************************/
//Reverb Enable, after turning it on, you can enable the reverb function under BT/FM/MUSIC/LINEIN.
#define ECHO_EN                 0

#if ECHO_EN
//When ECHO_EN is 1, the following configuration is valid
#define PITCH_EN                1
//Individual reverb mode enable
#define TASK_ECHO_EN            1

//Reverb is generally not automatically MUTE DAC
#undef DAC_AUTO_MUTE_EN
#define  DAC_AUTO_MUTE_EN       0

//混响不能开AUX的AD通道
#undef AUX_AD_ENABLE
#define AUX_AD_ENABLE   0

//混响与AUX录音有冲突，不能同时开
#undef AUX_REC_EN
#define AUX_REC_EN      0
#endif

/********************************************************************************/
//------------------------------FM TRANSMITTER MACRO
///********************************************************************************/
////FM发射器配置，点烟器用
#define FMTX_EN       0

#if (FMTX_EN)
//QN8027
#define QN8027                 	1
//QN8007
#define QN8007					0
#endif

/********************************************************************************/
//------------------------------UI MACRO
/********************************************************************************/
///<LED指示使能
#define LED_EN                  1

#define UI_ENABLE               1
#if (BT_LOW_POWER_MODE || SNIFF_MODE_CONF)            //进低功耗模式 not support ui
#undef  UI_ENABLE
#define UI_ENABLE               0
#endif
///dependency
#if (UI_ENABLE == 1)
#define UI_SEL_BY_RES_EN		0	  ///是否通过选屏电阻进行选屏
#define LED_7_EN                1     ///<led 支持
#define LED_1888_EN             0	  ///6脚数码管，点烟器一般用这个
#define LCD_128X64_EN           0	  ///点阵屏LCD
#else
///都不支持
#define LED_7_EN                0
#define LED_1888_EN             0
#define LCD_128X64_EN           0
#endif

#if (LCD_128X64_EN == 1)
#define LRC_LYRICS_EN			1	  ///LRC歌词显示
#else
#define LRC_LYRICS_EN           0
#endif

/********************************************************************************/
//------------------------------System clock and other configurations
/********************************************************************************/
//时钟配置  //more config in clock_interface.h
#define OSC_Hz                  24000000L	//fpga:12M / chip:24M

///<SYS_CLK   //不同工作状态的系统时钟选则
#define BT_CALL_Hz		        160000000L	//phone call clock
#define BT_REC_Hz		        192000000L	//bt rec clock

#if (EQ_RUN_SEL == EQ_RUN_SW || SPEED_PITCH_EN || ECHO_EN )    //Software EQ need Run 192M
#define MUSIC_DECODE_Hz         192000000L
#define SYS_Hz		            192000000L  //120000000L//96000000L
#else
#define MUSIC_DECODE_Hz         160000000L
#if BT_TWS
#define SYS_Hz		            192000000L
#else
#define SYS_Hz		            120000000L
#endif
#endif


/********************************************************************************/
//------------------------------Conflicting macro handling
/********************************************************************************/
//USB口用于调试时, 关闭USB_DISK/PC功能.
#if ( (defined(__DEBUG) && (DEBUG_UART_SEL == UART1_USB_TXDP_RXDM)) || \
       ( EQ_UART_DEBUG && (EQ_DEBUG_UART_SEL == UART1_USB_TXDP_RXDM) ))
#undef  USB_DISK_EN
#undef  USB_PC_EN
#define USB_DISK_EN             0
#define USB_PC_EN               0
#endif

//调试用的串口 和 EQ在线调试串口冲突
#if ( (defined(__DEBUG) && (DEBUG_UART_SEL == UART1_USB_TXDP_RXDM)) && \
       ( EQ_UART_DEBUG && (EQ_DEBUG_UART_SEL == UART1_USB_TXDP_RXDM) ))
#error "DEBUG_UART_SEL same with EQ_DEBUG_UART_SEL"
#endif

//没有内部收音也没有外部收音时不定义收音模式
#if ( (RDA5807 == 0 ) && (BK1080 == 0 ) && (QN8035 == 0) && (FM_INSIDE==0) )
#undef FM_RADIO_EN
#define FM_RADIO_EN             0
#endif

//没有FM发射芯片的时候不开点烟器的宏
#if ( (QN8007 == 0 ) && (QN8027 == 0 ) )
#undef FMTX_EN
#define FMTX_EN       0
#endif

//点烟器不需要FM收音模式
#if (FMTX_EN == 1)
#undef FM_RADIO_EN
#define FM_RADIO_EN             0
#endif

#if (ECHO_EN == 1)
#undef  DAC_AUTO_MUTE_EN
#define DAC_AUTO_MUTE_EN		0
#endif

#if (SNIFF_MODE_CONF == SNIFF_EN)
#undef  DEV_POWER_OFF_EN
#define DEV_POWER_OFF_EN    1
#endif

#endif  //end of _SDK_CFG_

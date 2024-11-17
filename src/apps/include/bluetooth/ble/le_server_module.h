// binary representation
// attribute size in bytes (16), flags(16), handle (16), uuid (16/128), value(...)

#ifndef _LE_SERVER_MODULE_H
#define _LE_SERVER_MODULE_H

#include <stdint.h>
#include <le_user.h>
//
// gatt profile include file, generated by jieli gatt_inc_generator.exe
//

const uint8_t profile_data[] = {
    //////////////////////////////////////////////////////
    //
    // 0x0001 PRIMARY_SERVICE  1800
    //
    //////////////////////////////////////////////////////
    0x0a, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x28, 0x00, 0x18,

    /* CHARACTERISTIC,  2a00, READ | WRITE | DYNAMIC, */
    // 0x0002 CHARACTERISTIC 2a00 READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x02, 0x00, 0x03, 0x28, 0x0a, 0x03, 0x00, 0x00, 0x2a,
    // 0x0003 VALUE 2a00 READ | WRITE | DYNAMIC
    0x08, 0x00, 0x0a, 0x01, 0x03, 0x00, 0x00, 0x2a,

    //////////////////////////////////////////////////////
    //
    // 0x0004 PRIMARY_SERVICE  ae00
    //
    //////////////////////////////////////////////////////
    0x0a, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x28, 0x00, 0xae,

    /* CHARACTERISTIC,  ae01, WRITE_WITHOUT_RESPONSE | DYNAMIC, */
    // 0x0005 CHARACTERISTIC ae01 WRITE_WITHOUT_RESPONSE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x05, 0x00, 0x03, 0x28, 0x04, 0x06, 0x00, 0x01, 0xae,
    // 0x0006 VALUE ae01 WRITE_WITHOUT_RESPONSE | DYNAMIC
    0x08, 0x00, 0x04, 0x01, 0x06, 0x00, 0x01, 0xae,

    /* CHARACTERISTIC,  ae02, NOTIFY, */
    // 0x0007 CHARACTERISTIC ae02 NOTIFY
    0x0d, 0x00, 0x02, 0x00, 0x07, 0x00, 0x03, 0x28, 0x10, 0x08, 0x00, 0x02, 0xae,
    // 0x0008 VALUE ae02 NOTIFY
    0x08, 0x00, 0x10, 0x00, 0x08, 0x00, 0x02, 0xae,
    // 0x0009 CLIENT_CHARACTERISTIC_CONFIGURATION
    0x0a, 0x00, 0x0a, 0x01, 0x09, 0x00, 0x02, 0x29, 0x00, 0x00,

    /* CHARACTERISTIC,  ae03, WRITE_WITHOUT_RESPONSE | DYNAMIC, */
    // 0x000a CHARACTERISTIC ae03 WRITE_WITHOUT_RESPONSE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x03, 0x28, 0x04, 0x0b, 0x00, 0x03, 0xae,
    // 0x000b VALUE ae03 WRITE_WITHOUT_RESPONSE | DYNAMIC
    0x08, 0x00, 0x04, 0x01, 0x0b, 0x00, 0x03, 0xae,

    /* CHARACTERISTIC,  ae04, NOTIFY, */
    // 0x000c CHARACTERISTIC ae04 NOTIFY
    0x0d, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x03, 0x28, 0x10, 0x0d, 0x00, 0x04, 0xae,
    // 0x000d VALUE ae04 NOTIFY
    0x08, 0x00, 0x10, 0x00, 0x0d, 0x00, 0x04, 0xae,
    // 0x000e CLIENT_CHARACTERISTIC_CONFIGURATION
    0x0a, 0x00, 0x0a, 0x01, 0x0e, 0x00, 0x02, 0x29, 0x00, 0x00,

    /* CHARACTERISTIC,  ae05, INDICATE, */
    // 0x000f CHARACTERISTIC ae05 INDICATE
    0x0d, 0x00, 0x02, 0x00, 0x0f, 0x00, 0x03, 0x28, 0x20, 0x10, 0x00, 0x05, 0xae,
    // 0x0010 VALUE ae05 INDICATE
    0x08, 0x00, 0x20, 0x00, 0x10, 0x00, 0x05, 0xae,
    // 0x0011 CLIENT_CHARACTERISTIC_CONFIGURATION
    0x0a, 0x00, 0x0a, 0x01, 0x11, 0x00, 0x02, 0x29, 0x00, 0x00,

    /* CHARACTERISTIC,  ae10, READ | WRITE | DYNAMIC, */
    // 0x0012 CHARACTERISTIC ae10 READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x12, 0x00, 0x03, 0x28, 0x0a, 0x13, 0x00, 0x10, 0xae,
    // 0x0013 VALUE ae10 READ | WRITE | DYNAMIC
    0x08, 0x00, 0x0a, 0x01, 0x13, 0x00, 0x10, 0xae,

    //////////////////////////////////////////////////////
    //
    // 0x0014 PRIMARY_SERVICE  1812
    //
    //////////////////////////////////////////////////////
    0x0a, 0x00, 0x02, 0x00, 0x14, 0x00, 0x00, 0x28, 0x12, 0x18,

#if 0// authentication
    //
    10, 0x00,   0x00, 0x00,    0x1A, 0x00,     0x00, 0x28,     0x0A, 0x18,                                     //primary service declaration
    13, 0x00,   0x02, 0x00,    0x1B, 0x00,     0x03, 0x28,     0x02, 0x1C, 0x00, 0x50, 0x2A,                   //characteristic declaration
    15, 0x00,   0x02, 0x04,    0x1C, 0x00,     0x50, 0x2A,     0x02, 0x8A, 0x24, 0x66, 0x82, 0x34, 0x36,       //PnP ID
#endif

    // END
    0x00, 0x00,
};
//
// characteristics <--> handles
//
#define ATT_CHARACTERISTIC_2a00_01_VALUE_HANDLE 0x0003
#define ATT_CHARACTERISTIC_ae01_01_VALUE_HANDLE 0x0006
#define ATT_CHARACTERISTIC_ae02_01_VALUE_HANDLE 0x0008
#define ATT_CHARACTERISTIC_ae02_01_CLIENT_CONFIGURATION_HANDLE 0x0009
#define ATT_CHARACTERISTIC_ae03_01_VALUE_HANDLE 0x000b
#define ATT_CHARACTERISTIC_ae04_01_VALUE_HANDLE 0x000d
#define ATT_CHARACTERISTIC_ae04_01_CLIENT_CONFIGURATION_HANDLE 0x000e
#define ATT_CHARACTERISTIC_ae05_01_VALUE_HANDLE 0x0010
#define ATT_CHARACTERISTIC_ae05_01_CLIENT_CONFIGURATION_HANDLE 0x0011
#define ATT_CHARACTERISTIC_ae10_01_VALUE_HANDLE 0x0013

#endif

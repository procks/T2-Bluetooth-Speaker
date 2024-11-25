#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "typedef.h"
#include "circular_buf.h"
#include "audio/audio_stream.h"
#include "audio/eq.h"

extern struct SOUND_VAR sound;

typedef struct __AUDIO_STREAM_DAC {
    volatile u8 	flag;
    cbuffer_t 		cbuf;
    u8 				*buf;
    u32 			buf_size;
} AUDIO_STREAM_DAC;

extern const AUDIO_STREAM audio_stream_io;
extern AUDIO_STREAM *g_audio_stream;


void sound_automute_set(u8 ctl, u16 packet_cnt, u16 Threshold, u8 max_cnt);
void sound_buf_init(void *cbuf, u32 cbuf_size);
u32 get_sound_cbuf_len(void);
u32 audio_read(void *buf, u32 len);
void audio_set_output_buf_limit(u32 limit_val);
u16 get_audio_stream_dac_len();

void ad2da_init(void);
s32 ad2da_write(u8 *buf, u32 len);
s32 ad2da_read(u8 *buf, u32 len);
void set_sys_vol(u32 l_vol, u32 r_vol, u8 fade_en);

#endif

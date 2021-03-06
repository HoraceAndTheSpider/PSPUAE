 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Prototypes for general sound related functions
  * This use to be called sound.h, but that causes confusion
  *
  * Copyright 1997 Bernd Schmidt
  */

extern int sound_available;

extern void (*sample_handler) (void);
/* sample_evtime is in normal Amiga cycles; scaled_sample_evtime is in our
   event cycles.  scaled_sample_evtime_ok is set to 1 by init_sound if the
   port understands scaled_sample_evtime and set it to something sensible.  */
extern unsigned long sample_evtime, scaled_sample_evtime;
extern int scaled_sample_evtime_ok;

/* Determine if we can produce any sound at all.  This can be only a guess;
 * if unsure, say yes.  Any call to init_sound may change the value.  */
extern int setup_sound (void);

extern int init_sound (void);
extern void close_sound (void);

extern void update_sound (int freq);
extern void pause_sound (void);
extern void resume_sound (void);
extern void reset_sound (void);
extern void sound_volume (int dir);

extern void switch_audio_interpol (void);

extern void sample16s_handler (void);

#ifdef MULTIPLICATION_PROFITABLE
STATIC_INLINE void init_sound_table16 (void) { }
STATIC_INLINE void init_sound_table8  (void) { }
#else
extern void init_sound_table16 (void);
extern void init_sound_table8 (void);
#endif

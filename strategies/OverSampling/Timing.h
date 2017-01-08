
/* PJON OverSampling strategy Transmission Timing table
   Copyright (c) 2017, Giovanni Blu Mitolo All rights reserved.

   All benchmarks should be executed with NetworkAnalysis and SpeedTest examples.

   The following constants setup is quite conservative and determined only
   with a huge amount of time and blind testing (without oscilloscope)
   tweaking values and analysing results. Theese can be changed to obtain
   faster speed. Probably you need experience, time and an oscilloscope. */

#if defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
  #if _OS_MODE == _STXRX882_STANDARD
    #if F_CPU == 16000000L
      #define OS_BIT_WIDTH   512
      #define OS_BIT_SPACER  328
    #endif
  #endif
#endif

#ifndef OS_BIT_WIDTH
  #define OS_BIT_WIDTH       512
#endif

#ifndef OS_BIT_SPACER
  #define OS_BIT_SPACER      328
#endif

/* The default response timeout setup dedicates the transmission time of 1 byte plus
  1 millisecond to latency and CRC computation. If receiver needs more than
  OS_TIMEOUT to compute CRC and answer back ACK, transmitter will not receive
  the incoming synchronous ACK, Higher or lower if necessary! */

#ifndef OS_LATENCY
 #define OS_LATENCY         4000
#endif

#define OS_TIMEOUT ((OS_BIT_WIDTH * 9) + OS_BIT_SPACER + OS_LATENCY)

/* Maximum initial delay in milliseconds: */

#ifndef OS_INITIAL_DELAY
  #define OS_INITIAL_DELAY  1000
#endif

/* Maximum delay in case of collision in microseconds: */

#ifndef OS_COLLISION_DELAY
  #define OS_COLLISION_DELAY 328
#endif

/* Time necessary for receiver to recover its gain: */

#ifndef OS_GAIN_REFRESH_DELAY
  #define OS_GAIN_REFRESH_DELAY 100
#endif

/* Maximum transmission attempts */

#ifndef OS_MAX_ATTEMPTS
  #define OS_MAX_ATTEMPTS    10
#endif

/* Back-off exponential degree */

#ifndef OS_BACK_OFF_DEGREE
  #define OS_BACK_OFF_DEGREE 5
#endif

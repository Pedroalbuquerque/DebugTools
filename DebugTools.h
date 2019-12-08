
//  *****  This Macros allow to direct debug and message output eitheir to Serial port or telnet (used for ESP826 and similar)
//
//  be aware that when using arduino boards like moteino, floats do not print with sprinf, so this method wont work
// floats will have to be converted to string usinf dtostrf() before using this output macro
//
// for ESPxx board this is not a problem as the .printf() implement the output of floats (nice!!)

#ifndef DEBUGTOOLS_H
#define DEBUGTOOLS_H

#if defined(DEBUG_PORT) || defined(ECHO_PORT)
  #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega328P__)
    char buf[200];
  #endif
#endif

#if defined(DEBUG_PORT)

    #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO) || defined(__AVR_ATmega1284P__)  || defined(__AVR_ATmega328P__)
      #define DEBUG_MSG(...) sprintf( buf,__VA_ARGS__ );DEBUG_PORT.print(buf);
    #else
      #define DEBUG_MSG(...) DEBUG_PORT.printf( __VA_ARGS__ );
    #endif
#else
    #define DEBUG_MSG(...)
#endif

#ifdef ECHO_PORT

  #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO) || defined(__AVR_ATmega1284P__)  || defined(__AVR_ATmega328P__)
    #define ECHO_MSG(...) sprintf( buf,__VA_ARGS__ );ECHO_PORT.print(buf);
  #else
    #define ECHO_MSG(...) ECHO_PORT.printf( __VA_ARGS__ );
  #endif
#else
  #define ECHO_MSG(...)
#endif

#endif

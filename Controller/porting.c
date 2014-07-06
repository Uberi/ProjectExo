#define ARDUINO 0
#define PIC18F 1
#ifndef PLATFORM
#define PLATFORM PIC18F
#endif

// Arduino with Arduino IDE
#if PLATFORM == ARDUINO
#include "Arduino.h"

#define microseconds() micros()
#endif

// PIC18F with MikroC Pro for PIC
#if PLATFORM == PIC18F
//wip: ANSI math library
#endif

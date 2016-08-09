/* 
 * File:   main.h
 * Author: ReadOnly
 *
 * Created on August 1, 2016, 3:25 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <stdbool.h>
#include <stdlib.h>
#include <pic18.h>
#include <htc.h>
#include <pic18f4620.h>
#include "GPIO.h"
#include "config.h"
#include "Timers.h"
#include "ADC.h"
#include "menu.h"

extern char display_ram[6];
extern char array1[6];
extern char display_ram[6];
extern const char seg_data[6];
extern const char opened[6];
extern const char SHORT[5];
extern const char rtn[6];
extern const char adjust[6];

extern char decimal,decimal4,blink_all,blink_2,blink_4;
extern int high_HTP,high_LTP,low_HTP,low_LTP;

void delay(long x);
int division(unsigned long x);
#endif	/* MAIN_H */


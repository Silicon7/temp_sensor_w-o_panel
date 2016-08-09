#include "main.h"

void TIMER2_config(void)
{
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.TOUTPS = 5;
    
    PR2 = 210;
    TMR2 = 0;
    
    PIE1bits.TMR2IE = 1;
    IPR1bits.TMR2IP = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.PEIE = 1;
    T2CONbits.TMR2ON = 1;
}


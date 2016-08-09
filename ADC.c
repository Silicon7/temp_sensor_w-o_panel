#include "main.h"

void ADC_config(void)
{
    ADCON2bits.ADCS = 6;
    ADCON2bits.ACQT = 6;
    ADCON2bits.ADFM = 1;
    
    ADCON1bits.PCFG = 0xC;
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    
    ADCON0bits.CHS0 = 0;
    ADCON0bits.CHS1 = 1;
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS3 = 0;
            
    ADCON0bits.ADON = 1;
    
    PIE1bits.ADIE = 1;
    IPR1bits.ADIP = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.PEIE = 1;
    RCONbits.IPEN = 0;
    
    ADCON0bits.GO = 1;
    
}

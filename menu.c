#include "main.h"
static char press_up=1 , panel_state=-1 , press_enter=1, press_down=1,press_esc=1;
char menu=0,flag=1;
//static char blink_all=0,blink_2,blink_4;
void control_panel(void)
{
    int i;
    if(PORTAbits.RA3 == 0 || menu)
    {
        delay(100);
        if(PORTAbits.RA3 == 0)
        {
            flag = 0;
            menu = 1;
            if(press_enter)
                panel_state++;
            panel_state = panel_state%5;
            press_enter = 0;

            if(panel_state == 0)
            {
                for(i=0;i<6;i++)
                    display_ram[i] = adjust[i];
                decimal = 0;decimal4 = 0;
            }
            else if(panel_state == 1)
            {
                display_ram[0] = 18;
                display_ram[1] = 18;
                division(high_HTP);
                for(i=2;i<6;i++)
                    display_ram[i] = array1[i];
                decimal = 0;decimal4 = 1;
            }
            else if(panel_state == 2)
            {
                display_ram[0] = 18;
                display_ram[1] = 19;
                division(high_LTP);
                for(i=2;i<6;i++)
                    display_ram[i] = array1[i];
                decimal = 0;decimal4 = 1;
            }

            else if(panel_state == 3)
            {
                display_ram[0] = 19;
                display_ram[1] = 18;
                division(low_HTP);
                for(i=2;i<6;i++)
                    display_ram[i] = array1[i];
                decimal = 0;decimal4 = 1;
            }

            else if(panel_state == 4)
            {
                display_ram[0] = 19;
                display_ram[1] = 19;
                division(low_LTP);
                for(i=2;i<6;i++)
                    display_ram[i] = array1[i];
                decimal = 0;decimal4 = 1;
            }
        }
        else
            press_enter = 1;
        
        
        if(!PORTAbits.RA5)
        {
            delay(100);
            if(!PORTAbits.RA5)
            {

                if(press_up)
                    switch(panel_state)
                    {
                        case 1:
                            high_HTP++;
                            display_ram[0] = 18;
                            display_ram[1] = 18;
                            division(high_HTP);
                            for(i=2;i<6;i++)
                                display_ram[i] = array1[i];
                            decimal = 0;decimal4 = 1;
                            break;
                        case 2:
                            high_LTP++;
                            display_ram[0] = 18;
                            display_ram[1] = 19;
                            division(high_LTP);
                            for(i=2;i<6;i++)
                                display_ram[i] = array1[i];
                            decimal = 0;decimal4 = 1;
                            break;
                        case 3:
                            low_HTP++;
                            display_ram[0] = 19;
                            display_ram[1] = 18;
                            division(low_HTP);
                            for(i=2;i<6;i++)
                                display_ram[i] = array1[i];
                            decimal = 0;decimal4 = 1;
                            
                            break;
                        case 4:
                            low_LTP++;
                            display_ram[0] = 19;
                            display_ram[1] = 19;
                            division(low_LTP);
                            for(i=2;i<6;i++)
                                display_ram[i] = array1[i];
                            decimal = 0;
                            decimal4 = 1;
                            
                            break;

                    }
                press_up = 0;
            }
        }
        else
            press_up = 1;
        
        if(PORTEbits.RE0 == 0)
        {
            delay(100);
            if(PORTEbits.RE0 == 0 && press_down)
            {
                press_down = 0;
                switch(panel_state)
                {
                    case 1:
                        high_HTP--;
                        display_ram[0] = 18;
                        display_ram[1] = 18;
                        division(high_HTP);
                        for(i=2;i<6;i++)
                            display_ram[i] = array1[i];
                        decimal = 0;decimal4 = 1;
                        
                        break;
                    case 2:
                        high_LTP--;
                        display_ram[0] = 18;
                        display_ram[1] = 19;
                        division(high_LTP);
                        for(i=2;i<6;i++)
                            display_ram[i] = array1[i];
                        decimal = 0;decimal4 = 1;
                        
                        break;
                    case 3:
                        low_HTP--;
                        display_ram[0] = 19;
                        display_ram[1] = 18;
                        division(low_HTP);
                        for(i=2;i<6;i++)
                            display_ram[i] = array1[i];
                        decimal = 0;decimal4 = 1;
                        
                        break;
                    case 4:
                        low_LTP--;
                        display_ram[0] = 19;
                        display_ram[1] = 19;
                        division(low_LTP);
                        for(i=2;i<6;i++)
                            display_ram[i] = array1[i];
                        decimal = 0;
                        decimal4 = 1;
                        
                        break;
                }
            }
        }
        else
            press_down = 1;
        
        
        if(PORTAbits.RA4 == 0)
        {    
            delay(100);
            if(PORTAbits.RA4 == 0)
            {
                flag = 1;
                menu = 0;
                panel_state = -1;
                for(i=0;i<6;i++)
                display_ram[i] = rtn[i];
                decimal4 = 0; decimal = 0;
                delay(100);
            }
        }

    }
}
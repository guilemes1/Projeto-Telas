/*
 * File:   main.c
 * Author: 20185189
 *
 * Created on 14 de Maio de 2021, 16:18
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"

#include "dispLCD4vias.h"

void main(void) 
{
    char estado = 0;
    char tecla;
    dispLCD_init();
    teclado_init();
    
    while (1)
    {
        tecla = teclado();
        
        switch( estado )
        {        
            case 0: estado = 1;
                    break;
                        
            case 1: dispLCD(0,0,"    WELCOME     ");
                    delay(3000);
                    dispLCD_clr();
                    estado = 10;
                    break;
                    
            case 10: dispLCD(0,0," TeRtoS PrOjEcT ");    
                     delay(3000);
                     dispLCD_clr();
                     estado = 15;
                     break;
                     
            case 15: dispLCD(0,0,"1: Operacao     ");  
                     dispLCD(1,0,"C: Configuracao ");
                     if(tecla == '1')
                     {  
                         dispLCD_clr();
                         estado = 20;
                     }    
                     if(tecla == 'C')
                     {    
                         dispLCD_clr();
                         estado = 100;
                     } 
                     break;        
                     
            case 20: dispLCD(0,0,"Operando...     ");
                     if(tecla == '*')
                         estado = 15;
                     break;
                     
            case 100: dispLCD(0,0,"Configurando... ");
                      if(tecla == '*')
                         estado = 15;
                      break;         
            
                
                     
            
        }        
    }    
    
    
    
    return;
}

#include "kpad.h"
#include "delay.h"
#include "mkl25z.h"
#include "mbed.h"


char col [4] {4,5,6,7};
char fil [4] {0,1,2,3};
char KPad [4][4]{
   {"1" , "2" , "3" , "A"},
   {"4" , "5" , "6" , "B"},
   {"7" , "8" , "9" , "C"},
   {"*" , "0" , "#" , "D"}
};
uint8_t i;
uint8_t j;
uint8_t est;

    kpadSetup(){
        SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
        for (j = 0; j < 4; j++) PORTA->PDR[col[j]]=PORTA_PCR_MUX(0)|PORT_PCR_PS_MASK;
        for (i = 0; i < 4; i++) PORTA->PDR[fil[i]]=PORTA_PCR_MUX(1)|PORT_PCR_PS_MASK;
        for(i = 0; i < 4; i++) PTA->PDOR|=(1u<<fil);
    }    

    kpadRead(){
        for (i = 0; i < 4; i++){
                PTA->PCOR|=(1u<<fil[i]);
            for(j = 0; j < 4; j++){
            est=PTA->PDIR|=(col[j]);
                if (est==0u){
                    PTA->PDOR|=(1u<<fil[i]);
                    return KPad[i][j];
                    }
                    else PTA->PDOR|=(1u<<fil[i]);
            }
        }
        return "O";
        
    }

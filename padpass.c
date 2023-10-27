#include "kpad.h"
#include "delay.h"
#include "mkl25z.h"
#include "mbed.h"

    uint8_t i, flag[4];
    char ChPress = 0, pass[4]{6,8,7,4}, NumSet[4];
    kpadSetup();
    while(true){
        ChPress = kpadRead();
        if(!ChPress = "O"){
            for(i = 0; i < 4; i++){
            NumSet[i] = kpadRead();
        }   
            for(i = 0; i < 4; i++){
            if(NumSet[i]==pass[i]) flag[i]==1; else flag[i]==0;
        }   
            if(flag[0]&&flag[1]&&flag[2]&&flag[3]==1) printf("Access granted"); else printf("Access denied!");
    }
}    
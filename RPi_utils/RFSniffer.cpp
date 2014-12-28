/*
  RF_Sniffer
  
  Hacked from http://code.google.com/p/rc-switch/
  
  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
     
     
RCSwitch mySwitch;
 
void byte_to_str(char *str,int x)
{
   int n;
   for(n=0; n<8;n++ )
   {
      if((x & 0x80) !=0)
      {
         str[n] = '1';
      }
      else
      {
         str[n] = '0';
      }
    //  if(n==3)
    //     str[n] = ' '; // space between nybbles
         
      x = x<<1;
   }
   str[n] = '\0';
}
void int16_to_str(char* str,int x)
{
   int hi, lo;
   hi=(x>>8) & 0xff;
   lo=x&0xff;
   byte_to_str(str,hi);
   byte_to_str(&str[9],lo);
}


int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 15 ;
     
     if(wiringPiSetup() == -1)
       return 0;

     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on inerrupt 0 => that is pin #2
     
 //    char str[18];
     int fob_id, button_id;

     while(1) {
  
      if (mySwitch.available()) {
    
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
          printf("Unknown encoding");
        } else {    
          fob_id = (value >> 4);
          button_id=value&0x0f;
 //        int16_to_str(str,value);
 //         value = mySwitch.getReceivedValue();
          printf("%i %i\n", fob_id,button_id);
        }
    
        mySwitch.resetAvailable();
    
      }
      
  
  }

  exit(0);


}


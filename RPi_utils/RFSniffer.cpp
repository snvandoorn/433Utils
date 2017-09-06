/*
  RF_Sniffer
  
  Hacked from http://code.google.com/p/rc-switch/
  
  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
     
     
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

void error(char *msg) {
    perror(msg);
    exit(0);
}
void sendData( int sockfd, char *buffer ) {
  int n;

  if ( (n = write( sockfd, buffer, strlen(buffer) ) ) < 0 )
      error( const_cast<char *>( "ERROR writing to socket") );
  buffer[0] = '\0';
}
int getData( int sockfd ) {
  char buffer[32];
  int n;

  if ( (n = read(sockfd,buffer,31) ) < 0 )
       error( const_cast<char *>( "ERROR reading from socket") );
  buffer[n] = '\0';
  return atoi( buffer );
}

<<<<<<< HEAD
static int sockfd, portno = 51717;
static int standalone = 0;
void receive_callback(int value) 
{
   int fob_id, button_id;
   char str[64]; 
    
        if (value == 0) {
          printf("Unknown encoding");
        } else {    
          fob_id = (value >> 4);
          button_id=value&0x0f;
          sprintf(str,"%i %i\n", fob_id,button_id);
          printf("sending command %s\n",str);
          if(!standalone)
            sendData(sockfd,str);
        }
}
      
  

int main(int argc, char *argv[]) {
  
=======

int main(int argc, char *argv[]) {
  
    int sockfd, portno = 51717, n;
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b
    char serverIp[] = "127.0.0.1";
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    int data;

<<<<<<< HEAD
    if( argc > 1) 
      portno = atoi(argv[1]);
    if(portno==0) {
        if(!strcmp(argv[1],"-s")) {
          printf("Running standalone");
          standalone = 1;
        }else{
          error( const_cast<char *>( "Usage: RFSniffer [-s|<portno]") );
        }
    }

  //--- set up data connection
    if(!standalone) {
=======
  //--- set up data connection
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b
    if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 )
        error( const_cast<char *>( "ERROR opening socket") );

    if ( ( server = gethostbyname( serverIp ) ) == NULL ) 
        error( const_cast<char *>("ERROR, no such host\n") );
    
    bzero( (char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy( (char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if ( connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error( const_cast<char *>( "ERROR connecting") );
<<<<<<< HEAD
    }
=======
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b


     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 15 ;
     
     if(wiringPiSetup() == -1)
       return 0;

     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on inerrupt 0 => that is pin #2
<<<<<<< HEAD
     mySwitch.setReceiveCallback(receive_callback);
=======
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b
     
     char str[18];
     int fob_id, button_id;

     while(1) {
<<<<<<< HEAD
      if(standalone) 
        printf("Waiting for commands\n");
      sleep(10);
=======
  
      if (mySwitch.available()) {
    
        printf("Waiting for commands\n");
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
          printf("Unknown encoding");
        } else {    
          fob_id = (value >> 4);
          button_id=value&0x0f;
 //        int16_to_str(str,value);
 //         value = mySwitch.getReceivedValue();
          sprintf(str,"%i %i", fob_id,button_id);
          printf("sending command %s\n",str);
       //   fflush(stdout);
          sendData(sockfd,str);
        }
    
        mySwitch.resetAvailable();
    
      }
      
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b
  
  }

  exit(0);


}


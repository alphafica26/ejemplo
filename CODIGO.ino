/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include <SD.h>                      // need to include the SD library
#include <Servo.h>
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...

TMRpcm tmrpcm;   

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int estado1,estado2,estado3;
int x,y;
int pos = 0;    // variable to store the servo position
int entrada1=A5;
int entrada2=A6;
int entrada3=A7;

void setup() {
 
  servo.attach(8);  // attaches the servo on pin 9 to the servo object
  
  pinMode(entrada1,INPUT);
  pinMode(entrada2,INPUT);
  pinMode(entrada3,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  x=0;
  y=0;

  //tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
  //if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  //return;   // don't do anything more if not
  //}
  //tmrpcm.volume(1);
  //tmrpcm.play("11.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
  
}

void loop() {

//------------------------------------------------------------------------------------------
// Funciones de Servo
//------------------------------------------------------------------------------------------

  estado1  = analogRead(entrada1);
  
  if(estado1<512){
    x=1;
  }

  while(x==1){

      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      }

      estado1 = analogRead(entrada1);
      
      if(estado1<512 && x==1){
      x=0;
      }
    }
   delay(250);
    

//------------------------------------------------------------------------------------------
// Secuencia de luces
//------------------------------------------------------------------------------------------

   estado2  = analogRead(entrada2);
   
   if(estado2<512){
     y=1;
   }

   while(y==1){   

      digitalWrite(2, HIGH);  // sets the LED on
      digitalWrite(3, LOW);   // sets the LED off
      digitalWrite(5, LOW);   // sets the LED off
      digitalWrite(6, LOW);   // sets the LED off
      digitalWrite(7, LOW);   // sets the LED off
      
      delay(500);            // waits for a second
      
      digitalWrite(2, LOW);  // sets the LED off
      digitalWrite(3, HIGH);   // sets the LED on
      digitalWrite(5, LOW);   // sets the LED off
      digitalWrite(6, LOW);   // sets the LED off
      digitalWrite(7, LOW);   // sets the LED off

      delay(500);            // waits for a second
      
      digitalWrite(2, LOW);  // sets the LED off
      digitalWrite(3, LOW);   // sets the LED off
      digitalWrite(5, HIGH);   // sets the LED on
      digitalWrite(6, LOW);   // sets the LED off
      digitalWrite(7, LOW);   // sets the LED off

      delay(500);            // waits for a second
      
      digitalWrite(2, LOW);  // sets the LED off
      digitalWrite(3, LOW);   // sets the LED off
      digitalWrite(5, LOW);   // sets the LED off
      digitalWrite(6, HIGH);   // sets the LED on
      digitalWrite(7, LOW);   // sets the LED off

      delay(500);            // waits for a second
      
      digitalWrite(2, LOW);  // sets the LED off
      digitalWrite(3, LOW);   // sets the LED off
      digitalWrite(5, LOW);   // sets the LED off
      digitalWrite(6, LOW);   // sets the LED off
      digitalWrite(7, HIGH);   // sets the LED on

      delay(500);            // waits for a second
      
      digitalWrite(2, LOW);  // sets the LED off
      digitalWrite(3, LOW);   // sets the LED off
      digitalWrite(5, LOW);   // sets the LED off
      digitalWrite(6, LOW);   // sets the LED off
      digitalWrite(7, LOW);   // sets the LED on

      estado2 = analogRead(entrada2);
      
      if(estado2<512 && y==1){
      y=0;
      }
      
     }
      delay(250);

//------------------------------------------------------------------------------------------
// Reproducción de música
//------------------------------------------------------------------------------------------

  estado3  = analogRead(entrada3);
   
      if(estado3<512){
      tmrpcm.play("1.wav");
      delay(5000);
      tmrpcm.play("2.wav");
      delay(5000);
      tmrpcm.play("3.wav");
      delay(5000);
      tmrpcm.play("4.wav");
      delay(5000);
      tmrpcm.play("5.wav");
      delay(5000);
      tmrpcm.play("6.wav");
      delay(5000);
      tmrpcm.play("7.wav");
      delay(5000);
      tmrpcm.play("8.wav");     
      delay(5000);
      tmrpcm.play("8.wav"); 
      asm("jmp 0x0000"); 
     }
   }
    

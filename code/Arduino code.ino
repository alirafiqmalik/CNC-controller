// PROJECT IF ALI HAMZA MALIK AND ALI ASHARF

#include<Servo.h>  //including servo.h library
const int xstepPin = 3; 
const int xdirPin = 4;
const int ystepPin = 6; 
const int ydirPin = 7;
const int enablex =9;
const int enabley =10;
//Defining Arduino pins as constants

int time=500;
int x=0;
int inByte;
int pul=5; 
//Declaring variables

Servo servopin;  //Initiliazing servo as servopin

void posxstep();
void negxstep();
void posystep();
void negystep();
void serialread();   // functions for reading serial port and driving motors

void setup() {
  Serial.begin(9600);//baud rate set to 9600
  pinMode(xstepPin,OUTPUT); 
  pinMode(xdirPin,OUTPUT);
  pinMode(ystepPin,OUTPUT); 
  pinMode(ydirPin,OUTPUT); 
  pinMode(enabley,OUTPUT); 
  pinMode(enablex,OUTPUT); //Setting pins as outputs
  //setting modes of pins
  servopin.attach(11);  //attaching servo to pin 11
  servopin.write(0); //setting servo to 0 degrees

}
void loop() {
    if (Serial.available()>0){  //if input is detected
      serialread();   //run function
      }
    else {
      digitalWrite(enabley,HIGH);  //else enable pins as set high and motors are turned off
      digitalWrite(enablex,HIGH);
      }


}





void xposstep(){//turns x motor in one direction

    digitalWrite(xdirPin,HIGH); // Enables the motor to move in a particular direction
 
  for(x = 0; x < pul; x++) {
    digitalWrite(xstepPin,HIGH); 
    delayMicroseconds(time); 
    digitalWrite(xstepPin,LOW); 
    delayMicroseconds(time); 
     }
 digitalWrite(enablex,HIGH);
  }
  
void xnegstep(){//turns x motor in other direction
 
  digitalWrite(xdirPin,LOW); //Changes the rotations direction
  // Makes pul pulses 
  for(x = 0; x < pul; x++) {
    digitalWrite(xstepPin,HIGH);
    delayMicroseconds(time);
    digitalWrite(xstepPin,LOW);
    delayMicroseconds(time);
  }
 
}


void yposstep(){//turns y motor in one direction
  
    digitalWrite(ydirPin,HIGH); // Enables the motor to move in a particular direction
 
  for(x = 0; x < pul; x++) {
    digitalWrite(ystepPin,HIGH); 
    delayMicroseconds(time); 
    digitalWrite(ystepPin,LOW); 
    delayMicroseconds(time); 
  }

  }
  
void ynegstep(){//turns y motor in other direction
  
  digitalWrite(ydirPin,LOW); //Changes the rotations direction
  // Makes pul pulses
  for(x = 0; x < pul; x++) {
    digitalWrite(ystepPin,HIGH);
    delayMicroseconds(time);
    digitalWrite(ystepPin,LOW);
    delayMicroseconds(time);
  }
  
}
  

  void serialread(){  //compares serial command to conditons
    
 inByte = Serial.read();
 digitalWrite(enabley,LOW);
 digitalWrite(enablex,LOW);
    if (inByte=='r'){
         xposstep();
   
      }
    else if (inByte=='l'){
         xnegstep();
   
      }
    else if (inByte=='u'){
         yposstep();
   
      }
    else if (inByte=='d'){
         ynegstep();
   
      }

    else if (inByte=='s'){
      
       servopin.write(180);
      }
   else if (inByte=='a'){
      
       servopin.write(0);
      }
      

    else{ 
  digitalWrite(enabley,HIGH);
  digitalWrite(enablex,HIGH);
  }
  }
    
    

  














    

#include <Servo.h>
const int leftmotorf = 4;  
const int leftmotorb = 5;
const int rightmotorf= 6;
const int rightmotorb= 7;
float distance , duration;
//const int ENR = 2; use t ENR and ENB to adjust the speed 
//const int ENB = 3; 
int trigpin = A1;
int echopin = A2;
Servo my_servo;  // Servo is a class inside the Adafruit_PWMServoDriver library and we  make my_servo as the object of that class
int pot_pin=0;
int val;
void setup()
{
 my_servo.attach(9); // it tells the servo motor is attached to 9th digital pin 
 pinMode(leftmotorf,OUTPUT);
 pinMode(leftmotorb,OUTPUT);
 pinMode(rightmotorb,OUTPUT);
 pinMode(rightmotorf,OUTPUT);
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
// pinMode(ENR , OUTPUT);
// pinMode(ENB,OUTPUT);
}
void loop()
{  
  //analogWrite(ENA,255);
  //analogWrite(ENB,255);
  ultrasonic();
 if (distance > 5)
     moveforward();
 else
 {   movestop();
     movebackward();
     int distanceRight = seeRight();
     int distanceLeft = seeLeft();
     if(distanceRight>distanceLeft)
         moveright();
     else 
         moveleft();
  }
}
int  ultrasonic()
{
 digitalWrite(trigpin,LOW);//the trigpin goes to low state
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);//tigpin sends in a burst of waves for 10ms
delayMicroseconds(10);
duration = pulseIn(echopin,HIGH);// this function finds the  duration for the signal to reach reciever
distance = (34.3*duration)/2; // we are calcultating the distance travelled in cms 
return distance;
}
void moveforward()
{
digitalWrite(leftmotorf,HIGH);  
digitalWrite(leftmotorb,LOW);
digitalWrite(rightmotorf,HIGH);
digitalWrite(rightmotorb,LOW);
delayMicroseconds(500);
return 0;}
void movestop()
{
digitalWrite(leftmotorf,LOW);  
digitalWrite(leftmotorb,LOW);
digitalWrite(rightmotorf,LOW);
digitalWrite(rightmotorb,LOW);
delayMicroseconds(500); 
}
void movebackward()
{
digitalWrite(leftmotorf,LOW);  
digitalWrite(leftmotorb,HIGH);
digitalWrite(rightmotorf,LOW);
digitalWrite(rightmotorb,HIGH); 
delayMicroseconds(500);
return 0;
  }
  int seeRight()
 {
    
   my_servo.write(50);
   int a = ultrasonic();
    delayMicroseconds(500);
    return a; 
 }
 int seeLeft()
 {
  my_servo.write(130);
  int b = ultrasonic();
   delayMicroseconds(500);
  return b;
 }
 void moveright()
 {
 
digitalWrite(leftmotorf,HIGH);  
digitalWrite(leftmotorb,LOW);
digitalWrite(rightmotorf,LOW);
digitalWrite(rightmotorb,HIGH);
delayMicroseconds(500);
return 0;
 
 }
 void moveleft()
 {
digitalWrite(leftmotorf,LOW);  
digitalWrite(leftmotorb,HIGH);
digitalWrite(rightmotorf,HIGH);
digitalWrite(rightmotorb,LOW);
delayMicroseconds(500);
return 0;
}
 

/*
  Hecho por Rhem y solo por Rhem sin ayuda de la SCEIE... 
  F...
*/

#include <Servo.h>      // libreria de Servo
int ReadX=0;
int ReadY=0;
int MovX=0;
int MovY=0;
int Boton;
Servo servo1,servo2,servo3,servo4,servo5;  
int PULSOMIN = 1000;    
int PULSOMAX = 2000;    
#define PINSERVO1 2   
#define PINSERVO2 3   
#define PINSERVO3 4   
#define PINSERVO4 5   
#define PINSERVO5 6   
#define Start1 90  
#define close1 165
#define Start2 90  
#define Min2  0
#define Max2 150
#define Start3 90  
#define Min3  30
#define Max3  150
#define Start4 90 
#define Start5 130 
#define close5 0
#define Switch 10

void setup()
{
  servo1.attach(PINSERVO1, PULSOMIN, PULSOMAX);  
  servo2.attach(PINSERVO2, PULSOMIN, PULSOMAX);  
  servo3.attach(PINSERVO3, PULSOMIN, PULSOMAX);  
  servo4.attach(PINSERVO4, PULSOMIN, PULSOMAX);  
  servo5.attach(PINSERVO5, PULSOMIN, PULSOMAX);  
  servo1.write(Start1);
  servo2.write(Start2);
  servo3.write(Start3);
  servo4.write(Start4);
  servo5.write(Start5);
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(Switch,INPUT);
}

void loop()
{
  ReadX=analogRead(A0);  
  ReadY=analogRead(A1);  
  Boton=digitalRead(Switch);
  Serial.print("Eje X:");
  Serial.print(ReadX);
  Serial.print(";");
  Serial.print("Eje Y:");
  Serial.println(ReadY);
  MovX=map(ReadX,0,1023,Min3,Max3);
  servo3.write(MovX);
  MovY=map(ReadY,0,1023,Min2,Max2);
  servo2.write(MovY);
  servo4.write(abs(180-MovY));
if (!Boton==HIGH){
    servo2.write(Start2);
    servo3.write(Start3);
    servo4.write(Start4);
    delay(100);
    servo1.write(close1);
    servo5.write(close5);
    delay(300);
    servo1.write(Start1);
    servo5.write(Start5);
    delay(400);
    }
}

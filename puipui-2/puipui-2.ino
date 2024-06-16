#include<Servo.h>

#include <HCSR04.h>

Servo iil;
Servo iir;
int pinA=10;
int pinB=11;
int right=analogRead(A1);
int mid=analogRead(A3);
int left=analogRead(A2);
int i=0;

UltraSonicDistanceSensor distanceSensor(13, 12);

void setup()
{
iir.attach(pinB,500,2500);
iil.attach(pinA,500,2500);
pinMode(left,INPUT);
pinMode(right,INPUT);
pinMode(mid,INPUT);
Serial.begin(9600);
   
}

void loop()
{
int right=analogRead(A1);
int mid=analogRead(A3);
int left=analogRead(A2);
int cm=distanceSensor.measureDistanceCm();

  Serial.print(left);
  Serial.print(" ");  
  Serial.print(mid);
  Serial.print(" ");
  Serial.print(right);
  Serial.print(" ");
  Serial.println(cm);
  Serial.print(" ");

int  r=350;
int  m=150;
int  l=100;

  
if(cm<0 or cm>15){
     
  if(right<r and mid>m and left<l){
  iir.writeMicroseconds(1460);
  iil.writeMicroseconds(1530);
  Serial.println("直走");
  delay(100);
  }
 else if(right>=r and mid<m and left<l){
    iir.writeMicroseconds(1530);
    iil.writeMicroseconds(1530);
    Serial.println("右轉");
    delay(50);
  }
   else if(right<r and mid<m and left>=l){
    iir.writeMicroseconds(1470);
    iil.writeMicroseconds(1470);
    Serial.println("左轉");
    delay(80);
  }
   else if (right<r and mid>m and left>=l and i!=3){
    iir.writeMicroseconds(1460);
  iil.writeMicroseconds(1530);
  Serial.println("直走");
  delay(40);
    iir.writeMicroseconds(1000);
    iil.writeMicroseconds(1500);
    i++;
    Serial.println(i);
    Serial.println("西風");
    delay(1100);
    iir.writeMicroseconds(1540);
    iil.writeMicroseconds(1460);
    Serial.println("後退");
    delay(500);
  }
  else if (right<r and mid>m and left>=l and i==3){
    iir.writeMicroseconds(900);
    iil.writeMicroseconds(1500);
    Serial.println("v");
    delay(1700);
    
  }
 else if(right>=r and mid>m and left<l){
    iir.writeMicroseconds(1460);
  iil.writeMicroseconds(1540);
  Serial.println("直走");
  delay(40);
    iir.writeMicroseconds(1500);
    iil.writeMicroseconds(2000);
    Serial.println("東風");
    delay(1000);
    iir.writeMicroseconds(1540);
  iil.writeMicroseconds(1460);
  Serial.println("後退");
  delay(500);
  }
  else if(right<r and mid<m and left<l){
    iir.writeMicroseconds(1460);
    iil.writeMicroseconds(1530);
    Serial.println("北風");
    delay(100);
  }
  else if(right>r and mid>m and left>l){
    iir.writeMicroseconds(1460);
    iil.writeMicroseconds(1530);
    Serial.println("北風");
    delay(100);
  }
  }
else if (cm>0 and cm<15){
  Serial.println("避障");
  avoidance();
  iir.writeMicroseconds(1459);
  iil.writeMicroseconds(1530);
  Serial.println("直走");
  delay(6000);
  iir.writeMicroseconds(1500);
    iil.writeMicroseconds(2000);
    Serial.println("東風");
    delay(1000);
     iir.writeMicroseconds(1460);
  iil.writeMicroseconds(1530);
  Serial.println("直走");
  delay(6000);
}
}
void avoidance(){
  iir.writeMicroseconds(1500);
  iil.writeMicroseconds(1500);
  delay(1150);
  Serial.println("停");
  
  iir.writeMicroseconds(1530);
  iil.writeMicroseconds(1535);
  delay(1200);
  Serial.println("右");
  
   iir.writeMicroseconds(1463);
  iil.writeMicroseconds(1527);
  delay(2000);
  Serial.println("直走");
  
  iir.writeMicroseconds(1465);
  iil.writeMicroseconds(1470);
  delay(1500);
  Serial.println("左");
  
   iir.writeMicroseconds(1463);
  iil.writeMicroseconds(1527);
  delay(6000);
  Serial.println("直走");
  
  iir.writeMicroseconds(1465);
  iil.writeMicroseconds(1470);
  delay(1700);
  Serial.println("左");
  
    iir.writeMicroseconds(1463);
  iil.writeMicroseconds(1527);
  delay(2300);
  Serial.println("直走");
  
  iir.writeMicroseconds(1530);
  iil.writeMicroseconds(1535);
  delay(1200);
  Serial.println("右");
}

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0,1);
int in1= 4;
int in2= 5;
int in3= 6;
int in4= 7;

void setup() {
Bluetooth.begin(9600);

  // put your setup code here, to run once:
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
}

void loop() {
if(Bluetooth.available()){
if(Bluetooth.read()=='1'){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
if(Bluetooth.read()=='2'){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}
if(Bluetooth.read()=='3'){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}
if(Bluetooth.read()=='4'){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
}
delay(100);
}

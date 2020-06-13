// Include the Servo library 
#include <Servo.h> 
int trigPin= 8;
int echoPin = 9;
int IRsensor1= A0;//left

int IRsensor2= A1;///right
int in1=2,in2=3 ,in3=4,in4=5;
// Declare the Servo pin 
int servoPin = 7; 
long duration , dist ;
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   pinMode(IRsensor1,INPUT);
   pinMode(IRsensor2,INPUT);
   pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   pinMode(in3,OUTPUT);
   pinMode(in4,OUTPUT);
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   Serial.begin(9600);
}
void loop(){ 

   Serial.print(analogRead(IRsensor1));
   int Var1= analogRead(IRsensor1);
   Serial.print(" ");
   Serial.print(analogRead(IRsensor2));
    int Var2= analogRead(IRsensor2);
    
   digitalWrite(trigPin,LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);

   pinMode(echoPin,INPUT);
   duration= pulseIn(echoPin,HIGH);
   dist= (duration/2)*0.034;
   Serial.print("duration");
   Serial.print(dist);
   if(Var1<=80){
      Servo1.write(0);
      digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,LOW); 
     digitalWrite(in4,HIGH);
      delay(1000); 
   }
   if(Var2<=80){
      Servo1.write(180);
      digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,HIGH); 
     digitalWrite(in4,LOW);
      delay(1000); 
   }
   if(dist<=20){
    digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,HIGH); 
     digitalWrite(in4,LOW);
   }
 
   // Make servo go to 0 degrees 
   // Servo1.write(0); 
   // delay(1000); 
   // // Make servo go to 90 degrees 
   // Servo1.write(90); 
   // delay(1000); 
   // // Make servo go to 180 degrees 
   // Servo1.write(180); 
   // delay(1000); 

if(Var1>=50&&Var2>=50){
  Servo1.write(90);
}


}

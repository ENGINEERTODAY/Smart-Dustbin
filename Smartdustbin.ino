#define MQ2pin A0

float sensorValue;  //variable to store sensor value

// void setup()
// {
//   Serial.begin(9600); // sets the serial port to 9600
//   Serial.println("Gas sensor warming up!");
//   delay(20000); // allow the MQ-2 to warm up
// }

// void loop()
// {
//   sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
//   Serial.print("Sensor Value: ");
//   Serial.print(sensorValue);
  
//   if(sensorValue > 200)
//   {
//     Serial.print(" | Smoke detected!");
//   }
  
//   Serial.println("");
//   delay(2000); // wait 2s for next reading
// }
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
int led= 10;
long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(100);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    
sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  if(sensorValue < 200)
  {
    Serial.print(" | Smoke detected!");
  }
  
  Serial.println("");
  delay(100); 
if ( dist<50  ) {
//Change distance as per your need
   if(sensorValue > 200){
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
}
Serial.print(dist);
}

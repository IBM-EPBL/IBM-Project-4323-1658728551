#include <Servo.h>

#define echo 4
#define trigPin 3

int sen1Value = 0;
int sen2Value = 0;
int pir = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
  Serial.begin(9600);    
  pinMode(11, OUTPUT);
  servo_7.attach(12, 500, 2500);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
 
}

void loop()
{
  sen2Value = digitalRead(13);
  if (sen2Value == 0) 
    {
      digitalWrite(11, LOW);  
      delay(3000);  
      Serial.print("NO Motion Detected" );
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
    }
 
  if (sen2Value == 1) 
    {
      digitalWrite(11, HIGH);//npn as switch ON
      delay(3000);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      Serial.print("Motion Detected!" );
    }
  delay(300);

  
  sen1Value = 0.01723 * readUltrasonicDistance(echo,trigPin);

  if (sen1Value < 100) 
    {
      servo_7.write(90);
      Serial.print("Door Open!");
      Serial.print("\n");
 
    } 
  else 
    {
      servo_7.write(0);
      Serial.print("Door Closed!");
      Serial.print("\n");
  }
  delay(10);
}

#include "Ultrasonic.h"


Ultrasonic ultrasonic(11, 12);
#define echo  12
#define trig  11
#define buzzer 13
//#define maxdistance 180

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzzer, OUTPUT);
  }

void loop() {
int distancia = (ultrasonic.Ranging(CM));
  if (distancia <=80) {
    digitalWrite(buzzer, LOW);
    delay(600);
    digitalWrite(buzzer, HIGH);
    delay(600);
    Serial.print("distancia: ");
    Serial.print(ultrasonic.Ranging(CM));
    Serial.println("cm");
    }
  if (distancia <= 60) {
    digitalWrite(buzzer, LOW);
    delay(400);
    digitalWrite(buzzer, HIGH);
    delay(400);
    Serial.print("distancia: ");
    Serial.print(ultrasonic.Ranging(CM));
    Serial.println("cm");
  }
  if (distancia <= 20) {
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    Serial.print("distancia: ");
    Serial.print(ultrasonic.Ranging(CM));
    Serial.println("cm");
    
    } 
   else {
      digitalWrite(buzzer, LOW);
      delay(200);
      Serial.println("--Obstáculo não encontrado--");
      }
       }

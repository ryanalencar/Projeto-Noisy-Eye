const int trig = 11;
const int echo = 12;
const int buzzer = 13;

long duration;
float distance;

void setup () {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop () {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 100) {
     digitalWrite(buzzer, LOW);//noTone(buzzer);
     delay(distance*5);    //digitalWrite(buzzer, HIGH);
     digitalWrite(buzzer, HIGH); //tone(buzzer, 1000, 100);              //delay(600);
     delay(100);              //digitalWrite(buzzer, LOW);
                   //delay(600);
  }
  /*if (distance <= 20){
    noTone(buzzer);//digitalWrite(buzzer, HIGH);
    delay(distance*10);//delay(300);
    tone(buzzer, 200, 100);//digitalWrite(buzzer, LOW);
    delay(50);//delay(300);
    noTone(buzzer);
    delay(50);
  }
  */
  else {
    digitalWrite(buzzer, LOW);
  }
  delay(100);
  
}


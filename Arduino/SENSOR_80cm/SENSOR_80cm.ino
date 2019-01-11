/* Vcc conecta com 5V  
Gnd conecta com Gnd
Trigger conecta com 11
Echo conecta com 12 
Leg (+) conecta com 13
Leg (-) conecta com Gnd
*/
const int trig = 2;                                                                               
const int echo = 4;
const int buzzer = 5;

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

  if (distance <= 80) {
     noTone(buzzer);
     delay(distance*5);    //digitalWrite(buzzer, HIGH);
     tone(buzzer, 700, 100);              //delay(600);
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

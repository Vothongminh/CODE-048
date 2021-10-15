//VTM https://www.youtube.com/c/VTMVlogVoThongMinh
const int stepPin = 5;//clk+
const int dirPin = 2;//cw+
const int enPin = 8;
int on = 11;
int len = 10;
int xuong = 9;
int ssr = 12;
void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(ssr, OUTPUT);
  pinMode(on, INPUT_PULLUP);
  pinMode(len, INPUT_PULLUP);
  pinMode(xuong, INPUT_PULLUP);
  digitalWrite(enPin, LOW);
}
void loop() {
  set:
  digitalWrite(ssr, LOW);
  long bb = analogRead(A0);
  long aa = analogRead(A1);
  long cc = analogRead(A2);
  long b = map(bb,0,1023,40,200);
  long a = map(aa,0,1023,50,30000);
  long c = map(cc,0,1023,0,150);
  Serial.println(b);
  if (digitalRead(len) == LOW) {
    Serial.println("len");
    digitalWrite(enPin, LOW);
    digitalWrite(dirPin, HIGH);
    for (int x = 0; x < 50; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(b);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(b);
    }
    goto set;
  }
  ///////////////////////////////////////////////////////
  if (digitalRead(xuong) == LOW) {
    Serial.println("xuong");
    digitalWrite(enPin, LOW);
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < 50; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(b);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(b);
    }
    goto set;
  }
  ///////////////////////////////////////////////////////
  if (digitalRead(on) == LOW) {
    Serial.println("ON");
    digitalWrite(enPin, LOW);
    digitalWrite(dirPin, HIGH);
    for (int x = 0; x < a; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(b);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(b);
    }
    delay(100);
    digitalWrite(ssr, HIGH);
    delay(c);
    digitalWrite(ssr, LOW);
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < a; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(b);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(b);
    }
    goto set;
  }
}

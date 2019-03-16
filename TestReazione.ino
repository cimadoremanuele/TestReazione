int ledStart = 13;
int btnStart = 7;
int buttonstatus = 0;
int tempoLed;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnStart, INPUT);
  pinMode(ledStart, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstatus = digitalRead(btnStart);
  if (buttonstatus == HIGH)
  {
    digitalWrite(ledStart, LOW);
    tempoLed = random(1000,3000);
    delay(tempoLed);
    digitalWrite(ledStart, HIGH);
  }
  else
  {
    digitalWrite(ledStart, HIGH);
  }
}

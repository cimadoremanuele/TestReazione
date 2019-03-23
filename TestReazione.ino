#include <LiquidCrystal_I2C.h>
int btnStart;
int led1;
int button1;
int beep;
int button2;
int ledR;
int ledV;
int tempo1;
int tempo2;
int tempoLed;
int tempoBeep;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  //assegno il numero dei pin alle variabili dichiarate sopra
  btnStart = 7;
  led1 = 8;
  button1 = 9;
  beep = 10;
  button2 = 11;
  ledR = 5;
  ledV = 6;
  lcd.init();
  lcd.backlight();
  pinMode(btnStart, INPUT);
  pinMode(button1, INPUT);
  pinMode(led1,OUTPUT);
  pinMode(button2, INPUT);
  pinMode(beep, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btnStart) == HIGH)
  {
    lcd.clear();
    tempo1 = 0;
    tempo2 = 0;
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, LOW);
    ButtonClicked(tempoLed,led1);
  while (digitalRead(button1) == LOW)
  {
    tempo1++;
    delay(1);
  }
  digitalWrite(led1, LOW);
  Scrittura(tempo1, 0, 0);
  if (digitalRead(button1) == HIGH)
  {
    ButtonClicked(tempoBeep,beep);
  while (digitalRead(button2) == LOW)
  {
    tempo2++;
    delay(1);
  }
  Scrittura(tempo2,0,1);
  if (digitalRead(button2) == HIGH)
  {
    digitalWrite(beep, LOW);
  }
  }
  if(tempo1 > 500 || tempo2 > 500)
  {
    digitalWrite(ledR, HIGH);
  }
  else
  {
    digitalWrite(ledV, HIGH);
  }
  }
}
void ButtonClicked(int tempo, int output)
{
    tempo = random(2000,5000);
    delay(tempo);
    digitalWrite(output, HIGH);
}
void Scrittura(int tempo, int a, int b)
{
  lcd.setCursor(a, b);
  lcd.print(String(tempo) + "ms");
}

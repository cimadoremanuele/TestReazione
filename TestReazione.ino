#include <LiquidCrystal_I2C.h>
int ledStart;
int button1;
int led1;
int button2;
int led2;
int ledRGB;
int beep;
int tempo1;
int tempo2;
int btnStart;
int buttonstatus;
int tempoLed;
int tempoBeep;
bool finito;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  //assegno il numero dei pin alle variabili dichiarate sopra
  btnStart = 7;
  led1 = 8;
  button1 = 9;
  beep = 10;
  button2 = 11;
  lcd.init();
  lcd.backlight();
  pinMode(btnStart, INPUT);
  pinMode(button1, INPUT);
  pinMode(led1,OUTPUT);
  pinMode(button2, INPUT);
  pinMode(beep, OUTPUT);
  pinMode(ledRGB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btnStart) == HIGH)
  {
    lcd.clear();
    tempo1 = 0;
    tempo2 = 0;
    ButtonClicked(tempoLed,led1);
  while (digitalRead(button1) == LOW)
  {
    tempo1++;
    delay(1);
  }
  lcd.setCursor(0, 0);
  lcd.print(String(tempo1) + "ms");
  if (digitalRead(button1) == HIGH)
  {
    ButtonClicked(tempoBeep,beep);
  while (digitalRead(button2) == LOW)
  {
    tempo2++;
    delay(1);
  }
  lcd.setCursor(0, 1);
  lcd.print(String(tempo2) + "ms");
  if (digitalRead(button2) == HIGH)
  {
    digitalWrite(beep, LOW);
  }
  }
  }
}
void ButtonClicked(int tempo, int output)
{
    tempo = random(2000,5000);
    delay(tempo);
    digitalWrite(output, HIGH);
}

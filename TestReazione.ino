#include <LiquidCrystal_I2C.h>
//int ledStart = 13;
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

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  //assegno il numero dei pin alle variabili dichiarate sopra
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
  buttonstatus = digitalRead(btnStart);
  if (buttonstatus == HIGH)
  {
    digitalWrite(led1, LOW);
    tempoLed = random(2000,5000);
    delay(tempoLed);
    digitalWrite(led1, HIGH);
  }
  buttonstatus = digitalRead(button1);
  while(led1 == HIGH)
  {
    if (buttonstatus == HIGH)
    {
      digitalWrite(led1, LOW);
      tempoBeep = random(2000,5000);
      delay(tempoBeep);
      digitalWrite(beep, HIGH);
    }
    else
    {
      tempo1++;
      delay(1);
    }
  }
  buttonstatus = digitalRead(button2);
  while (beep == HIGH)
  {
    if (buttonstatus == HIGH)
    {
      digitalWrite(beep, LOW);
    }
    else
    {
      tempo2++;
      delay(1);
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Ciao");
}

#include <LiquidCrystal_I2C.h>
int ledStart = 13;
int button1;
int led1;
int button2;
int led2;
int ledRGB;
int btnStart = 7;
int buttonstatus = 0;
int tempoLed;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(btnStart, INPUT);
  pinMode(ledStart, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstatus = digitalRead(btnStart);
  if (buttonstatus == HIGH)
  {
    digitalWrite(ledStart, LOW);
    tempoLed = random(2000,5000);
    delay(tempoLed);
    digitalWrite(ledStart, HIGH);
  }
  lcd.setCursor(0, 0);
  lcd.print("Ciao");
}

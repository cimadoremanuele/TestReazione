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
bool errore;
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
  errore = false;
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
  lcd.setCursor(0,0);
  lcd.print("Premi il bottone");
  lcd.setCursor(0,1);
  lcd.print("blu per iniziare");
  if (digitalRead(btnStart) == HIGH)
  {
    lcd.clear();
    errore = false;
    tempo1 = 0;
    tempo2 = 0;
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, LOW);
    ButtonClicked(tempoLed,led1, button1);
    if (errore == true)
    {
      lcd.print("Stai barando,");
      lcd.setCursor(0,1);
      lcd.print("ricomincia!");
      digitalWrite(ledR, HIGH);
    }
    else
    {
      while (digitalRead(button1) == LOW)
  {
    tempo1++;
    delay(1);
  }
  digitalWrite(led1, LOW);
  Scrittura(tempo1, 0, 0, "led");
  if (digitalRead(button1) == HIGH)
  {
    ButtonClicked(tempoBeep,beep, button2);
    if (errore == true)
    {
      Errore();
    }
    else
    {
      while (digitalRead(button2) == LOW)
      {
        tempo2++;
        delay(1);
        }
        Scrittura(tempo2,0,1, "suono");
        if (digitalRead(button2) == HIGH)
        {
          digitalWrite(beep, LOW);
        }
      }
      if (errore == true)
      {
        Errore();
      }
      else if(tempo1 > 500 || tempo2 > 500)
      {
        digitalWrite(ledR, HIGH);
        delay(3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Test non");
        lcd.setCursor(0,1);
        lcd.print("superato!");
      }
      else
      {
        digitalWrite(ledV, HIGH);
        delay(3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Test superato!");
      }
    }
    }
    delay(2000);
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, LOW);
    }
}
void ButtonClicked(int tempo, int output, int button)
{
    tempo = random(2000,5000);
    int tempo1 = 0;
    while (tempo1 <= tempo)
    {
      if (digitalRead(output) == LOW && digitalRead(button) == HIGH)
      {
        errore = true;
      }
      tempo1++;
      delay(1);
    }
    if (errore != true)
    {
      digitalWrite(output, HIGH);
    }
}
void Scrittura(int tempo, int a, int b, String tipo)
{
  lcd.setCursor(a, b);
  lcd.print(tipo + ":" + String(tempo) + "ms");
}
void Errore()
{
  lcd.clear();
  lcd.print("Stai barando,");
  lcd.setCursor(0,1);
  lcd.print("ricomincia!");
  digitalWrite(ledR, HIGH);
}

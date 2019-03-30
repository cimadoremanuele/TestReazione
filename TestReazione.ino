#include <LiquidCrystal_I2C.h>
int btnStart; //bottone blu
int led1;     //led blu
int button1;  //bottone giallo
int beep;     //buzzer
int button2;  //bottone verde
int ledR;     //led RGB
int ledV;     //led RGB
int tempo1;   //tempo led
int tempo2;   //tempo buzzer
bool errore;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  //assegno il numero dei pin alle variabili dichiarate sopra
  ledR = 5;
  ledV = 6;
  btnStart = 7;
  led1 = 8;
  button1 = 9;
  beep = 10;
  button2 = 11;
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
  //frase iniziale
  lcd.setCursor(0,0);
  lcd.print("Premi il bottone");
  lcd.setCursor(0,1);
  lcd.print("blu per iniziare");
  //inizio
  if (digitalRead(btnStart) == HIGH)
  {
    //pulisco il display, azzero i tempi e spengo il led RGB
    lcd.clear();
    errore = false;
    tempo1 = 0;
    tempo2 = 0;
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, LOW);
    ButtonClicked(tempoLed,led1, button1);
    //intervengo se la persona sta barando
    if (errore == true)
    {
      Errore();
    }
    else
    {
      //calcolo il tempo di reazione
      while (digitalRead(button1) == LOW)
      {
        tempo1++;
        delay(1);
      }
      //scrivo sul display il risultato
      digitalWrite(led1, LOW);
      Scrittura(tempo1, 0, 0, "led");
      if (digitalRead(button1) == HIGH)
      {
        ButtonClicked(tempoBeep,beep, button2);
        //intervengo se la persona sta barando
        if (errore == true)
        {
          Errore();
        }
        else
        {
          //calcolo il tempo di reazione
          while (digitalRead(button2) == LOW)
          { 
            tempo2++;
            delay(1);
          }
          //scrivo sul display il risultato
          Scrittura(tempo2,0,1, "suono");
          if (digitalRead(button2) == HIGH)
          {
            digitalWrite(beep, LOW);
          }
        }
        //scrivo sul display il risultato
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
  //calcolo il tempo tra l'accensione del led e il bottone premuto
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
  //scrivo il risultato
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

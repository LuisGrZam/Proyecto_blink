#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upButton = 10;
int downButton = 9;
int selectButton = 8;
int menu = 1;
int LED = 13;
int EncenderLEDGradual();
int x=0;



// Void Setup

void setup() {
  lcd.begin(16, 2);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);

  updateMenu();
}


// Void Loop
void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }

  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(100);
    while (!digitalRead(upButton));
  }

  if (!digitalRead(selectButton)) {
    execute();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }	
}


// Actualizaciones
void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print("Encender LED");
    
      break;
    case 2:
      lcd.clear();
      lcd.print(">Apagar LED");

      break;

  }
}


// Ejecutar Casos 

void execute() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
   
  }
}


// Accion

void action1() {
  lcd.clear();
  lcd.print(">Encender LED");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
  //digitalWrite(LED, HIGH);
  //delay(500);
 
  for(x=0;x<256; x+=5){ //Este ciclo es para encender gradualmente
 analogWrite(LED,x);   //Encender LED con intensidad establecida en x
delay(70);;
 }


}
void action2() {
  lcd.clear();
  lcd.print(">Apagar LED");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
 
  
  //digitalWrite(LED, LOW);
 for(x=0;x<256; x-=5){ //Este ciclo es para apagar gradualmente
 analogWrite(LED,x);   //Encender LED con intensidad establecida en x
delay(70);
}
}



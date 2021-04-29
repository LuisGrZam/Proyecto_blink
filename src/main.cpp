#include <Arduino.h>
#define btnIN A1    //Entrada analógica (Variable global)
#define LED 10      //Salida de un LED, el 10 es el pin de salida (Variable global)

enum FunMode {
  OFF,
  BLINK1,
  BLINK2,
  BLINK3,
};

int LecturadeBoton();
int BotondeSeleccion();
int FuncionOff();
int FuncionBlink1();
int FuncionBlink2();
int FuncionBlink3();


unsigned long lastDeTime = 0;
int LstBSTD = HIGH;    //Último estado predefindo en alto
int btnSTD = 0;     //Estado presente
int funcSTD = 0;

void setup() {
  pinMode(btnIN, INPUT_PULLUP);   //Declarar entrada analógica como alto como bajo de manera indefinida
  pinMode(LED, OUTPUT);           //Declarar salida digital

  // put your setup code here, to run once:
}

void loop() {
  LecturadeBoton();
  BotondeSeleccion();
}

int LecturadeBoton(){
   int reading = digitalRead(btnIN);   //Variable local de lectura
  if(reading != LstBSTD){              //Último estado definido del boton
    if((millis()-lastDeTime) > 100){
    if(reading != btnSTD){
      btnSTD = reading;
  }
  if(btnSTD == HIGH){
    funcSTD += 1;
  }
  }
  }
LstBSTD = reading;
}

int BotondeSeleccion(){
  switch (funcSTD){
    case OFF:
    FuncionOff();
    break;
    case BLINK1:
    FuncionBlink1();  
    break;
    case BLINK2:
    FuncionBlink2();
    break;
    case BLINK3:
    FuncionBlink3();
    break;
  }
}

int FuncionOff(){
 digitalWrite(LED,LOW);
}

int FuncionBlink1(){
  delay(100);
  digitalWrite(LED,LOW);
  delay(100);
  digitalWrite(LED,HIGH);
}

int FuncionBlink2(){
    delay(50);
    digitalWrite(LED,LOW);
    delay(50);
    digitalWrite(LED,HIGH);
}

int FuncionBlink3(){
    delay(200);
    digitalWrite(LED,LOW);
    delay(200);
    digitalWrite(LED,HIGH);
    
}
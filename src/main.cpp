#include <Arduino.h>
#define btnIN A0 //Entrada analogica
#define LED 10   //Salida digital

enum funMode
{
  OFF,
  BLINK1,
  BLINK2,
  BLINK3,
  BLINK4,
  
};

int led=10;
int t=4000;//4seg  
int t1=4000;//4seg
unsigned long ta=0;
unsigned long tb=0;
bool stado=true;
void setup() {
pinMode(led,OUTPUT);
digitalWrite(led,1);
}
void loop() {
if(millis()>=t+ta&&stado==true)
{
 stado=false;
 digitalWrite(led,0);
 tb=millis();
}
if(millis()>=t1+tb&&stado==false)
{
 stado=true;
 digitalWrite(led,1);
 ta=millis();
 }
}
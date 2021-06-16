#include <nRF24L01.h> //Librería correspondiente al modulo nRF24L01
#include <RF24_config.h> //Librería correspondiente al modulo nRF24L01
#include <RF24.h> //Librería correspondiente al modulo nRF24L01


#include <SPI.h> //Librería de protocolo de comunicación serial
#include <RF24.h> //Librería correspondiente al modulo nRF24L01
#include <DHT11.h> //Librería de módulo de sensor de temperatura y humedad
#include <LiquidCrystal.h> //Libreria correspondiente a pantalla LCD
#include <Wire.h>  //Librería establece protocolo I2C/TWI

//Inicializar la librería indicando los pins de la interfaz
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7)
 
float temperature[2];
 /*Crear un objeto RF24 al que llamaremos “radio”. Los dos argumentos que se utilizan 
en la funcion son los numeros de pin que vamos a usar para CS y CE */

RF24 radio(8, 9); //Pin del Arduino conectado al pin Chip Enable (CE) y Chip Select (CS) del módulo
const uint64_t pipe = 0xE8E8F0F0E1LL; // Dirección de canal de radio única para que los 2 nodos se comuniquen
 
void setup() 
{
  Serial.begin(9600); //inicializamos el puerto serie
  lcd.begin(16, 2); // Inicia LCD 16x02 (columnas, filas)
 
  radio.begin(); //inicializamos el NRF24L01 
  radio.openReadingPipe(1, pipe);   //Abrimos el canal de Lectura
  radio.startListening(); // Este comando establece este modulo como el receptor
 
lcd.print("Proyecto Final");   //Muestra mensaje
  delay(3000);                 //Retardo 3 s
  lcd.clear();                 //Limpia pantalla
    lcd.setCursor(0, 0);       //Cursor en posición 0,0
 lcd.print("Informatica");
  lcd.setCursor(0, 1);
  lcd.print("Industrial");
  delay(3000);
   lcd.clear();
 lcd.print("Temp & Humedad");
  delay(2500);



  
  lcd.clear();
  lcd.print("Inicializando...");
  delay(2000);
}
 
void loop()
{
  if ( radio.available() )   //Si la señal transmisora esta disponible
{
  bool done = false;
  while (!done)
{
 done = radio.read(temperature, sizeof(temperature)); //Leemos los datos y guardamos en la variable temperature[]
  lcd.clear(); //limpia LCD
  delay(500);  
 
  lcd.setCursor(0, 0);         //Posición
  lcd.print("Temp");           //Imprime mensaje
  lcd.setCursor(0, 1);         //Posisción
  lcd.print("Humedad");        //Imprime mensaje
  lcd.setCursor(9, 0);         //Posición
  lcd.print(temperature[0]);   //Imprime valor de variable
  lcd.print(" C");             //Imprime simbolo ''C''
  lcd.setCursor(9, 1);         //Posición
  lcd.print(temperature[1]);   //Imprime valor de variable
  lcd.print(" %");             //Imprime simbolo ''%''
  delay(1000);                 //Retardo 1s 
}
}
 else
{
  lcd.setCursor(0, 0);       //Posición
  lcd.print("Sin señal");    //Imprime mensaje que no detecta señal
}
}
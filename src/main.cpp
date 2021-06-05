//Este es el código correspondiente al emisor 
#include <SPI.h>   //Librería de protocolo de comunicación serial
//#include <nRF24L01.h> //Librería correspondiente al módulo de antena
#include <RF24.h> //Librería correspondiente al módulo de antena
#include <DHT11.h> //Librería de módulo de sensor de temperatura y humedad
#include <Wire.h>
 
int pin = A0;   //Declaración de pin A0
DHT11 dht11(pin);
float temperature[2];
 
double Fahrenheit(double celsius) {
return ((double)(9 / 5) * celsius) + 32;
}
 
double Kelvin(double celsius) {
return celsius + 273.15;
}
 
RF24 radio(8, 9);
const uint64_t pipe = 0xE8E8F0F0E1LL;
float temp, humi;

void setup() {
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);
}
 
void loop(void)
{

dht11.read(humi, temp);
temperature[0] = temp;
temperature[1] = humi;
radio.write(temperature, sizeof(temperature));
delay (1000);
}
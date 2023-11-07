#include <DHT.h>
#define DHTTYPE DHT22
 
const int DHTPin = 6;
 
DHT dht(DHTPin, DHTTYPE);
 
void setup() 
{
   Serial.begin(9600);
   Serial.println("Probando DHT22!");
 
   dht.begin();
}
 
void loop() 
{
   delay(2000);
 
   float h = dht.readHumidity();
   float t = dht.readTemperature();
 
   if (isnan(h) || isnan(t)) 
   {
      Serial.println("No se pudo leer el sensor DHT!");
      return;
   }
    else if (h<10 ) 
   {
      Serial.println("Alerta preste atencion humedad baja");
      return;
   }
    else if (t>40) 
   {
      Serial.println("Alerta preste atencion temperatura alta");
      return;
   }


   Serial.print("Humedad: ");
   Serial.print(h);
   Serial.print(" %\t");
   Serial.print("Temperatura: ");
   Serial.print(t);
   Serial.println(" *C ");

  


}
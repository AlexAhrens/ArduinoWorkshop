// Einfügen der Bibliothek und Definition der notwendigen Parameter
#include "DHT.h"                  // Library für DHT Sensor aufgerufen
#define DHTPIN 4                  // DHT Sensor wird aus PIN 4 ausgelesen
#define DHTTYPE DHT11             // DHT Type wird auf DHT11 festgelegt
DHT dht11(DHTPIN, DHTTYPE);       // Festlegen des Sensors

// Einführung von Variablen
float temperatur = 0.00;          // Variable temperatur als Nachkommazahl mit 2 Nachkommastellen
float feuchte = 0.00;             // Variable feuchte

void setup() 
{
  dht11.begin();                  // Start des DHT11 Sensors    
  Serial.begin(9600);             // Start der Seriellen Ausgabe mit 9600 Baud-Rate
  Serial.println("DHT22 Serielle Ausgabe"); // Begrüßung beim Aufruf des seriellen Monitors
}

void loop() 
{
  float temperatur = dht11.readTemperature();     // Die Temperatur wird vom DHT22 ausgelesen, Wert in "t" schreiben
  float feuchte = dht11.readHumidity();           // Die Luftfeuchte wird vom DHT22 ausgelesen, Wert in "h" schreiben

  Serial.print("Temperatur: ");            // Ausgabe im Seriellen Monitor 
  Serial.print(temperatur);                // Ausgabe im Seriellen Monitor
  Serial.print(" *C");                     // Ausgabe im Seriellen Monitor  
  Serial.println();
  Serial.print("Luftfeuchte: ");         // Ausgabe im Seriellen Monitor
  Serial.print(feuchte);                   // Ausgabe im Seriellen Monitor
  Serial.print(" %");                    // Ausgabe im Seriellen Monitor
  Serial.println();
  delay(5000);
}

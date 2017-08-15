// Code für Praxisversuch Nummer 7: Auslesen der Temperatur und Feuchtigkeit und Anzeige auf Display
// Hier werden die Bibliotheken eingebunden
#include <Wire.h>                     // Wire Bibliothek für Kommunikation über den I2C-Bus
#include <LiquidCrystal_I2C.h>        // Vorher hinzugefügte LiquidCrystal_I2C Bibliothek einbinden für Kommunikation mit dem Display
#include "DHT.h"                      // Library für DHT Sensor aufgerufen
#define DHTPIN 4                      // DHT Sensor wird aus PIN 4 ausgelesen
#define DHTTYPE DHT11                 // DHT Type wird auf DHT11 festgelegt
DHT dht11(DHTPIN, DHTTYPE);           // Festlegen des Sensors

// Initialisierung des Displays
LiquidCrystal_I2C lcd(0x27, 16, 2);   //Display mit 16 Zeichen in 2 Zeilen, Busadresse 0x27 (Interessant wenn man mehrere Geräte über den I2C-Bus betreibt)

// Einführung der Variablen 
float temperatur = 0.00;              // Variable temperatur als Nachkommazahl mit 2 Nachkommastellen
float feuchte = 0.00;                 // Variable feuchte
    
void setup()
{
  lcd.begin();                          // LCD wird gestartet
  dht11.begin();                        // Start des DHT11 Sensors  
}

void loop()
{
  temperatur = dht11.readTemperature();   // Die Temperatur wird vom DHT22 ausgelesen, Wert in "t" schreiben
  feuchte = dht11.readHumidity();         // Die Luftfeuchte wird vom DHT22 ausgelesen, Wert in "h" schreiben
  lcd.setCursor(0,0);                     // Setze den Cursor an den Ursprung (Zeichen 0, Zeile 0) -> Oben links
  lcd.print("Temp: ");                    // Textausgabe, was zwischen den "..." steht
  lcd.print(temperatur); 
  lcd.print(" *C"); 
  lcd.setCursor(0,1);                   // lcd.setCursor um Zeichen und Zeile anzugeben
  lcd.print("Feuchte: ");               // Wir belegen 12 Zeichen
  lcd.print(feuchte);                   // Schreibt Wert von spannung auf den dafür vorgesehenen Platz
  lcd.print(" %");                      // Schreibt nach einem Leerzeichen die Einheit Volt hinter das Ergebnis  
}

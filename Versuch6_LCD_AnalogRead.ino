// Code für Praxisversuch Nummer 6: Einbindung eines I2C-Displays und Funktion AnalogRead
// Hier werden die Bibliotheken eingebunden
#include <Wire.h>                     // Wire Bibliothek für Kommunikation über den I2C-Bus
#include <LiquidCrystal_I2C.h>        // Vorher hinzugefügte LiquidCrystal_I2C Bibliothek einbinden für Kommunikation mit dem Display

// Initialisierung des Displays
LiquidCrystal_I2C lcd(0x3F, 16, 2);   //Display mit 16 Zeichen in 2 Zeilen, Busadresse 0x27 (Interessant wenn man mehrere Geräte über den I2C-Bus betreibt)

// Einführung der Variablen 
int input = 0;
float spannung = 0.0;

void setup()
{
  lcd.begin();                          // LCD wird gestartet
}

void loop()
{
  lcd.setCursor(0,0);                 // Setze den Cursor an den Ursprung (Zeichen 0, Zeile 0) -> Oben links
  lcd.print("Hello World");           // Textausgabe, was zwischen den "..." steht
  input = analogRead(A0);             // Lesen des Wertes auf Analogpin A0
  spannung = input * (5.0 / 1023.0);  // Umrechnen des gelesenen Wertes auf einen Spannungswert
  lcd.setCursor(0,1);                 // lcd.setCursor um Zeichen und Zeile anzugeben
  lcd.print("Spannung: ");            // Wir belegen 12 Zeichen
  lcd.setCursor(10,1);                // Setzt Cursor auf den Platz der Variablen spannung
  lcd.print(spannung);                // Schreibt Wert von spannung auf den dafür vorgesehenen Platz
  lcd.print(" V");                    // Schreibt nach einem Leerzeichen die Einheit Volt hinter das Ergebnis  
}

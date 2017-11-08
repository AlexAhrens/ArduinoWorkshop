// Abschluss Projekt Praxisteil Abstandsmessung Ultraschall mit Display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialisierung des Displays
LiquidCrystal_I2C lcd(0x3F, 16, 2);         //Display mit 16 Zeichen in 2 Zeilen, Busadresse 0x27
// Einführung der Variablen
int trigger=7;                              //Pin "trigger" ist angeschlossen an Pin 7
int echo=6;                                 //Pin "echo" ist angeschlossen an Pin 6
long laufzeit=0;                            //Laufzeit des Schalls, Datentyp long statt int, es können größere Zahlen gespeichert werden
long entfernung=0;                          //Für berechnung der Entfernung, int bereich -2147483648 bis 2147483647 

void setup()
{
  lcd.begin();
   pinMode(trigger, OUTPUT);                //„trigger“(Pin7) ist ein Ausgang.
   pinMode(echo, INPUT);                    //„echo“(Pin6) ist ein Eingang.
}

void loop()
{
  digitalWrite(trigger, LOW);               //Kurz Ausschalten zur Rauschreduzierung
    delay(5);                               //Dauer: 5 Millisekunden
  digitalWrite(trigger, HIGH);              //Ultraschallwelle wird gestartet
    delay(10);                              //Dauer des Aussendens der Welle
  digitalWrite(trigger, LOW);               //Ultraschallwelle wird beendet
 // Berechnung der Laufzeit
  laufzeit = pulseIn(echo, HIGH);           //pulseIn zählt Zeit bis zur detektierung der Reflektion der Schallwelle
  entfernung = (laufzeit/2) / 29.1;         // Berechnung in cm. Schall in Luft hat eine Geschwindigkeit von 29,1 cm pro ms 
                                            // Teilung durch 2 da nur eine Wegstrecke gemessen werden soll
if (entfernung >= 500 || entfernung <= 0)   //Messwertgrenze
  {
    lcd.setCursor(0,1);                     //Setzt Cursor auf die zweite Zeile für das Ergebnis
    lcd.clear();                            //Löscht alle Zeichen vom LCD für klare Anzeige
    lcd.print("Kein Messwert");             //Keine Messung möglich
  }
else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Entfernung");                //Zeigt den Einführungstext in der ersten Zeile an
    lcd.setCursor(0,1);                     //Setzt Cursor auf die zweite Zeile für das Ergebnis
    lcd.print(entfernung);                  //Ausgabe des Messwertes
    lcd.print(" cm");                       //Ausgabe der Einheit hinter dem Messwert
   }
delay(1000);                               //Pause für 1 Sekunde zur Stabilität
}

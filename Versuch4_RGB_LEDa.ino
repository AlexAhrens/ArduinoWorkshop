// Einführung von Variablen
int LEDblau = 3; // Farbe blau an Pin 3
int LEDrot = 5; // Farbe rot an Pin 5
int LEDgruen=6; // Farbe gruen an Pin 6

// Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int helligkeit1a = 150;
int helligkeit1b = 150;
int helligkeit1c = 150; 

int aus = 0; // Zahlenwert 0 bedeutet Spannung 0V – also LED aus

void setup()
{
  pinMode(LEDblau, OUTPUT);
  pinMode(LEDgruen, OUTPUT);
  pinMode(LEDrot, OUTPUT);
}

void loop()
{
  analogWrite(LEDblau, helligkeit1a);   // Blau einschalten
    delay(1000);                        // Pause 1000 Millisekunden
  analogWrite(LEDblau, aus);            // Blau ausschalten
  analogWrite(LEDrot, helligkeit1b);    // Rot einschalten
    delay(1000); 
  analogWrite(LEDrot, aus);             // Rot ausschalten   
  analogWrite(LEDgruen, helligkeit1c);  // Grün einschalten
    delay(1000);
  analogWrite(LEDgruen, aus);           // Grün ausschalten
  }

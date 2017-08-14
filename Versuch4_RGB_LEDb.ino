//Einführung von Variablen zum Mischen der Farben
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
  analogWrite(LEDgruen, helligkeit1c); // Grüen und Rot ein = Gelb
  analogWrite(LEDrot, helligkeit1b);
    delay(1000);
  analogWrite(LEDgruen, aus); // Grün und Rot aus = Gelb aus
  analogWrite(LEDrot, aus);
  analogWrite(LEDgruen, helligkeit1c); // Grün und Blau ein = Türkis
  analogWrite(LEDblau, helligkeit1b);
    delay(1000);
  analogWrite(LEDgruen, aus); // Grün und Blau aus = Türkis aus
  analogWrite(LEDblau, aus);
  analogWrite(LEDrot, helligkeit1b); // Rot und Blau ein = Lila
  analogWrite(LEDblau, helligkeit1b);
    delay(1000);
  analogWrite(LEDrot, aus); // Rot und Blau aus = Lila aus
  analogWrite(LEDblau, aus);
}

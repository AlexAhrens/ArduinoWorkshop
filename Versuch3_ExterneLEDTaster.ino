//Versuch 3 - externe LEDs per Tasterdruck Schalten
int taster = 0;                   // Variable Taster eingeführt und gleich null gesetzt. 
//Hier wird gespeichert, ob der Taster gedrückt (HIGH) oder nicht (LOW) ist

void setup() {
  // Setze Pin Digitalpin 2 und 3 als Output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}

void loop() {
  taster=digitalRead(4);           // Lesen des Statuses am PIN 4 (HIGH = 5V, LOW = 0V)
  if (taster == HIGH)              // Wenn Taster gedrückt, dann {....}
    {
      digitalWrite(3, HIGH);       // Schalte Spannung an PIN 3 ein, Grüne LED wenn Taster gedrückt
      digitalWrite(2,LOW);         // Schalte Spannung an PIN 2 aus
     }
  else                             // Wenn Taster nicht gedrückt, dann {...}
    {
      digitalWrite(2,HIGH);        // Schalte Spannung an PIN 2 ein, Rote LED immer an, außer wenn Taster gedrückt.
      digitalWrite(3,LOW);         // Schalte Spannung an PIN 3 aus
    }
  }                                // Ende Loop-Funktion

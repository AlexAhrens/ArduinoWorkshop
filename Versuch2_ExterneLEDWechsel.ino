//Versuch 2 - externe LEDs im Wechsel Blinken lassen

void setup() {
  // Setze Pin Digitalpin 2 und 3 als Output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);            // Schalte Spannung an PIN 2 ein
  digitalWrite(3, LOW);             // Schalte Spannung an PIN 3 aus
  delay(1000);                      //Programmpause 1000 Millisekunden
  digitalWrite(2, LOW);             // Schalte Spannung an PIN 2 aus
  digitalWrite(3, HIGH);            // Schalte Spannung an PIN 3 ein
  delay(1000);                      // Programmpause 1000 Millisekunden
  }

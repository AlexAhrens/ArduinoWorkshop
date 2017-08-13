//Versuch 1 - externe LED Blinken lassen

void setup() {
  // Setze Pin Digitalpin 2 als Output.
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);   // Schalte Spannung an PIN 2 ein
  delay(1000);                       //Programmpause 1000 Millisekunden
  digitalWrite(2, LOW);    // Schalte Spannung an PIN 2 aus
  delay(1000);                       // Programmpause 1000 Millisekunden

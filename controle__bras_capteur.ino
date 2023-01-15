unsigned long temp;
int posit_objet;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  lecture();
  temp = millis();
  while (posit_objet == 3) {
    lecture();
    if (millis() > temp + 2000) {
      Serial.println(posit_objet);
      digitalWrite(13, 1);
      //code qui demande au bras de prendre l'objet et deposé à un endroit précis 
      // retour du dras à l'etat initial
    }
  }
  if (posit_objet != 5) {
    digitalWrite(13, 0);
    Serial.println(posit_objet);
  }
}
void lecture() {
  posit_objet = analogRead(A0);
 posit_objet = map(posit_objet, 0, 1023, 0, 10);
}

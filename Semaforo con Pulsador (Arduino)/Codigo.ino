const int ledRojo = 8;
const int ledAmarillo = 9;
const int ledVerde = 10;
const int boton = 2;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  if (digitalRead(boton) == HIGH) {
    digitalWrite(ledVerde, HIGH);
    delay(2000);
    digitalWrite(ledVerde, LOW);
    
    digitalWrite(ledAmarillo, HIGH);
    delay(1000);
    digitalWrite(ledAmarillo, LOW);
    
    digitalWrite(ledRojo, HIGH);
    delay(2000);
    digitalWrite(ledRojo, LOW);
  }
}

int sensorPosicion = 2;
int buzzer = 8;
int boton = 12;

void setup() {
  pinMode(boton, INPUT);
  pinMode(sensorPosicion, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(boton) == HIGH) {
    Serial.println("ALARMA detenida");
    noTone(buzzer);
    
    while (digitalRead(boton) == HIGH) {
      delay(5000);
    }
    Serial.println("liberado, Reanudando programa");
  }
    
  int estadoSensor = digitalRead(sensorPosicion);

  	if (estadoSensor == LOW) {
    	tone(buzzer, 523, 100);
    	Serial.println("ALERTA: Caloventor caido");
  	} 
  	else {
    	Serial.println("Caloventor en posicion normal");
    	digitalWrite(buzzer, LOW);
  	}
  
  delay(500);
}

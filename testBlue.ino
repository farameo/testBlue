
#include <SoftwareSerial.h>

#define BT_RX 10
#define BT_TX 11
#define BTVCC 9

SoftwareSerial Bluetooth(BT_RX, BT_TX); // RX, TX

void setup() {
  Serial.begin(9600);
  pinMode(BTVCC, OUTPUT);                         // Marca el PIN de alimentacion para el HC-05 como salida
  delay (500) ;                                           // Espera antes de encender el modulo
  
  Serial.println("Alimentando el modulo HC-05");
  digitalWrite (BTVCC, HIGH);                       // Enciende el modulo

  Bluetooth.begin(9600); 
}

void loop(){
  if (Bluetooth.available()){ Serial.write(Bluetooth.read()); }
  if (Serial.available()){ Bluetooth.write(Serial.read()); }
}

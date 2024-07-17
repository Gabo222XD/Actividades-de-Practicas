/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Variables de medición e indicaciones sonoras
   Dev: Henry Francisco Leal Súchite
   Fecha: 16 de Julio
*/
#include <Wire.h>
#include <SparkFun_ADXL345.h> 
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

SoftwareSerial softSerial(10, 11); // Conexiones RX y TX del DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;
ADXL345 acelerometro_ADXL345 = ADXL345();
int x, y, z;
float Mx, My, Mz, MR;

void setup() {
  softSerial.begin(9600);
  Serial.begin(9600);

  if (!myDFPlayer.begin(softSerial)) {
    Serial.println("Error en la inicialización del DFPlayer Mini");
    while (true); // Si hay un error, detener el programa
  }
  myDFPlayer.volume(15); // Ajusta el volumen a un nivel más alto
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(8);
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
}
void loop() {
  // Leer datos del acelerómetro
  acelerometro_ADXL345.readAccel(&x, &y, &z);
  Mx = x * 0.4; 
  My = y * 0.4;
  Mz = z * 0.4;

  MR = sqrt(Mx * Mx + My * My + Mz * Mz);

  Serial.print("La magnitud resultante de la aceleracion es de: ");
  Serial.println(MR);

  int Rango = map(MR, 24, 100, 0, 9); 

  Serial.print("Rango calculado: ");
  Serial.println(Rango);

  switch (Rango) {
    case 0:
      digitalWrite(2, HIGH);
      break;
    case 1:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      apagar();
      break;
    case 2:
      for (int i = 2; i <= 4; i++) {
        digitalWrite(i, HIGH);
      }
      apagar();
      break;
    case 3:
      for (int i = 2; i <= 5; i++) {
        digitalWrite(i, HIGH);
      }
      apagar();
      break;
    case 4:
      for (int i = 2; i <= 6; i++) {
        digitalWrite(i, HIGH);
      }
      apagar();
      break;
    case 5:
      for (int i = 2; i <= 7; i++) {
        digitalWrite(i, HIGH);
      }
      apagar();
      break;
    case 6:
     myDFPlayer.play(1);
      for (int i = 2; i <= 8; i++) {
        digitalWrite(i, HIGH);
      }
      apagar();
      break;
    case 7:
    myDFPlayer.play(1);
      for (int i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      apagar(); 
      break;
    case 8:
    myDFPlayer.play(1);
      for (int i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      digitalWrite(A2, HIGH);
      apagar();
      break;
    case 9:
    myDFPlayer.play(1);
    
      for (int i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      digitalWrite(A2, HIGH);
      digitalWrite(A1, HIGH);
      apagar();
      break;
  }
}
void salidas() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
}
void apagar(){
  delay(2000);
for (int i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(A2, LOW);
  digitalWrite(A1, LOW);
}

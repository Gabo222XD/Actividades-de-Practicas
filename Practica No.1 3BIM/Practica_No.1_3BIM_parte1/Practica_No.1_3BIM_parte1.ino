/*
  
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Primera Practica III BIM
   Dev: Henry Francisco Leal Súchite
   Fecha: 20 de JUNIO
*/

#include <Adafruit_NeoPixel.h>
 
int pines[] = {5, 6, 7, 8, 9, 10, 11};
int no10[] = {11};
int no9[] = {5, 6, 7, 10, 11};
int no8[] = {5, 6, 7, 8, 9, 10, 11};
int no7[] = {5, 6, 7, 11};
int no6[] = {7, 8, 9, 10, 11};
int no5[] = {5, 10, 11, 7, 8};
int no4[] = {6, 7, 10, 11};
int no3[] = {5, 6, 7, 8, 11};
int no2[] = {5, 6, 11, 9, 8};
int no1[] = {6, 7};

#define Cantidad_Leds 1
#define pin_Led 4

int Trigger = 2;
int Echo = 3;
long Sensor;
long Distancia;
int persdetec = 0;

Adafruit_NeoPixel neopin(Cantidad_Leds, pin_Led, NEO_GRB + NEO_KHZ800);

void distancia(void);

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(2, LOW);
  salidas();
  neopin.begin();
}

void loop() {
  medicion();
  deteccion();
}

float medicion() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  Sensor = pulseIn(3, HIGH);
  Distancia = Sensor / 59;
  Serial.print("Distancia: ");
  Serial.print(Distancia);
  Serial.print("cm ");
  Serial.println();
  delay(10);
}

float deteccion() {
  if (Distancia >= 6 && Distancia <= 10) {
    Serial.print(" Persona detectada ");
    persdetec++;
/*if (persdetec >= 0 && persdetec < 9)
    {
      neopin.setPixelColor(0, 0, 255, 0); // Verde
      neopin.show();
    }*/
    switch (persdetec) {
      case 1:
        for (int i = 0; i < 2; i++) {
          digitalWrite(no1[i], HIGH);
        }
        delay(1000);
        for (int i = 1; i >= 0; i--) {
          digitalWrite(no1[i], LOW);
        }
        break;
      case 2:
        for (int i = 0; i < 5; i++) {
          digitalWrite(no2[i], HIGH);
        }
        delay(1000);
        for (int i = 4; i >= 0; i--) {
          digitalWrite(no2[i], LOW);
        }
        break;
      case 3:
        for (int i = 0; i < 5; i++) {
          digitalWrite(no3[i], HIGH);
        }
        delay(1000);
        for (int i = 4; i >= 0; i--) {
          digitalWrite(no3[i], LOW);
        }
        break;
      case 4:
        for (int i = 0; i < 4; i++) {
          digitalWrite(no4[i], HIGH);
        }
        delay(1000);
        for (int i = 3; i >= 0; i--) {
          digitalWrite(no4[i], LOW);
        }
        break;
      case 5:
        for (int i = 0; i < 5; i++) {
          digitalWrite(no5[i], HIGH);
        }
        delay(1000);
        for (int i = 4; i >= 0; i--) {
          digitalWrite(no5[i], LOW);
        }
        break;
      case 6:
        for (int i = 0; i < 5; i++) {
          digitalWrite(no6[i], HIGH);
        }
        delay(1000);
        for (int i = 4; i >= 0; i--) {
          digitalWrite(no6[i], LOW);
        }
        break;
      case 7:
        for (int i = 0; i < 4; i++) {
          digitalWrite(no7[i], HIGH);
        }
        delay(1000);
        for (int i = 3; i >= 0; i--) {
          digitalWrite(no7[i], LOW);
        }
        break;
      case 8:
        for (int i = 0; i < 7; i++) {
          digitalWrite(no8[i], HIGH);
        }
        delay(1000);
        for (int i = 6; i >= 0; i--) {
          digitalWrite(no8[i], LOW);
        }
        break;
      case 9:
        for (int i = 0; i < 5; i++) {
          digitalWrite(no9[i], HIGH);
        }
        delay(1000);
        for (int i = 4; i >= 0; i--) {
          digitalWrite(no9[i], LOW);
        }
        break;
      
    }
if (persdetec >= 0 && persdetec < 9)
    {
      neopin.setPixelColor(0, 0, 255, 0); // Verde
      neopin.show();
    }
    
     else if (persdetec >= 10 && persdetec <= 100) {
      neopin.setPixelColor(0, 255, 0, 0); // rojo
      neopin.show();
        for (int i = 0; i < 1; i++) {
          digitalWrite(no10[i], HIGH);
        }
    }
  }
}

void salidas() {
  for (int p = 0; p < 7; p++) {
    pinMode(pines[p], OUTPUT);
  }
}

/*
  
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Primera parte, Practica no.3 3BIM
   Dev: Henry Francisco Leal Súchite
   Fecha: 18 de JULIO
*/


#include <LedControl.h> 

#define din_matrix 3
#define cs_matrix 2
#define clk_matrix 4
#define potenciometro A1

LedControl Pacman_Matrix = LedControl(din_matrix, clk_matrix, cs_matrix, 1);

byte Pacman_boca_abierta[8] = { 
B00111100,
B01000010,
B10100100,
B10001000,
B10001000,
B10000100,
B01000010,
B00111100,
 };
byte Pacman_boca_CERRADA[8] = { 
B00111100,
B01000010,
B10010001,
B10000001,
B10001111,
B10000001,
B01000010,
B00111100,
 };
void setup() {
Serial.begin(9600);
Pacman_Matrix.shutdown(0, false);
Pacman_Matrix.setIntensity(0, 15);
Pacman_Matrix.clearDisplay(0);
Serial.println("Uso de la matriz led");
pinMode(potenciometro, INPUT);
}

void loop() {
    int valor_pot = analogRead(potenciometro);
    int tiempo_espera = map(valor_pot, 0, 1023, 50, 1500);
PacmanON();
delay(tiempo_espera);
PacmanOff();
delay(tiempo_espera);
Serial.println(tiempo_espera);

}
void PacmanON()
{
  for(int i=0; i<8; i++ ){
  Pacman_Matrix.setRow(0,i, Pacman_boca_abierta[i]);
}
}
void PacmanOff()
{
  for(int i=0; i<8; i++ ){
  Pacman_Matrix.setRow(0,i, Pacman_boca_CERRADA[i]);
  }
}

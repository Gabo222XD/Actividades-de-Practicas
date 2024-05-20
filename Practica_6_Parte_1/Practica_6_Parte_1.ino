/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de la pantalla LCD sin interfaz I2C
   Dev: Henry Francisco Leal Súchite
   Fecha: 20 de mayo de 2024   
*/
#include <LiquidCrystal.h>
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5


LiquidCrystal HENRYLCD(RS, Enable, D4, D5, D6, D7); 

void setup()
{
  HENRYLCD.begin(16,2);  
  HENRYLCD.setCursor(0,0);
  HENRYLCD.print("     Henry    ");
  HENRYLCD.setCursor(0,1);
  HENRYLCD.print("    2023102   "); 
}

void loop()
{

}

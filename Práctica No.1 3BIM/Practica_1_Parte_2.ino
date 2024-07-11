/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Primera Practica III BIM / segunda parte
   Dev: Henry Francisco Leal Súchite
   Fecha: 8 de Julio 2024 
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
// STEPPER
#define IN1  9
#define IN2  10
#define IN3  11
#define IN4  12
#define potenciometro A0
// SENSOR DE OBSTACULOS
#define sensor_IR 2
// SENSOR EFECTO HALL
#define HALL 3
int contador = 0;
int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
void Interrupcion() {
  contador++;
}
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas); 
bool state_sensor = false;
void setup() {
  Serial.begin(9600);  // Inicio la comunicación serial
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Contador de revoluciones");
  lcd.setCursor(0, 1);
  lcd.print("No. De Rev.       ");
  pines(); 
  attachInterrupt(digitalPinToInterrupt(HALL), Interrupcion, FALLING); 
}
void loop() {
  state_sensor = digitalRead(sensor_IR);
  if (state_sensor == LOW) {
   int valor_pot = analogRead(potenciometro);  // Lee el valor del potenciómetro (0-1023)
   int tiempo_espera = map(valor_pot, 0, 1023, 0, 3);  // Ajusta los valores mínimo y máximo según la velocidad deseada
   for (int i = 0; i < 8; i++) {
    digitalWrite(IN1, paso[i][0]);
    digitalWrite(IN2, paso[i][1]);
    digitalWrite(IN3, paso[i][2]);
    digitalWrite(IN4, paso[i][3]);
    delay(tiempo_espera);  // Utiliza delay para tiempos de espera
   }
    rpm(); 
  } else{
    contador = 0;
    lcd.setCursor(12, 1);
    lcd.print("   "); 
  }
}
void rpm() {
  attachInterrupt(digitalPinToInterrupt(HALL), Interrupcion, FALLING);
lcd.setCursor(12, 1);
  lcd.print(contador);    
 state_sensor = digitalRead(sensor_IR);
}
void pines(){
   pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(sensor_IR, INPUT);
  pinMode(HALL, INPUT);
}
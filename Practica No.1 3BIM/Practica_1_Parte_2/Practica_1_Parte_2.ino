/*
  
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Segunda Practica III BIM
   Dev: Henry Francisco Leal Súchite
   Fecha: 12 de JULIO
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
 
#define IN1  9
#define IN2  10
#define IN3  11
#define IN4  12
#define potenciometro A0
#define sensor_IR 2
#define HALL 3
 
unsigned long contadorRevoluciones = 0;
unsigned long ultimaMedicion = 0;
volatile bool hallInterruptFlag = false;
 
int paso[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
 
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);
 
void Interrupcion() {
  contadorRevoluciones++;
  hallInterruptFlag = true;
}
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Contador de revoluciones");
  lcd.setCursor(0, 1);
  lcd.print("RPM:       ");
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(sensor_IR, INPUT);
  pinMode(HALL, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(HALL), Interrupcion, FALLING);
}
void loop() {
  bool state_sensor = digitalRead(sensor_IR);
  if (state_sensor == LOW) {
    int valor_pot = analogRead(potenciometro);
    int tiempo_espera = map(valor_pot, 0, 1023, 0, 3);
    for (int i = 0; i < 8; i++) {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(tiempo_espera);
    }
  }
  if (hallInterruptFlag && millis() - ultimaMedicion >= 1000) {
    noInterrupts(); 
    unsigned long revoluciones = contadorRevoluciones;
    contadorRevoluciones = 0;
    interrupts(); 
    unsigned long tiempoTranscurrido = millis() - ultimaMedicion;
    ultimaMedicion = millis();
    float rpm = (revoluciones * 60000.0) / tiempoTranscurrido;
    lcd.setCursor(12, 1);
    lcd.print("   ");
    hallInterruptFlag = false;
    delay(1000);
    lcd.setCursor(5, 1); 
    lcd.print("0.0");    
    lcd.print("   ");
  }
}
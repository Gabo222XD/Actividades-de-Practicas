/*
  
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto final Segundo Bimestre
   Dev: Henry Francisco Leal Súchite
   Fecha: 25 de mayo
*/

//Librerias
#include <Keypad.h>             //Libreria que me permite usar el teclado matricial
#include <Servo.h> //libreria que me permite usar el servo
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
//Directivas de preprocesador para la LCD
#define direccion_lcd 0x27     //Sla_add pantalla LCD
#define filas 2                //Cantidad de filas que posee la pantalla LCD
#define columnas 16            //Cantidad de columnas que posee la pantalla LCD 
//Macros o directivas de preprocesador
#define filas_teclado 4   //cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4 //cantidad de columnas que posee el teclado matricial.
#define f1_teclado 6  //pin2 conectado a la fila 1
#define f2_teclado 5  //pin3 conectado a la fila 2
#define f3_teclado 0  //pin4 conectado a la fila 3
#define f4_teclado 0  //pin5 conectado a la fila 4
#define c1_teclado 4  //pin6 conectado a la columna 1
#define c2_teclado 3  //pin7 conectado a la columna 2
#define c3_teclado 2  //pin8 conectado a la columna 3
#define c4_teclado 0  //pin9 conectado a la columna 4
#define A 7
#define C 8
#define D 9
#define F 10
#define G 11
#define pin_Servo 12
// secuencia para luces autofantastico
int pines[] = {A0, A1, A2, A3}; 
int tiempo = 0;


//Creo una matriz led con la disposicion fisica de las teclas
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};

Keypad teclado_Leal = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);   //teclado matricial 4x4 conectado al arduino por diversos pines
Servo Servo_leal;  //mi servo


LiquidCrystal_I2C lcdleal(direccion_lcd, columnas, filas); 


void setup(){
  Serial.begin(9600);             
  Servo_leal.attach(pin_Servo);   // servo 
  lcdleal.init();                 // modulo i2c
  lcdleal.backlight();            // luz de lcd
  lcdleal.print("     HENRY     ");
  lcdleal.setCursor(0,1);
  lcdleal.print(" Proyecto Final");
  for (int b = 0; b < 4; b++) { //for de luces
  pinMode(pines[b], OUTPUT);}
}

void loop(){   
  char tecla = teclado_Leal.getKey();  //Obtengo la tecla que presione
  if(tecla){
    Serial.print("La tecla presionada es: ");   
    Serial.println(tecla);    
  }
  if(tecla == '1'){ // if de teca 1
    Serial.println("contador 0 a 99"); // inincia cotador de 0 a 99
    for(int i=0; i<100;i++){
    Serial.println(i);
    delay(50);}
    } 
  if(tecla == '2'){ // if de tecla  2
    Serial.println("contador 99 a 0"); // inicia contador de 99 a 00
    for(int i=99; i>-1; i--){
    Serial.println(i);
    delay(50);}
    }  
      
  if (tecla == '3') { //if de tecla 3
    tiempo = 250;
    Serial.println("Luces de auto fantastico");
     for (int b = 0; b<3 ; b++) { // secuencia de ida
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);
    }
    for (int b = 3; b>=0 ; b--) { // secuencia de vuelta
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);}
    
    for (int b = 0; b < 4; b++) { //enciende todas las leds
    digitalWrite(pines[b], HIGH);}
    delay(tiempo);
    for (int b = 0; b < 4; b++) { // se apagan todas las leds
    digitalWrite(pines[b], LOW);}
    delay(tiempo);}
 
  
    if(tecla == '4'){ // if de tecla 4
    Serial.println("secuencia en Display"); // secuencia en display de 7 segmentos
    digitalWrite( A, HIGH);
    delay(250);
    digitalWrite( A, LOW);
    digitalWrite( F, HIGH);
    delay(250);
    digitalWrite( F, LOW);
    digitalWrite( G, HIGH);
    delay(250);
    digitalWrite( G, LOW);
    digitalWrite( C, HIGH);
    delay(250);
    digitalWrite( C, LOW);
    digitalWrite( D, HIGH);
    delay(250);
    digitalWrite( D, LOW);      
    digitalWrite( D, HIGH);
    delay(250);
    digitalWrite( D, LOW);       
    digitalWrite( C, HIGH);
    delay(250);
    digitalWrite( C, LOW);     
    digitalWrite( G, HIGH);
    delay(250);
    digitalWrite( G, LOW);     
    digitalWrite( F, HIGH);
    delay(250);
    digitalWrite( F, LOW);  
    digitalWrite( A, HIGH);
    delay(250);
    digitalWrite( A, LOW);
      digitalWrite( A, HIGH);
      digitalWrite( F, HIGH);
      digitalWrite( G, HIGH);
      digitalWrite( C, HIGH);
      digitalWrite( D, HIGH);
      delay(250);
      digitalWrite( A, LOW);
      digitalWrite( F, LOW);
      digitalWrite( G,LOW);
      digitalWrite( C, LOW);
      digitalWrite( D, LOW);
    }
      if(tecla == '5'){ // if de tecla 5
       Serial.println("Inicio de servo"); // giro de servo
      Servo_leal.write(0);
      delay(3000);
      Servo_leal.write(180);
      delay(3000);
      Servo_leal.write(0);
      Serial.println("Fin de servo");}
 }
 

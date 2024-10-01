//Librerias
#include <Wire.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

//Variables 
int contador = 0;
const int botonAumentar = 2, botonDisminuir = 3, botonPausa = 4;
#define pinPotenciometro A0
#define direccion_lcd 0x27
#define filas 2
#define columnas 16

SoftwareSerial softSerial(10, 11); 
DFRobotDFPlayerMini myDFPlayer;
LiquidCrystal_I2C lcdLeal(direccion_lcd, columnas, filas);
unsigned long tiempoant = 0, tiempocancion = 0, reptimecancion = 0;
bool Pausa = false;
unsigned long TimeAumentar = 0, TimeDisminuir = 0, TimePausa = 0;
const unsigned long Delay = 200;

void setup() {
  pinMode(botonAumentar, INPUT);
  pinMode(botonDisminuir, INPUT);
  pinMode(botonPausa, INPUT);
  softSerial.begin(9600);
  Serial.begin(9600);
  
  if (!myDFPlayer.begin(softSerial)) {
    Serial.println("Error en la inicialización del DFPlayer Mini");
    while (true);
  }
  
  myDFPlayer.volume(10);
  lcdLeal.init();
  lcdLeal.backlight();
}

void loop() {
  int valorPotenciometro = analogRead(pinPotenciometro);
  int volumen = map(valorPotenciometro, 0, 1023, 0, 30);
  myDFPlayer.volume(volumen);
  lcdLeal.setCursor(0, 1);
  lcdLeal.print(" < >  Volumen     ");
  lcdLeal.setCursor(14, 1);
  lcdLeal.print(volumen);

  if (digitalRead(botonAumentar) == HIGH && millis() - TimeAumentar > Delay && !Pausa && contador < 10) {
    contador++;
    playSong(contador);
    TimeAumentar = millis();
  }

  if (digitalRead(botonDisminuir) == HIGH && millis() - TimeDisminuir > Delay && !Pausa && contador > 0) {
    contador--;
    playSong(contador);
    TimeDisminuir = millis();
  }

  if (digitalRead(botonPausa) == HIGH && millis() - TimePausa > Delay) {
    Pausa = !Pausa;
    if (Pausa) myDFPlayer.pause(); else myDFPlayer.start();
    TimePausa = millis();
  }

  if (!Pausa && millis() - reptimecancion >= tiempocancion) {
    contador = (contador + 1) % 11;
    playSong(contador);
  }

  delay(100); 
}

void playSong(int Numero_cancion) {
  const char* canciones[] = {
    " cancion ", "  EXTSSY MODEL   ", "SPED UP NIGTHCORE ", 
    "     Lluvia     ", " LIBROS TONTOS  ", " FEEL SO CLOSE  ",
    " SE QUE TE AMO ", "  CORAZON FRIO ", "GOTAS DE LLUVIA", 
    "MI SEGUNDA VIDA ", "   GOOSEBUMPS   "
  };
  const unsigned long duraciones[] = {
    240000, 240000, 145800, 375600, 202800, 243600, 260400, 
    254400, 333000, 205800, 246000
  };

  Serial.print("Contador: ");
  Serial.println(Numero_cancion);
  Lcdlim();
  lcdLeal.setCursor(0, 0);
  lcdLeal.print(canciones[Numero_cancion]);
  myDFPlayer.play(Numero_cancion);
  tiempocancion = duraciones[Numero_cancion];
  reptimecancion = millis();
}

void Lcdlim() {
  lcdLeal.setCursor(0, 0);
  lcdLeal.print("                ");
}


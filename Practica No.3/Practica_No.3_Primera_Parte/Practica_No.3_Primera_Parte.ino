/*
 Fundacion Kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito
Quinto Electronica
Codigo Tecnico: EB5AM
Curso: Taller de electronica digital y reparacion de computadoras I
Proyecto: Catalogo de productos
Dev:Henry Francisco Leal Súchite
*/
struct Dulce_1
{
  char nombres_dulces[50];     
  byte cantidad_dulces;  
};
struct Dulce_2
{
  char nombres_dulces[50];     
  byte cantidad_dulces;  
};
struct Dulce_3
{
  char nombres_dulces[50];     
  byte cantidad_dulces;  
};
struct Dulce_4
{
  char nombres_dulces[50];     
  byte cantidad_dulces;  
};


Dulce_1 Dulce1 = {"Dulce de menta", 25};
Dulce_2 Dulce2 = {"Dulce coco ", 25};
Dulce_3 Dulce3 = {"Bombon", 25};
Dulce_4 Dulce4 = {"Chocolate KISS", 25};



void setup() {
  Serial.begin(9600);     //Inicio la comunicación serial.
   pinMode(2, INPUT);     //Pin 2 del arduino como entrada.
  pinMode(3, INPUT);     //Pin 3 del arduino como entrada.
   Serial.println("Catalogo de Dulces ");
  Serial.println("Boton izquierdo avanza ");
  Serial.println("Boton Derecho retrocede ");
  }

byte contador = 0;

  void loop() {

  if(digitalRead(2)==HIGH)  //Leo el estado digital del pin 2 y si este es bajo.
  {
   delay(350);
   contador = contador+1; 
   Serial.print("La pagina es: ");
   Serial.println(contador);
    
    if(contador == 1){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce1. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce1. cantidad_dulces);
  } 
     if(contador == 2){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce2. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce2. cantidad_dulces);
  } 
     if(contador == 3){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce3. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce3. cantidad_dulces);
  } 
     if(contador == 4){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce4. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce4. cantidad_dulces);
  } 
     if(contador >= 4){
    contador = 0;
  } 
  }
  else if(digitalRead(3)==HIGH) //Leo el estado digital del pin 3 y si este es bajo.
  {
   delay(350);
   contador = contador-1;   //disminuyo en uno el contador
   Serial.print("El valor del contador es de: ");
   Serial.println(contador);
     if(contador == 1){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce1. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce1. cantidad_dulces);
  } 
     if(contador == 2){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce2. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce2. cantidad_dulces);
  } 
     if(contador == 3){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce3. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce3. cantidad_dulces);
  } 
     if(contador == 4){
   Serial.print("Nombre del Dulce: ");
   Serial.println(Dulce4. nombres_dulces);
   Serial.print("La cantidad de dulces es:  ");
   Serial.println(Dulce4. cantidad_dulces);
    }
    
  }
    
}

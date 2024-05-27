/*
 Fundacion Kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito
Quinto Electronica
Codigo Tecnico: EB5AM
Curso: Taller de electronica digital y reparacion de computadoras I
Proyecto: Contador ascendente 0 a 9
Dev:Henry Francisco Leal Súchite
*/
byte contador = 0;

void setup() {
  Serial.begin(9600);     
  Serial.println(" contador ascedente 0 a 9");     
  pinMode(2, INPUT);    
  pinMode(3, INPUT);     
  pinMode(4, INPUT);
 contador = -1;
  }

 void loop() {
   contador = contador+1; 
    Serial.println(contador);
    if(contador >= 9){  
   contador = -1;
  }   
   
  if (digitalRead(2) == HIGH && digitalRead(3) == HIGH ) {
    delay(500);
   
  }
    if (digitalRead(3) == HIGH && digitalRead(4) == HIGH) {
    delay(50);
   
  }
   else if (digitalRead(2) == HIGH)  {
    delay(1000);
   
  }
   else if (digitalRead(3) == HIGH)  {
   delay(2000);
   
  }
   else if (digitalRead(4) == HIGH)  {
   delay(3000);
   
     }

 }
  

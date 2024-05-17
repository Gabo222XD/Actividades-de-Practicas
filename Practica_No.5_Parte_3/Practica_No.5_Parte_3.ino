/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: COHETE
   Dev: Henery Francisco Leal Súchite
   Fecha: 15 de abril */
int pines[] = {2,3,4,5,6,7,8};
int no9 [] = {8,7,4,3,2};
int no8 [] = {8,7,6,5,4,3,2};
int no7 [] = {2,3,4,8};
int no6 [] = {8,7,6,5,4,2};
int no5 [] = {8,7,5,4,2};
int no4 [] = {8,7,4,3};
int no3 [] = {8,5,4,3,2};
int no2 [] = {8,6,5,3,2};
int no1 [] = {4,3}; 
int no0 [] = {7,6,5,4,3,2};              
int buzzer = 9;

void setup (){
salidas();
pinMode(10,OUTPUT); 
digitalWrite(10,LOW); 
pinMode(buzzer,OUTPUT);
conteo();
}


void loop(){
}


void conteo(){
  for (int i =0; i<5; i++){
  digitalWrite(no9[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no9[i], LOW);}

  for (int i =0; i<7; i++){
  digitalWrite(no8[i], HIGH);}
  delay(1000);
  for (int i =7; i>=0; i--){
  digitalWrite(no8[i], LOW);} 

  for (int i =0; i<3; i++){
  digitalWrite(no7[i], HIGH);}
  delay(1000);
  for (int i =3; i>=0; i--){
  digitalWrite(no7[i], LOW);}
  
  for (int i =0; i<6; i++){
  digitalWrite(no6[i], HIGH);}
  delay(1000);
  for (int i =6; i>=0; i--){
  digitalWrite(no6[i], LOW);}
  
  for (int i =0; i<5; i++){
  digitalWrite(no5[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no5[i], LOW);}
  
  for (int i =0; i<4; i++){
  digitalWrite(no4[i], HIGH);}
  delay(1000);
  for (int i =4; i>=0; i--){
  digitalWrite(no4[i], LOW);}

  for (int i =0; i<5; i++){
  digitalWrite(no3[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no3[i], LOW);}
  
  for (int i =0; i<5; i++){
  digitalWrite(no2[i], HIGH);}
  delay(1000);
  for (int i =5; i>=0; i--){
  digitalWrite(no2[i], LOW);}

  for (int i =0; i<2; i++){
  digitalWrite(no1[i], HIGH);}
  delay(1000);
  for (int i =2; i>=0; i--){
  digitalWrite(no1[i], LOW);}

  for (int i =0; i<6; i++){
  digitalWrite(no0[i], HIGH);}
  delay(1000);
  for (int i =6; i>=0; i--){
  digitalWrite(no0[i], LOW);}
  ruido(); 
  
}
void ruido() {
  digitalWrite(10,HIGH);
  delay(25);
  tone(buzzer,250);
  delay(500);
  noTone(buzzer);
  digitalWrite(10,LOW);

  }

void salidas(){
  for(int p=0; p<7; p++){
  pinMode(pines[p],OUTPUT);}
}

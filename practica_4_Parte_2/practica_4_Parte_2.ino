/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Auto-fantastico
   Dev: Henry Francisco Leal Súchite
*/
int pines[] = {4, 5, 6, 7, 8, 9, 10, 11, 12}; 
int tiempo = 0;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
  for (int b = 0; b < 9; b++) {
  pinMode(pines[b], OUTPUT);}
  Serial.begin(9600);
}
 
void loop() {
  if(digitalRead(2)==HIGH){
    tiempo = 500;
    Serial.println("Secuencia - Velocidad 1");
    for (int b = 0; b<9 ; b++) {
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);
    }
    for (int b = 9; b>=0 ; b--) {
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);}
  }
  if(digitalRead(3)==HIGH){
    tiempo = 1000;
    Serial.println("Secuencia - Velocidad 2");
    for (int b = 0; b<9 ; b++){
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);
    }
    for (int b = 9; b >= 0 ; b--){
    digitalWrite(pines[b], HIGH);
    delay(tiempo);
    digitalWrite(pines[b], LOW);
    delay(tiempo);}
  } 
}  

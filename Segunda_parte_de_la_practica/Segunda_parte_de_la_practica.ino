/*
 Fundacion Kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito
Quinto Electronica
Codigo Tecnico: EB5AM
Curso: Taller de electronica digital y reparacion de computadoras I
Proyecto: Escritura en un pin digital (Encender o apagar un pin digital)
Dev:Henry Francisco Leal Súchite
*/
// Directivas de procesador
#define LedNaranja 4 //Pin4 conectado a un led
#define tiempo_espera 500 //Tiempo entre estados del led

void setup()
{
  pinMode(LedNaranja, OUTPUT); //Pin4 como salida
  digitalWrite(LedNaranja, LOW);//LED conectado al pin13 inicia apagado
}

void loop()
{
  digitalWrite(LedNaranja, HIGH);// Enciendo el led conectado al  pin4
  delay(tiempo_espera); //espera de 500 milisegundos
  digitalWrite(LedNaranja, LOW);//Apago el led conectado al pin4
  delay(tiempo_espera); //espera de 500 milisegundos
}

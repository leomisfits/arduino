//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
void velocity1(){
  digitalWrite(6,HIGH);
  delay(250);
  digitalWrite(6,LOW);
}
void velocity2(){
  digitalWrite(6,HIGH);
  delay(125);
  digitalWrite(6,LOW);
}
void velocity3(){
  digitalWrite(6,HIGH);
  delay(60);
  digitalWrite(6,LOW);
}
void velocity4(){
  digitalWrite(6,HIGH);
  delay(30);
  digitalWrite(6,LOW);
}
void velocity5(){
  digitalWrite(6,HIGH);
}
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");,
  pinMode(6,OUTPUT);
}
 
void loop()
{
  digitalWrite(6,LOW);
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  if (inMsec > 20){
    velocity1();
  }
  if (inMsec > 15 && inMsec < 20){
    velocity2();
  }
  if (inMsec > 10 && inMsec < 15){
    velocity3();
  }
  if (inMsec > 5 && inMsec < 10){
    velocity4();
  }
  if (inMsec > 1.5 && inMsec < 5){
    velocity5();
  }
}

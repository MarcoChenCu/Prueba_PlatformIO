#include <Arduino.h>

#define echo 6
#define trig 7
long duracion,distancia;
void setup()
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duracion = pulseIn(echo,HIGH);
  distancia = (duracion/2)/29;
  
  if(distancia>=500 || distancia<=0){
    Serial.println("Fuera de rango");
  }
  else if(distancia<=10){
  	digitalWrite(13,1);
    Serial.println("Alarma");
  }
  else{
    Serial.print(distancia);
    Serial.print(" cm\n");
    digitalWrite(13,0);    
  }
  
  delay(400);

}
#include <math.h>
const double p1 = 0.51816;
const double p2 = -9.9809;
const double p3 = 78.1372;
const double p4 = -319.0188;
const double p5 = 721.9031;
const double p6 = -877.527;
const double p7 = 485.6205;
void setup() {
  Serial.begin(9600);
   pinMode(A0, INPUT);
}
void loop() {
  int n = 150;
  float suma = 0;
  for (int i = 0; i < n; i++)
  {
    suma += analogRead(A0);
  }
  float medicion = suma / n;
  float v = (medicion * 5) / 1023;
  //float distancia = 51726.81003718/(pow(medicion, 1.41843971));//sin CAS
  //float distancia = 71929.05884822/(pow(medicion, 1.32625994));//con CAS
  double distancia = p1*pow(v,6) + p2*pow(v,5) + p3*pow(v,4) + p4*pow(v,3) + p5*pow(v,2) + p6*v + p7;//matlab 
  Serial.println("Medicion: " + String(medicion));
  Serial.println("Voltaje: " + String(v) + "v.");
  Serial.println("Distancia: " + String(distancia) + "cm. \n");
  delay(1000);
}

byte const echo = 53;
byte const trig = 51;
byte const led = 52;
float duracion, distancia;   
 
void setup() {                
  Serial.begin (9600);       
  pinMode(echo, INPUT);     
  pinMode(trig, OUTPUT);   
  pinMode(led, OUTPUT);        
  }
  
void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);   // genera el pulso de triger por 10ms como dice en la datasheet
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duracion = pulseIn(echo, HIGH);
  distancia = int((duracion/2) / 29);            // calcula la distancia en centimetros 1/26(0.034) cm/us = 340 m/s
  
  if (distancia >= 500 || distancia <= 0){    
    Serial.println("Fuera de rango");                 
  }
  else {
    Serial.print(distancia);             
    Serial.println("cm");              
    digitalWrite(led, LOW);               
  } 
  
  if (distancia <= 40 && distancia >= 30){
    digitalWrite(led, HIGH);                    
    Serial.println("led prendido");         
  }
  delay(400);                                
}

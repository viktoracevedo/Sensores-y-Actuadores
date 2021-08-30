#define PI 3.1415926535897932384626433832795
const byte decoder = 23; 
const byte led = 25;
byte contador = 0;
const byte n = 10;
const float radio = 3.6; //r = 3.6
float distancia = 0;
void setup() {
  Serial.begin (9600);
  pinMode(decoder, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(decoder, HIGH);
  digitalWrite(led, LOW);
}

void loop() {
  if (digitalRead(decoder)== LOW){
    contador++;
    float grados = (1 * 360) / n;
    float radianes = (grados * PI) / 180;
    distancia += radianes * radio;
    digitalWrite(led, LOW);
    Serial.println("Contador: " + String(contador) + 
                   " Se esta desplazando: "+String(distancia)+"cm.");
    if(contador == n){
      Serial.print("GIRO COMPLETO\n");
      digitalWrite(led, HIGH);
      contador = 0;
    }
    while(digitalRead(decoder) == LOW){}
  }
}
    //distancia = radianes * radio;
        //float grados = (contador * 360) / n;

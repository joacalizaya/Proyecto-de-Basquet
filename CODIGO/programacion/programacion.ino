
#define DEBUG 1

struct Display {
  int a, b, c, d, e, f, g ;
  int neg1, neg2, neg3, neg4;
};

void iniciarDisplay(Display *d) {
  pinMode(d->a, OUTPUT);
  pinMode(d->b, OUTPUT);
  pinMode(d->c, OUTPUT);
  pinMode(d->d, OUTPUT);
  pinMode(d->e, OUTPUT);
  pinMode(d->f, OUTPUT);
  pinMode(d->g, OUTPUT);
  pinMode(d->neg1, OUTPUT);
  pinMode(d->neg2, OUTPUT);
  pinMode(d->neg3, OUTPUT);
  pinMode(d->neg4, OUTPUT);
  
}
void apagarSegmentos(Display *d) {
  digitalWrite(d->a, LOW);
  digitalWrite(d->b, LOW);
  digitalWrite(d->c, LOW);
  digitalWrite(d->d, LOW);
  digitalWrite(d->e, LOW);
  digitalWrite(d->f, LOW);
  digitalWrite(d->g, LOW);
  digitalWrite(d->neg1, LOW);
  digitalWrite(d->neg2, LOW);
  digitalWrite(d->neg3, LOW);
  digitalWrite(d->neg4, LOW);
  
}


void mostrarNumero(Display *d, int num) {
  switch (num) {
   case 0:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,LOW);
  digitalWrite (d->e,HIGH);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
  
  break;
   case 1: 
  digitalWrite (d->a,LOW);
  digitalWrite (d->b,LOW);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,LOW);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,LOW);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
   case 2:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,LOW);
  digitalWrite (d->f,LOW);
  digitalWrite (d->g,LOW);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,HIGH);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
   case 3:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,LOW);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
   case 4: 
  digitalWrite (d->a,LOW);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,LOW);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
   case 5:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,LOW);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
   case 6:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,LOW);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,HIGH);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
  case 7: 
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,LOW);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,LOW);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,LOW);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
  case 8:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,HIGH);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
  case 9:
  digitalWrite (d->a,HIGH);
  digitalWrite (d->b,HIGH);
  digitalWrite (d->f,HIGH);
  digitalWrite (d->g,HIGH);
  digitalWrite (d->c,HIGH);
  digitalWrite (d->d,HIGH);
  digitalWrite (d->e,LOW);
  digitalWrite(d->neg1, HIGH);
  digitalWrite(d->neg2, HIGH);
  digitalWrite(d->neg3, HIGH);
  digitalWrite(d->neg4, HIGH);
 
  break;
  }
}

const int sensor = A1;
int pelotas = 0;
int estadoSensor = 0;
int estadoSensorAnterior = 0;
unsigned long previousMillis = 0;
const long interval = 100;
Display vector[4];

void setup() {
  Serial.begin(9600);
  
   vector[0] = {11, 10, 9, 8, 7, 6, 5, 3}; 
  vector[1] = {11, 10, 9, 8, 7, 6, 5, 12}; 
    vector[2] = {11, 10, 9, 8, 7, 6, 5, 2}; 
  vector[3] = {11, 10, 9, 8, 7, 6, 5, 4};   
  for (int i = 0; i < 2; i++) {
    iniciarDisplay(&vector[i]);
  }
    pinMode(sensor, INPUT);
}

void loop() {

unsigned long currentMillis = millis();
  estadoSensor = digitalRead(sensor);
    if(DEBUG){
    Serial.print("SENSOR: ");
    Serial.println(estadoSensor);}

  if(DEBUG){}
  
  if (!estadoSensor) {
    pelotas++;
    delay(500);
      if(DEBUG){
    Serial.print("Contador: ");
    Serial.println(pelotas);}
    delay(1000);
  }
  
  mostrarNumero(&vector[0], pelotas % 10); // Unidades de los puntos
  mostrarNumero(&vector[1], pelotas / 10); // Decenas de los puntos


if (currentMillis - previousMillis >= interval) {
 previousMillis = currentMillis; 
}
    estadoSensorAnterior = estadoSensor;
  
}

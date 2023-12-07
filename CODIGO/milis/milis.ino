#define sensorPin A1      
#define botonPin A0       
#define a 11
#define b 10
#define c 9
#define d 8
#define e 7
#define f 6
#define g 5
#define neg1 3
#define neg2 4
#define neg3 12
#define neg4 2

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempoSegundos = 0;
int numero = 0;


void cero(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,HIGH);
  digitalWrite (g,HIGH);
  digitalWrite (c,HIGH);
  digitalWrite (d,LOW);
  digitalWrite (e,HIGH);


  
}
void uno(){
 digitalWrite (a,HIGH);
  digitalWrite (b,LOW);
  digitalWrite (f,LOW);
  digitalWrite (g,LOW);
  digitalWrite (c,LOW);
  digitalWrite (d,LOW);
  digitalWrite (e,HIGH);


   
}
void dos(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,HIGH);
  digitalWrite (g,HIGH);
  digitalWrite (c,LOW);
  digitalWrite (d,HIGH);
  digitalWrite (e,LOW);


  
}
void tres(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,LOW);
  digitalWrite (g,HIGH);
  digitalWrite (c,LOW);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);


}
void cuatro(){
  digitalWrite (a,HIGH);
  digitalWrite (b,LOW);
  digitalWrite (f,LOW);
  digitalWrite (g,LOW);
  digitalWrite (c,HIGH);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);
 

  
}
void cinco(){
  digitalWrite (a,LOW);
  digitalWrite (b,HIGH);
  digitalWrite (f,LOW);
  digitalWrite (g,HIGH);
  digitalWrite (c,HIGH);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);



}
void seis(){
  digitalWrite (a,LOW);
  digitalWrite (b,HIGH);
  digitalWrite (f,HIGH);
  digitalWrite (g,HIGH);
  digitalWrite (c,HIGH);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);


 
}
void siete(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,LOW);
  digitalWrite (g,LOW);
  digitalWrite (c,LOW);
  digitalWrite (d,LOW);
  digitalWrite (e,HIGH);
 



}
void ocho(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,HIGH);
  digitalWrite (g,HIGH);
  digitalWrite (c,HIGH);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);



}
void nueve(){
  digitalWrite (a,HIGH);
  digitalWrite (b,HIGH);
  digitalWrite (f,LOW);
  digitalWrite (g,LOW);
  digitalWrite (c,HIGH);
  digitalWrite (d,HIGH);
  digitalWrite (e,HIGH);
}
void negativo_decena(){
  digitalWrite (neg1, LOW);
digitalWrite (neg2, LOW);
    digitalWrite (neg3, LOW);
  digitalWrite (neg4, HIGH);
}
void negativo_unidad(){
  digitalWrite (neg1, HIGH);
digitalWrite (neg2, LOW);
    digitalWrite (neg3, LOW);
  digitalWrite (neg4, LOW);
}


void setup() {
 pinMode (a,OUTPUT); 
 pinMode (b,OUTPUT);
 pinMode (f,OUTPUT);
 pinMode (g,OUTPUT);
 pinMode (c,OUTPUT);
 pinMode (d,OUTPUT);
 pinMode (e,OUTPUT);
 pinMode (sensorPin, INPUT);
 pinMode (botonPin, INPUT_PULLUP);
 
  Serial.begin(9600);
  tiempo1 = millis();

}
void loop() {

  tiempo2 = millis();
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
    Serial.print("Ha transcurrido: ");
    Serial.print(tiempoSegundos);
    Serial.println(" desde que se encendio el Arduino");
    numero = tiempoSegundos; }
 int millares=numero/1000;
	int centenas=(numero-(millares*1000))/100;
	int decenas=(numero- (millares*1000 + centenas*100))/10;
	int unidades=numero-(millares*1000 + centenas*100 + decenas*10 );
  Serial.print("UNIDADES");
Serial.println(unidades);
Serial.print("DECENAS ");
Serial.println(decenas);






switch(unidades){

  case 1: 
  uno();
  negativo_unidad();
  break;
  case 2:
  dos();
  negativo_unidad();
  break;
  case 3:
  tres();
  negativo_unidad();
  break;
   case 4: 
  cuatro();
  negativo_unidad();
  break;
  case 5:
  cinco();
  negativo_unidad();
  break;
  case 6:
  seis();
  negativo_unidad();
  break;
   case 7: 
  siete();
  negativo_unidad();
  break;
  case 8:
  ocho();
  negativo_unidad();
  break;
  case 9:
  nueve();
  negativo_unidad();
  break;

}


switch(decenas){

  case 1: 
  uno();
  negativo_decena();
  break;
  case 2:
  dos();
  negativo_decena();
  break;
  case 3:
  tres();
  negativo_decena();
  break;
   case 4: 
  cuatro();
  negativo_decena();
  break;
  case 5:
  cinco();
  negativo_decena();
  break;
  case 6:
  seis();
  negativo_decena();
  break;
   case 7: 
  siete();
  negativo_decena();
  break;
  case 8:
  ocho();
  negativo_decena();
  break;
  case 9:
  nueve();
  negativo_decena();
  break;

}

}


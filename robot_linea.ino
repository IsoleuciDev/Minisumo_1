//Sensor Ultrasonico

//Motor A Es el motor izquierdo 
int MA1 = 4;
int MA2 = 5;
int PWMA = 3; 

//Motor B es el motor derecho 
int MB1 = 6;
int MB2 = 7;
int PWMB = 11; 


int vel = 255;

//Sensores
int Sright = A7; 
int Sleft = A0;

void setup() {
  Serial.begin(9600);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT); 
  pinMode(Sright, INPUT);
  pinMode(Sleft, INPUT);
}

void loop(){
  atrasB();
  /*
  int valorR = sensorR();
  int valorL = sensorL();
  Serial.println("El valor del sensor derecho es");
  Serial.println(valorR);
  delay(400);
  Serial.println("El valor del sensor izquierdo es"); 
  Serial.println(valorL);/
  adelanteB();*/

}



void avanzar(){
  int sensorD = sensorR(); 
  int sensorI = sensorL(); 
  if(sensorD < 950 && sensorI >950){
    girarD();
  }
  else if(sensorI< 950 && sensorD >950){
    girarI();
  }
  else{
    adelanteA();
    adelanteB();
  }
}

void girarD(){
  adelanteA();
  digitalWrite(MB1, 1);
  digitalWrite(MB2, 0);
  analogWrite(PWMB, 70); 
  delay(200);
}

void girarI(){

}

int sensorR(){
  int valor = analogRead(Sright);
  return valor;
}

int sensorL(){
  int valor = analogRead(Sleft);
  return valor;
}


void adelanteA() {
  digitalWrite(MA1, 0);
  digitalWrite(MA2, 1);
  analogWrite(PWMA, vel); 
  delay(200);
  
}

void adelanteB() {
  digitalWrite(MB1, 0);
  digitalWrite(MB2, 1);
  analogWrite(PWMB, vel); 
  delay(200);
  
}

void atrasA() {
  digitalWrite(MA1, 1);
  digitalWrite(MA2, 0);
  analogWrite(PWMA, vel); 
  delay(200);
  
}


void atrasB() {
  digitalWrite(MB1, 1);
  digitalWrite(MB2, 0);
  analogWrite(PWMB, vel); 
  delay(200);
  
}

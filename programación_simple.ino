#include <SoftwareSerial.h> 
int LED = 13; 
int LED2 = 6;
int STBY = 2;

//Motores
int PWMA = 3;
int MOTORA1 = 4;
int MOTORA2 = 5;

int PWMB =11;
int MOTORB1 =8;
int MOTORB2 =7;


SoftwareSerial blue(12,10);
void setup() {
  blue.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(MOTORB1, OUTPUT);
  pinMode(MOTORB2, OUTPUT);
  pinMode(STBY, OUTPUT); 
  pinMode(PWMB, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(MOTORA1, OUTPUT);
  pinMode(MOTORA2, OUTPUT);
  delay(5000);
  //
  digitalWrite(STBY,1);
    VELM();
  AVANZAR();
  delay(200);
}

void loop() {
  VEL();
  AVANZAR(); 

  digitalWrite( LED2, LOW);
  digitalWrite( LED, LOW);  
  int sensorLineaR = analogRead(A2);
  int sensorLineaL  = analogRead(A3);
  Serial.println("Valor Derecho");
  Serial.print(sensorLineaL);
  //Serial.println("Valor Izquierdo"); */
  int sensorFI = analogRead(A4);
  int sensorC = analogRead(A5);
  int sensorFD = analogRead(A6);
  int sensorLD = analogRead(A7);
  int sensorLI = analogRead(A0);
 
  
  if (sensorLD > 100 ){
      digitalWrite( LED2, HIGH);
      GiroD();
      
    }
  if (sensorLI > 100){
      digitalWrite(LED, HIGH);
      GiroI();
  
    }
  if (sensorC > 100){
      AVANZAR();
      VELM();
      digitalWrite( LED, HIGH);
      digitalWrite( LED2, HIGH);      
    }
  if (sensorLineaL < 40){
      retroceder();
      VEL();
      digitalWrite( LED, HIGH);
      digitalWrite( LED2, HIGH);      
    }
  if (sensorLineaR < 200){
      retroceder();
      VEL();
      digitalWrite( LED, HIGH);
      digitalWrite( LED2, HIGH);      
    }

}

   


void retroceder(){
   digitalWrite(MOTORB1, 1);
   digitalWrite(MOTORB2, 0);
   analogWrite(PWMB, 100);
   digitalWrite(MOTORA1, 1);
   digitalWrite(MOTORA2, 0);
   analogWrite(PWMA, 100);
   delay(500);
}


void AVANZAR(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 60);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 60);
   delay(160); 
}


void GiroD(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 20);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 90);
   delay(200);
}


void GiroI(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 20);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 90);
   delay(200);

}

void pausa(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 0);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 0);
  

}


void VEL(){
  analogWrite(PWMA, 50);
  analogWrite(PWMB, 50);    
}


void VELM(){
  analogWrite(PWMA, 230);
  analogWrite(PWMB, 230);    
}

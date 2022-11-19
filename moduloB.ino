#include <SoftwareSerial.h>

int STBY = 2;
char instruccion;

//Motores
int PWMA = 3;
int MOTORA1 = 4;
int MOTORA2 = 5;

int PWMB =11;
int MOTORB1 =8;
int MOTORB2 =7;



SoftwareSerial blue(12,10);
void setup()  
{
  Serial.begin(9600);
  blue.begin(9600);
  pinMode(MOTORB1, OUTPUT);
  pinMode(MOTORB2, OUTPUT);
  pinMode(STBY, OUTPUT); 
  pinMode(PWMB, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(MOTORA1, OUTPUT);
  pinMode(MOTORA2, OUTPUT);

  //
  digitalWrite(STBY,1);

}

void loop() 
{
  while(blue.available())
  {
    instruccion = blue.read(); 
    Serial.println(instruccion);
    switch(instruccion){
      case 'a':
      GiroI();
      break;
      case 'w':
      avanzar();
      break;
      case 's':
      retroceder();
      break;      
      case 'd':
      GiroD();
      break;    
    }
  }
  while(Serial.available()){
    instruccion = Serial.read();
    blue.print(instruccion);  
  
  }
}

void retroceder(){
   digitalWrite(MOTORB1, 1);
   digitalWrite(MOTORB2, 0);
   analogWrite(PWMB, 50);
   digitalWrite(MOTORA1, 1);
   digitalWrite(MOTORA2, 0);
   analogWrite(PWMA, 50);
   delay(80);
}


void avanzar(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 50);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 50);
   delay(80);
}


void GiroD(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 20);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 100);
   delay(80);
}


void GiroI(){
   digitalWrite(MOTORB1, 0);
   digitalWrite(MOTORB2, 1);
   analogWrite(PWMB, 100);
   digitalWrite(MOTORA1, 0);
   digitalWrite(MOTORA2, 1);
   analogWrite(PWMA, 20);
   delay(80);
}

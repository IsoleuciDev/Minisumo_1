// Control Motores
int PWMA = 3; 
int PWMB = 11; 
//Motores 
int MOTORA1 = 4; 
int MOTORA2 = 5;
int MOTORB1 = 8; 
int MOTORB2 = 7;
int STBY = 2; 
void setup() 
{
  Serial.begin(9600);
  pinMode(MOTORA1, OUTPUT);
  pinMode(MOTORA2, OUTPUT);
  pinMode(MOTORB1, OUTPUT);
  pinMode(MOTORB2, OUTPUT); 
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);  
  digitalWrite(STBY, 1); 
  delay(5000);
}
void loop() 
{
  int sensorEI = digitalRead(A0);
  int sensorC = digitalRead(A1);//
  int sensorLI = digitalRead(A2);//
  int sensorED = digitalRead(A3);//
  int sensorLD = digitalRead(A4);//
  int sensorlineaD = analogRead(A5); 
  int sensorlineaI = analogRead(A6);
  Serial.print("valor : ");
  Serial.println(sensorlineaD);
  avanzar();
  if ( sensorlineaD < 490){
    retroceder();
    delay(220);
    giroI();
    delay(200);
  }
  if ( sensorlineaI < 490){
    retroceder();
    delay(220);
    giroD();
    delay(200);
  }
  if ( sensorlineaD < 490  && sensorlineaI  < 490){
    retroceder();
    delay(280);
    giroI();
    delay(200);
  }
  if ( sensorLI ==1){
    giroDa();
    delay(1);
  }
  if ( sensorLD ==1){
    giroIa();
    delay(1);
  }
  if ( sensorC ==1){
    avanzarR();
    delay(5);
  }  
}

void giroDa()
{
  digitalWrite(MOTORB1, 1);
  digitalWrite(MOTORB2, 0);
  analogWrite(PWMB  , 220);
  digitalWrite(MOTORA1, 0);
  digitalWrite(MOTORA2, 1 );
  analogWrite(PWMA, 220); 
}

void giroIa()
{
  digitalWrite(MOTORB1, 0);
  digitalWrite(MOTORB2, 1);
  analogWrite(PWMB  , 220);
  digitalWrite(MOTORA1, 1);
  digitalWrite(MOTORA2, 0);
  analogWrite(PWMA, 220);
}
void giroD()
{
  digitalWrite(MOTORB1, 0);
  digitalWrite(MOTORB2, 1);
  analogWrite(PWMB  , 220);
  digitalWrite(MOTORA1, 1);
  digitalWrite(MOTORA2, 0 );
  analogWrite(PWMA, 220); 
}

void giroI()
{
  digitalWrite(MOTORB1, 1);
  digitalWrite(MOTORB2, 0);
  analogWrite(PWMB  , 250);
  digitalWrite(MOTORA1, 0);
  digitalWrite(MOTORA2, 1);
  analogWrite(PWMA, 250);
}

void avanzar()
{
  digitalWrite(MOTORB1, 1);
  digitalWrite(MOTORB2, 0);
  analogWrite(PWMB  , 80);
  digitalWrite(MOTORA1, 1);
  digitalWrite(MOTORA2, 0);
  analogWrite(PWMA, 80);     
}
void avanzarR()
{
  digitalWrite(MOTORB1, 1);
  digitalWrite(MOTORB2, 0);
  analogWrite(PWMB  , 200);
  digitalWrite(MOTORA1, 1);
  digitalWrite(MOTORA2, 0);
  analogWrite(PWMA, 200);     
}
void alto()
{
  digitalWrite(MOTORB1, 1);
  digitalWrite(MOTORB2, 0);
  analogWrite(PWMB  , 0);
  digitalWrite(MOTORA1, 1);
  digitalWrite(MOTORA2, 0);
  analogWrite(PWMA, 0);     
}
void retroceder()
{
  digitalWrite(MOTORB1, 0);
  digitalWrite(MOTORB2, 1);
  analogWrite(PWMB  , 255);
  digitalWrite(MOTORA1, 0);
  digitalWrite(MOTORA2, 1);
  analogWrite(PWMA, 255);   
}

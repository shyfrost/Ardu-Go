 #include <SoftwareSerial.h>
 #include <Servo.h>

const int A_1A =2;
const int A_1B =3;
const int B_1A =4;
const int B_1B =5;
const int A_2A =6;
const int A_2B =7;
const int B_2A =8;
const int B_2B =9;
const int rxpin = 10;
const int txpin = 11;
int grado_A = 100;
int grado_P = 60;

Servo angulo;
Servo polar;

SoftwareSerial bluetooth(rxpin, txpin);
void setup()
{
  
   Serial.begin(9600); 
 bluetooth.begin(9600);
 Serial.println("Serial listo");
 bluetooth.println("Bluetooth listo"); 
 
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(A_2A, OUTPUT);
  pinMode(A_2B, OUTPUT);
  pinMode(B_2A, OUTPUT);
  pinMode(B_2B, OUTPUT);

  angulo.attach(12);
  polar.attach(13);
  angulo.write(grado_A);
  polar.write(grado_P);
  
  analogWrite(A_1A, 0); digitalWrite(A_1B, 0);
  analogWrite(B_1A, 0); digitalWrite(B_1B, 0);
  analogWrite(A_2A, 0); digitalWrite(A_2B, 0);
  analogWrite(B_2A, 0); digitalWrite(B_2B, 0);
}

void loop()
{
   if (bluetooth.available())
 {
    char c = (char)bluetooth.read();
    
   switch (c)
   {

    //SERVOS

  //'W' servo base, izquierda
  case 'W':
  if (grado_A < 180){
  grado_A = grado_A + 5;
  angulo.write(grado_A);
  }
  break;

  //'V' Servo base, derecha
  case 'V':
  if (grado_A > 0) {
  grado_A = grado_A - 5;
  angulo.write(grado_A);
  }
  break;

  //'Y' servo cámara, abajo
  case 'Y':
  if(grado_P > 0){
  grado_P = grado_P - 5;
  polar.write(grado_P);
  }
  break;

  //'z' servo cámara, arriba
  case 'Z':
  if(grado_P < 130){
  grado_P = grado_P + 5;
  polar.write(grado_P);
  }
  break;

  //MOTORES
     //adelante
  case 'A':
  analogWrite(A_1A, 255); digitalWrite(A_1B, 0);
  analogWrite(B_1A, 0); digitalWrite(B_1B, 255);
  analogWrite(A_2A, 255); digitalWrite(A_2B, 0);
  analogWrite(B_2A, 255); digitalWrite(B_2B, 0);
  break;

  
  //atras 
  case 'B':
  analogWrite(A_1A, 0); digitalWrite(A_1B, 255);
  analogWrite(B_1A, 255); digitalWrite(B_1B, 0);
  analogWrite(A_2A, 0); digitalWrite(A_2B, 255);
  analogWrite(B_2A, 0); digitalWrite(B_2B, 255);
  break;
  
  //Izquierda
  case 'I':
  analogWrite(A_1A, 0); digitalWrite(A_1B, 0);
  analogWrite(B_1A, 0); digitalWrite(B_1B, 255);
  analogWrite(A_2A, 0); digitalWrite(A_2B, 0);
  analogWrite(B_2A, 255); digitalWrite(B_2B, 0);
  break;

  //Derecha Adelante
  case 'D':
  analogWrite(A_1A, 255); digitalWrite(A_1B, 0);
  analogWrite(B_1A, 0); digitalWrite(B_1B, 0);
  analogWrite(A_2A, 255); digitalWrite(A_2B, 0);
  analogWrite(B_2A, 0); digitalWrite(B_2B, 0);
  break;
  
  //Detener
  case 'X':
  analogWrite(A_1A, 0); digitalWrite(A_1B, 0);
  analogWrite(B_1A, 0); digitalWrite(B_1B, 0);
  analogWrite(A_2A, 0); digitalWrite(A_2B, 0);
  analogWrite(B_2A, 0); digitalWrite(B_2B, 0);
  break;

  
   }
 }
 }
 /*
'W' (servo base, izquierda)
'V' (servo base, derecha)
'Y' ( servo cámara, abajo)
'Z' (servo cámara, arriba) */

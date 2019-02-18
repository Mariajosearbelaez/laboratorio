#include <Servo.h> 
#define PINSERVODERECHO 5 //pin del servo derecho como 5
#define PINSERVOIZQUIERDO 7 //pin del servo derecho como 7
Servo ServoDerecho; 
Servo ServoIzquierdo;

char tecla;

void setup()
{

 ServoDerecho.attach(PINSERVODERECHO);
 ServoIzquierdo.attach(PINSERVOIZQUIERDO);
 
  Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
}

void loop(){
if (Serial.available()>0)
{
  tecla = Serial.read();
  switch(tecla)
  {
    case 'w':
    ServoIzquierdo.write(0);
    ServoDerecho.write(180);
    break;
     case 's':
    ServoIzquierdo.write(180);
    ServoDerecho.write(0);
    break; 
    case 'a':
    ServoIzquierdo.write(90);
    ServoDerecho.write(0);
    break; case 'd':
    ServoIzquierdo.write(180);
    ServoDerecho.write(90);
    break;
    case 'q':
    ServoIzquierdo.write(90);
    ServoDerecho.write(90);
    break;
  }
}

}

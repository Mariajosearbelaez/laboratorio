#include <Servo.h> 
#define PINSERVODERECHO 5 //pin del servo derecho como 5
#define PINSERVOIZQUIERDO 7 //pin del servo derecho como 7
#define PinTX_BT 10
#define PinRX_BT 9
Servo ServoDerecho; 
Servo ServoIzquierdo;
#include <SoftwareSerial.h>
#define Pin_Echo 6
#define Pin_Trigger 8
long duracion, dist;
char tecla;
SoftwareSerial Bt(PinRX_BT, PinTX_BT);
void setup()
{

 ServoDerecho.attach(PINSERVODERECHO);
 ServoIzquierdo.attach(PINSERVOIZQUIERDO);
 
 Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
 Bt.begin(9600);
}

void loop(){
if (Serial.available()>0)
{
  tecla = Serial.read();
}
if(Bt.available()>0)
{
tecla=Bt.read();
}
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
digitalWrite(Pin_Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Pin_Trigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(Pin_Trigger, LOW);
  duracion = pulseIn(Pin_Echo, HIGH);
  dist = (duracion/2) / 29;
  if (dist <= 10 && dist >= 1)
  {
    ServoIzquierdo.write(90);
    ServoDerecho.write(90);
  }
}

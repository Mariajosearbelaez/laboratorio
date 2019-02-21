/*
Laboratorio #2 de programación.
Hecho por Maria José Arbelaez y Juan Esteban Gallego
Robot inalámbrico denominado Poppet
21/02/2019
*/
#include <Servo.h> //Librería del Servo
#include <SoftwareSerial.h>//Librería Bluetooth

#define PINSERVODERECHO 5 //pin del servo derecho como 5
#define PINSERVOIZQUIERDO 7 //pin del servo derecho como 7
#define PinTX_BT 10 //Pin del Tx del Bluetooth
#define PinRX_BT 9 //Pin del Tx del Bluetooth
#define Pin_Echo 6  //Pin Echo del Ultrasonido
#define Pin_Trigger 8 // Pin Trigger del Ultrasonido


long duracion, dist; // Variables tipo float para el Ultrasonido
char tecla; // Variable que almacena las órdenes del teclado


SoftwareSerial Bt(PinRX_BT, PinTX_BT); //Conexión del Bluetooth al Arduino
Servo ServoDerecho; // Declaración de los Servos
Servo ServoIzquierdo;


void setup()
{

 ServoDerecho.attach(PINSERVODERECHO); // Conexión de los Servos al Arduino
 ServoIzquierdo.attach(PINSERVOIZQUIERDO);
 
 Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
 Bt.begin(9600);       // Comunicación del Bluetooth a 9600 bps
}

void loop(){
if (Serial.available()>0) // Lectura del valor del Teclado
{
  tecla = Serial.read();
}
if(Bt.available()>0) // Lectura del valor puesto desde la aplicación
{
tecla=Bt.read();
}
  switch(tecla) // Movimiento según cada caso
  {
    case 'w': // Avanzar
    ServoIzquierdo.write(0);
    ServoDerecho.write(180);
    break;
     case 's': // Retroceder
    ServoIzquierdo.write(180);
    ServoDerecho.write(0);
    break; 
    case 'a': // Girar a la izquierda
    ServoIzquierdo.write(90);
    ServoDerecho.write(0);
    break;
    case 'd': // Girar a la Derecha
    ServoIzquierdo.write(180);
    ServoDerecho.write(90);
    break;
    case 'q': // Detenerse
    ServoIzquierdo.write(90);
    ServoDerecho.write(90);
    break;
  }
digitalWrite(Pin_Trigger, LOW); // Pulso emitido por el Trigger
  delayMicroseconds(2);
  digitalWrite(Pin_Trigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(Pin_Trigger, LOW);

  
  duracion = pulseIn(Pin_Echo, HIGH);  // Tiempo en el que el Echo percibió el pulso
  
  dist = (duracion/2) / 29; // Cálculo de la distancia en cm
  
  if (dist <= 5 && dist >= 1) // Orden de detenerse si percibe algo a menos de 5 cm
  {
    ServoIzquierdo.write(90);
    ServoDerecho.write(90);
  }
  delay(400); 
}

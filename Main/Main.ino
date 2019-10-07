#include <Ultrasonic.h>

#include <AFMotor.h>



AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

/*Definir posição e portas utilizadas*/
Ultrasonic Distancia(53, 52);
int SensorLinha = 51;


void setup() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    Serial.begin(9600);

    //Definição dos sensores
    pinMode(SensorLinha, INPUT);
}

void loop() {
  //Lógica
  float cm;
  long tempo = Distancia.timing();


  //Código para localizar o oponente

  while(cm >= 15){
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
    }

  //Caso localize o oponente irá acelerar os motores
  if(cm <= 15){
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      if(digitalRead(SensorLinha) == HIGH){
            motor1.run(RELEASE);
            motor2.run(RELEASE);
        }
    }
/* Código da linha preta*/

  
  
}

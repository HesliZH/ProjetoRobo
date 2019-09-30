#include <Ultrasonic.h>

#include <AFMotor.h>



AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

/*Definir posição e portas utilizadas*/
Ultrasonic Distancia(53, 52);


void setup() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    Serial.begin(9600);
}

void loop() {
  //Lógica
  float cm;
  long tempo = Distancia.timing();
  
  cm = Distancia.convert(tempo, Ultrasonic::CM);

  Serial.println(cm);

  if(cm <= 6){
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    }else{
        motor1.run(RELEASE);
        motor2.run(RELEASE);
      }

/* Código da linha preta*/

  
  
}

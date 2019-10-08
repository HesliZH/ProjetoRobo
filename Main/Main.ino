#include <Ultrasonic.h>

#include <AFMotor.h>



AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

/*Definir posição e portas utilizadas*/
Ultrasonic Distancia(53, 52);
int SensorLinha = 51;
long tempo;
  

void setup() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    Serial.begin(9600);

    //Definição dos sensores
    pinMode(SensorLinha, INPUT);
}

void loop() { 
    


    ProcuraOponente();
     
}

void ProcuraOponente(){
  float cm;
  tempo = Distancia.timing();
    
  bool Encontrado = false;
 
  if(Encontrado == false){
     cm = Distancia.convert(tempo, Ultrasonic::CM);
     
      motor1.run(FORWARD);
      motor2.run(BACKWARD);   
      Serial.println(cm);
      if(cm <= 15){
        motor1.run(RELEASE);
            motor2.run(RELEASE);
           Lutar(cm);
      }
  }  
}


void Lutar(float cm){
  if(cm <= 15){
        motor1.run(FORWARD);
        motor2.run(FORWARD);
  }else{
      
      
     /* if(digitalRead(SensorLinha) == HIGH){
            motor1.run(RELEASE);
            motor2.run(RELEASE);
        }*/
    return ProcuraOponente();
  }

}

/*carro de corrida autônomo .24º projeto.linguagem utilizada c++

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 15/09/2023
  Data de término do projeto 17/09/2023

*/
//********************INCLUSÃO DAS BIBLIOTECAS
#include <Ultrasonic.h>
//********************TRIG 12 ECHO 13 (INSTANCIAÇÃO DO OBJETO)
Ultrasonic ultrasonic(12, 13);
//********************VARIAVEIS
int distancia;
//********************DEFINIÇÕES
#define roda_da_direita_1 5
#define roda_da_ESQUERDA_1 6

#define roda_da_direita_2 10
#define roda_da_ESQUERDA_2 11
//*************************************************************************************************************************************
void setup(){
  pinMode(roda_da_direita_1 , OUTPUT);
  pinMode(roda_da_ESQUERDA_1 , OUTPUT);
  pinMode(roda_da_direita_2 , OUTPUT);
  pinMode(roda_da_ESQUERDA_2 , OUTPUT);

  delay(2000);//DELAY DE INICIO
  //Serial.begin(9600);
}
//****************************************************************************************************************************************
void loop(){
  //Serial.println(distancia);
//********************PASSA O COMANDO ""ultrasonic.read();"" PARA UMA VARIALVEL
  distancia = ultrasonic.read();
//********************FONCIONAMANETO DO ROBÔ
if ( distancia <=35 && distancia >=11) {// SE A DISTANCIA ESTIVAR ENTRE 55 E 16 FAÇA O DISVIO 
  if (random (1 ,2 + 1) ==1){ // SORTEIA A DIREÇÃO
    digitalWrite(roda_da_ESQUERDA_2, LOW);//******* DIREITA
    digitalWrite(roda_da_direita_1, HIGH);

    digitalWrite(roda_da_direita_2, HIGH);
    digitalWrite(roda_da_ESQUERDA_1, LOW);
    delay(100);

    }else{
    digitalWrite(roda_da_ESQUERDA_2,HIGH);//*******ESQUERDA
    digitalWrite(roda_da_direita_1, LOW);

    digitalWrite(roda_da_direita_2, LOW);
    digitalWrite(roda_da_ESQUERDA_1,HIGH);
    delay(100);
    }
  }else{ // SE NADA ATRAPALHA O CAMINO VAI PARA FRENTE
    digitalWrite(roda_da_ESQUERDA_2, HIGH);//******* FRENTE      
    digitalWrite(roda_da_direita_1, HIGH);

    digitalWrite(roda_da_direita_2, LOW);
    digitalWrite(roda_da_ESQUERDA_1, LOW);
  }
if ( distancia <=10 && distancia >=1) { //********************SE A DISTACIA FOR MENOR QUE 10 VAI DAR RÉ
    digitalWrite(roda_da_ESQUERDA_2, LOW);//******* RÉ     
    digitalWrite(roda_da_direita_1, LOW);

    digitalWrite(roda_da_direita_2, HIGH);
    digitalWrite(roda_da_ESQUERDA_1, HIGH);
    delay(600);
  }
  delay(50);
}
//***************************************************************************************************************************************


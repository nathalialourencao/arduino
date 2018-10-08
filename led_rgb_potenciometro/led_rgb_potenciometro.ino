/*
 * Aciona as 3 cores do LED RGB através de botões
 */

// Pinos
const int pinoLEDR = 11;
const int pinoLEDG = 10;
const int pinoLEDB = 9;
const int pinoBotaoR = 7;
const int pinoBotaoG = 6;
const int pinoBotaoB = 5;
const int pinoBotaoA = 4; // Botao de ajuste
const int pinoPotenciometro = A0; // potenciometro de intensidade

// Estados de cada botão
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;
int leituraBotaoA;
int leituraPotenciometro;
int pwmR = 0;
int pwmG = 0;
int pwmB = 0;

void setup() {
  // configura os pinos
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
  
  pinMode(pinoBotaoR, INPUT_PULLUP);
  pinMode(pinoBotaoG, INPUT_PULLUP);
  pinMode(pinoBotaoB, INPUT_PULLUP);
  pinMode(pinoBotaoA, INPUT_PULLUP);
}

void loop() {
  // le estado dos botões
  leituraBotaoR = digitalRead(pinoBotaoR);
  leituraBotaoG = digitalRead(pinoBotaoG);
  leituraBotaoB = digitalRead(pinoBotaoB);
  leituraBotaoA = digitalRead(pinoBotaoA);
  leituraPotenciometro = analogRead(pinoPotenciometro);

  if(leituraBotaoR == LOW){ // verifica se o botão foi pressionado
    if(leituraBotaoA == LOW){
      // Ajusta a intensidade da cor de acordo com o potenciometro
      pwmR = map(leituraPotenciometro, 0, 1023, 0 ,255);
    }
    analogWrite(pinoLEDR, pwmR); // aciona a cor a intesidade configurada
  } else{
    analogWrite(pinoLEDR, 0); // apaga o LED
  }

  if(leituraBotaoG == LOW){ // verifica se o botão foi pressionado
    if(leituraBotaoA == HIGH){
      // Ajusta a intensidade da cor de acordo com o potenciometro
      pwmG = map(leituraPotenciometro, 0, 1023, 0 ,255);
    }
    analogWrite(pinoLEDG, pwmG); // aciona a cor a intesidade configurada
  } else{
    analogWrite(pinoLEDG, 0); // apaga o LED
  }

  if(leituraBotaoB == LOW){ // verifica se o botão foi pressionado
    if(leituraBotaoA == HIGH){
      // Ajusta a intensidade da cor de acordo com o potenciometro
      pwmB = map(leituraPotenciometro, 0, 1023, 0 ,255);
    }
    analogWrite(pinoLEDB, pwmB); // aciona a cor a intesidade configurada
  } else{
    analogWrite(pinoLEDB, 0); // apaga o LED
  }

  delay(100); // aguar 100 miliseguindos para uma nova leitura

}

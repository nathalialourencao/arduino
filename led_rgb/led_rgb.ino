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

// Estados de cada botão
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;

void setup() {
  // configura os pinos
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
  
  pinMode(pinoBotaoR, INPUT_PULLUP);
  pinMode(pinoBotaoG, INPUT_PULLUP);
  pinMode(pinoBotaoB, INPUT_PULLUP);
}

void loop() {
  // le estado dos botões
  leituraBotaoR = digitalRead(pinoBotaoR);
  leituraBotaoG = digitalRead(pinoBotaoG);
  leituraBotaoB = digitalRead(pinoBotaoB);

  if(leituraBotaoR == LOW){ // verifica se o botão foi pressionado
    analogWrite(pinoLEDR, 255); // aciona a cor com brilho máximo
  } else{
    analogWrite(pinoLEDR, 0); // apaga o LED
  }

  if(leituraBotaoG == LOW){ // verifica se o botão foi pressionado
    analogWrite(pinoLEDG, 255); // aciona a cor com brilho máximo
  } else{
    analogWrite(pinoLEDG, 0); // apaga o LED
  }

  if(leituraBotaoB == LOW){ // verifica se o botão foi pressionado
    analogWrite(pinoLEDB, 255); // aciona a cor com brilho máximo
  } else{
    analogWrite(pinoLEDB, 0); // apaga o LED
  }

  delay(100); // aguar 100 miliseguindos para uma nova leitura

}

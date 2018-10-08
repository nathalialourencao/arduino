/*
 * Detectar a presença de obstáculos a partir de um diodo laser e um LDR
 */

// Pinos
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;

// Vars
int leituraLDR = 0;
int leituraBotao;

void setup() {
  Serial.begin(9600);
  
  // configura o pino com LDR como entrada
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // le o valor de tensão no pino do LDR
  leituraLDR = analogRead(pinoLDR);

  // Le o estado do botao
  leituraBotao = digitalRead(pinoBotao);

  Serial.print("Leitura: ");
  Serial.print(leituraLDR);
  Serial.print("\t"); // tabulacao

  if (leituraLDR <= 512){
    tone(pinoBuzzer, 1000); // aciona o buzzer
    Serial.print("Sim");
  }
  if (leituraBotao == LOW){ // senão e o botão estiver presinonado
    noTone(pinoBuzzer); // Desliga o buzzer
    Serial.print("Nao");
  }

  Serial.println();

  delay(100);
}

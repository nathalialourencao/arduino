/*
 * Fazendo Barulho - Pisca-pisca sonoro
 */

int frequencia = 2000; // Frequencia inicial do buzzer
const int pinoBuzzer = 10; // pino onde o buzzer esta conectado
const int pinoBotao1 = 9; // pino onde o botão 1 esta conectado
const int pinoBotao2 = 11; // pino onde o botão 2 esta conectado

void setup() {
  pinMode(pinoBuzzer, OUTPUT); // configura o pino com o buzzer como saída
  pinMode(pinoBotao1, INPUT_PULLUP); // configura o pino com o botão como entrada
  pinMode(pinoBotao2, INPUT_PULLUP); // configura o pino com o botão como entrada
}

void loop() {
  //  Soma 100 á frequencia atual se o botão estiver pressionado
  if (digitalRead(pinoBotao1) == LOW){
    frequencia = frequencia + 100;
  }

  //  Subtrai 100 á frequencia atual se o botão estiver pressionado
  if (digitalRead(pinoBotao2) == LOW){
    frequencia = frequencia - 100;
  }
  
  tone(pinoBuzzer, frequencia); // gera frequencia de 2000Hz no buzzer
  delay(1000);
  noTone(pinoBuzzer); // para frequencia no buzzer
  delay(1000);
}

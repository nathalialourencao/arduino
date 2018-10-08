/*
   Projeto Semáfaro
*/

void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(9, OUTPUT); // LED VERDE pedestres
  pinMode(10, OUTPUT); // LED VERMELHO pedestres
  pinMode(11, OUTPUT); // LED VERDE carros
  pinMode(12, OUTPUT); // LED AMARELO carros
  pinMode(13, OUTPUT); // LED VERMELHO carros
}

void loop() {
  // Sinal para pedestres fechado: apaga LED verde, acende LED vermelho
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);

  // Sinal para carros aberto: apaga LED vermelho, acende LED verde
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(3000);

  // Sinal fechado para carros: apaga LED verde, acende LED amaarelo
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(2000);

  // Sinal para pedestres aberto: apaga LED vermelho, acende LED verde
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  // Sinal fechado para carros: apaga LED AMARELO, acende LED vermelho
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(5000);

  // Sinal para pedestres fechando: apaga LED verde, pisca LED vermelho
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(200);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(200);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(200);
}

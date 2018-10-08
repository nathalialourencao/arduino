/*
 * Projeto Dimmer com LED 2
 * Usar um potenciômetro para controlar a intensidade de um LED.
 */

const int pinoPotenciometro = A0;
const int pinoLED = 11;
int leitura = 0;
int pwm = 0; // variavel para armazenar o valor da razão cíclica(duty cycle)

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  // Le o valor de tensão no pino do potenciometro
  leitura = analogRead(pinoPotenciometro); 

  // converte o valor do potenciômetro, de 0 a 1023, em um valor de 0 a 255
  pwm = map(leitura, 0, 1023, 0, 255);

  // atualiza a razão cíclica do pino 11, variando a intesidade do LED
  analogWrite(pinoLED, pwm);
}

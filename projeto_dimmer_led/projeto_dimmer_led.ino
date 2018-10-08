/*
 * Projeto Dimmer com LED 
 * Usar um potenciômetro para controlar o período com que o um LED pisca.
 */

const int pinoPotenciometro = A0;
const int pinoLED = 12;
const int periodo = 1023;
int tempo_ligado, tempo_desligado; // armazena o valor lido pelo ADC

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tempo_ligado = analogRead(pinoPotenciometro); // Le o valor de tensão no pino do potenciometro
  tempo_desligado = periodo - tempo_ligado; // atribui a variavel tempo_desligado, quanto o tempo LED deverá permanecer desligado.
  digitalWrite(pinoLED, HIGH); // aciona o LED
  // delay
  delayMicroseconds(tempo_ligado); // aguarda o valor lido no pino do potenciômetro em miliseguindos
  digitalWrite(pinoLED, LOW); // apaga o LED
  delayMicroseconds(tempo_desligado); // aguarda o valor lido no pino do potenciômetro em miliseguindos
  Serial.print(tempo_ligado);
  Serial.print("\t");
  Serial.println(tempo_desligado);

}

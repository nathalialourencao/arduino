/*
 * Imprime na Serial o valor de tensão na saída do potenciômetro.
 */

 const int pinoPotenciometro = A0;
 int leitura = 0;
 float tensao = 0.0;
 
void setup() {
 Serial.begin(9600);

 // configura o pino com o potenciometro como entrada
 pinMode(pinoPotenciometro, INPUT);
}

void loop() {
  // le o valor de tensão no pino do potenciometro
  leitura = analogRead(pinoPotenciometro);

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1023.0;

  // imprime valor no plotter serial
  Serial.println(tensao);

  delay(100);
}

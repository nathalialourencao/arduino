/*
 * Detectar a presença de obstáculos a partir de um diodo laser e um LDR
 */

const int pinoLDR = A0; 
int leitura = 0;

void setup() {
  Serial.begin(9600);
  
  // configura o pino com LDR como entrada
  pinMode(pinoLDR, INPUT);
}

void loop() {
  // le o valor de tensão no pino do LDR
  leitura = analogRead(pinoLDR);

  // imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // Tabulação

  // Imptime se existe ou não um obstáculo
  Serial.print("Obstaculo: ");
  if (leitura <= 512){
    Serial.print("Sim");
  }
  else{
    Serial.print("Não");
  }

  Serial.println();

  delay(500);
}

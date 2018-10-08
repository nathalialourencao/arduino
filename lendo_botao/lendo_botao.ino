/*
 * Lendo um botão
 * Acende LED qndo é pressionado e apaga quando o botão é solto
 */
void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT); // configura o pino com o botão como entrada
  pinMode(7, INPUT); // configura o pino com o botão como entrada
  pinMode(12, OUTPUT); // configura o pino com o LED como saída
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(9) == HIGH){ // se o botão estiver pressionado
    digitalWrite(12, HIGH); // acende o LED
  }
  if (digitalRead(7) == HIGH){ // se o botão estiver pressionado
    digitalWrite(12, LOW); // acende o LED
  }
  /*
  else{
    digitalWrite(12, LOW);
  }
  */
  
}

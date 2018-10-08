/*
 * Projeto Alarme
 */

// Inclui a bibliote DHT que possui as funções dos sensores do tipo DHT
#include "DHT.h"

const int pino_dht = 9; // DHT
const int pinoLEDR = 11;
const int pinoLEDG = 12;
const int pinoLEDB = 13;
const int pinoBuzzer = 10;

float temperatura;
float umidade;

DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

void setup() {
  Serial.begin(9600);
  dht.begin(); // inicializa o sensor DHT

  // Configura os pinos dos LEDs e buzzer
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  delay(2000); // 2s (Datasheed) entre uma leitura e outra

  // A leitura da temperatura ou umidade pode levar 250ms
  // O Atraso do sensor pode chegar a 2s
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade

  // Se ocorreu alguma falha durante a leitura
  if(isnan(umidade) || isnan(temperatura)){
    // Acende branco
    digitalWrite(pinoLEDR, HIGH);
    digitalWrite(pinoLEDG, HIGH);
    digitalWrite(pinoLEDB, HIGH);
  }
  else{

    if(temperatura > 26){
      // Acende vermelho e aciona buzzer a 2000Hz
      digitalWrite(pinoLEDR, HIGH);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, LOW);
      tone(pinoBuzzer, 2000);
      delay(1000);
    }

    else if(temperatura > 23 && temperatura < 26){
      // Acende azul e aciona buzzer a 1000Hz
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, HIGH);
      tone(pinoBuzzer, 600);
      delay(500);
    }
    else{
      // Acende verde 
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, HIGH);
      digitalWrite(pinoLEDB, LOW);
    }

    // Imprime o valor de temperatura
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");

    Serial.print("\t");
    Serial.println();

    // Desliga o buzzer
    noTone(pinoBuzzer);
  }

}

/*
 * Mostrar os valores de Temperatura e Umidade no Monitor Serial
 */

// Inclui a bibliote DHT que possui as funções dos sensores do tipo DHT
#include "DHT.h"

const int pino_dht = 9; // sensor conectado
float temperatura;
float umidade;
DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600);
  dht.begin(); // inicializa o sensor DHT
}

void loop() {
  delay(2000); // 2s (Datasheed) entre uma leitura e outra

  // A leitura da temperatura ou umidade pode levar 250ms
  // O Atraso do sensor pode chegar a 2s
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade

  // Se ocorreu alguma falha durante a leitura
  if(isnan(umidade) || isnan(temperatura)){
    Serial.println("Falha na leitura do Sensor DHT!");
  }
  else{
    // Imprime o valor de temperatura
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");

    Serial.print("\t");

    // Imprime o valor da umidade
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");

    Serial.println();
  }

}

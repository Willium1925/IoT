#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

#define R_PIN 32
#define G_PIN 33
#define B_PIN 25

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("DHT11 test");
  dht.begin();

  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  digitalWrite(R_PIN, LOW);
  digitalWrite(G_PIN, LOW);
  digitalWrite(B_PIN, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);

  delay(100);


  if (t < 25){
    analogWrite(G_PIN, 255);
  } else {
    analogWrite(R_PIN, 255);
  }

}

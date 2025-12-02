// preference github

#define BLYNK_PRINT Serial
// 複製自己的
// https://sgp1.blynk.cloud/dashboard/943968/global/devices/1/organization/943968/devices/3677281/dashboard
#define BLYNK_TEMPLATE_ID "TMPL6-jVTyrH3"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "U5732FsD_nri7IvmtdY3C55HczOB2Imt"

#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Zenfone 10_2679";
char password[] = "39393939";

// 使用 P0 當作按鈕輸入腳
const int BUTTON_PIN = 0;

void setup() {
  Serial.begin(115200);

  dht.begin(); // 初始化 DHT
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password); // 初始化 Blynk
  Serial.println("DHT11 + Blynk V5 - Button P0 trigger update!");

  pinMode(BUTTON_PIN, INPUT_PULLUP); // 內建上拉，按下時接地 -> 讀值為 LOW
}

void loop() {
  Blynk.run();

  // 按鍵觸發更新溫濕度（偵測「按下瞬間」）
  static bool lastButtonState = HIGH; // 初始為未按
  bool buttonState = digitalRead(BUTTON_PIN);

  // 偵測從 HIGH -> LOW（按下）
  if (lastButtonState == HIGH && buttonState == LOW) {
    Serial.println("Button P0 pressed, updating temperature and humidity...");

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // 檢查讀值是否有效
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
    } else {
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print("% Temperature: ");
      Serial.print(t);
      Serial.println("°C");

      Blynk.virtualWrite(V5, h);
      Blynk.virtualWrite(V6, t);
    }
  }
  lastButtonState = buttonState;
}





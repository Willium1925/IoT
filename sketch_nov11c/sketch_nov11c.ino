// 12的話，不知為何，需要先全淨空，上傳程式碼後再接元件，不然都上傳失敗
// 改成13, 15似乎就沒事

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(13, INPUT);
//   Serial.begin(115200);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   int light_value = analogRead(13);
//   Serial.println(light_value);
//   delay(100);

// }

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 26
#define SCL_PIN 25

#define LDR_PIN 13   // 光敏電阻輸入腳位（類比）

#define LED_PIN 4    // 燈腳位

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("光感應！");
  delay(1000);
  lcd.clear();
}

void loop() {
  // 讀取光敏電阻的值
  int light_value = analogRead(LDR_PIN);   // 通常範圍 0~4095（ESP32）
  Serial.print("Light value: ");
  Serial.println(light_value);

  // 顯示在 LCD 第一行
  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(light_value);
  lcd.print("    ");  // 防止前一次多餘字元殘留

  // 根據亮度判斷是白天或夜晚
  // 依實際環境調整閾值，例如 2000
  int threshold = 2000;
  lcd.setCursor(0, 1);
  if (light_value < threshold) {
    lcd.print("Night   ");
  } else {
    lcd.print("Morning ");
  }

  // 模擬夜晚開燈（亮度與光線成反比）
  //   光越暗 → light_value 越小 → LED 越亮
  //   analogWrite() 的值範圍是 0~255
  int led_brightness = map(light_value, 0, 4095, 255, 0);  // 反比轉換
  analogWrite(LED_PIN, led_brightness);

  delay(200);
}

int TrigPin = 17;
int EchoPin = 16;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 26
#define SCL_PIN 25

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(14, OUTPUT); // 蜂鳴器腳位
  Serial.begin(115200);

  lcd.setCursor(0, 0);
  lcd.print("倒車雷達啟動中...");
  delay(1000);
  lcd.clear();
}

void loop() {
  unsigned long duration = ping();           // 取得時間差（微秒）
  unsigned long distance = duration / 58;    // 轉成公分（超音波約 340m/s）

  Serial.print("距離: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print("cm");

  // === LCD 條狀距離顯示 ===
  // 每一格代表 10 公分，最多 10 格
  int bars = distance / 10;
  if (bars > 10) bars = 10;  // 最多顯示 10 格
  lcd.setCursor(0, 1);
  for (int i = 0; i < bars; i++) {
    lcd.print("#");
  }

  // === 蜂鳴器音效邏輯 ===
  if (distance < 33) {
    // 危險：小於 33cm，持續嗶
    tone(14, 1000, 1000);   // 長音，這裡還是要寫1000，不然不寫的話會變成抽筋跳針
    //delay(100);
  } else if (distance < 66) {
    // 注意：33~66cm，間隔長嗶
    tone(14, 1000, 500); // 嗶 0.5 秒
    delay(1000);          // 停 1 秒
  } else if (distance < 99) {
    // 警告：66~99cm，間隔短嗶
    tone(14, 1000, 200); // 嗶 0.2 秒
    delay(1000);          // 停 1 秒
  } else {
    // 安全距離：超過 99cm，不嗶
    noTone(14);
    delay(500);
  }

  noTone(14); // 確保蜂鳴器在每次迴圈結束後靜音
}

// === 測距函式 ===
unsigned long ping() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // pulseIn 會回傳 HIGH 的持續時間（單位微秒）
  return pulseIn(EchoPin, HIGH);
}

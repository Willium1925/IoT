// 三顆燈腳位 (bit0, bit1, bit2)
int ledPins[3] = {12, 26, 32};
int counter = 0;             // 計數器，範圍 0~7

// 按鈕腳位
const int buttonPin = 16;
bool lastButtonState = HIGH; // INPUT_PULLUP 預設是 HIGH

void setup() {
  Serial.begin(115200);

  // 設定燈為輸出
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // 初始全滅
  }

  // 設定按鈕為輸入 (內建上拉電阻)
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // 偵測「HIGH → LOW」(按下瞬間)
  if (lastButtonState == HIGH && buttonState == LOW) {
    counter++;
    if (counter > 7) {
      counter = 0; // 超過 7 就歸零
    }

    Serial.print("Counter = ");
    Serial.println(counter);
  }

  lastButtonState = buttonState;

  // 更新三顆燈的狀態 (輸出二進制)
  for (int i = 0; i < 3; i++) {
    int bitValue = (counter >> i) & 1; // 取第 i 個 bit
    digitalWrite(ledPins[i], bitValue ? HIGH : LOW);
  }

  delay(50); // 簡單去抖動
}

void setup() {
  // put your setup code here, to run once: 
  // 初始化區塊
  // 通訊相關，pin就是腳
  // 使用內建的led的那隻腳
  // 想像我是板子，所以我要發訊號給led燈
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // 用數位訊號的形式
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  // 用的空間越大，越消耗電池，所以嵌入式系統通常會講求有效分配，例如使用恰當的變數類型

}

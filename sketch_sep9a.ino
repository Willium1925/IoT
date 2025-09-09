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

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); // 低電位，初始關閉
}

void loop() {
  // put your main code here, to run repeatedly:
  // char command = Serial.read();
  int command = Serial.parseInt();


  for(int i = 0; i < command; i++){
    Serial.println("內建亮");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    Serial.println("內建暗");
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    Serial.println("外建亮");
    digitalWrite(4, HIGH);
    delay(1000);
    Serial.println("外建暗");
    digitalWrite(4, LOW);
    delay(1000);

  }
  



}

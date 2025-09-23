void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(16, INPUT_PULLUP); // 平常是高電位

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); // 低電位，初始關閉

}

void loop() {
  // put your main code here, to run repeatedly:
  bool p16 = digitalRead(16);

  Serial.println(p16);
  delay(500);

  if(p16 == 0) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);

  }
}

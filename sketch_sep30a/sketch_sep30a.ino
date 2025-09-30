void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(16, INPUT_PULLUP); // 平常是高電位



  pinMode(12, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(32, OUTPUT);
  digitalWrite(12, LOW); // 低電位，初始關閉
  digitalWrite(26, LOW); // 低電位，初始關閉
  digitalWrite(32, LOW); // 低電位，初始關閉

}

void loop() {
  // put your main code here, to run repeatedly:
  bool p12 = digitalRead(12);
  bool p26 = digitalRead(26);
  bool p32 = digitalRead(32);

  Serial.println(p12);
  Serial.println(p26);
  Serial.println(p32);
  delay(500);

  if(p12 == 0) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);

  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); // 初始滅


}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 255; i++){
    analogWrite(4, i);
    delay(100);
  }
}

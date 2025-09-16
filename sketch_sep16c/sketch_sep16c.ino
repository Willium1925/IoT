void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // 低電位，初始關閉
}

void loop() {
  // put your main code here, to run repeatedly:
  int command = Serial.parseInt();
  // int command = 0;

  // if(command == 'O') {
  //   Serial.println("LED ON");
  //   digitalWrite(LED_BUILTIN, HIGH);
  //   delay(1000);
  // } else if (command == 'X') {
  // digitalWrite(LED_BUILTIN, LOW);
  // }
  
  for(int i = 0; i < command; i++){
    Serial.println("LED ON");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW); // 低電位，初始關閉
    delay(500);
  }


}

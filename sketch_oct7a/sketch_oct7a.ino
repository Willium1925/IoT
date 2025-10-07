void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13, INPUT);
  pinMode(35, INPUT);

  // 控制switch
  pinMode(16, INPUT_PULLUP); // 平常是高電位

  // 對應x的燈
  pinMode(4, OUTPUT);  
  digitalWrite(4, LOW); // 初始滅

  // 對應y的燈
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW); // 初始滅

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(13);
  int y = analogRead(35);

  // 改成analogWrite可接受的0~255
  float xf = x/16;
  float yf = y/16;

  bool p16 = digitalRead(16);


  // Serial.print("x是：");
  // Serial.println(x);
  // delay(100);
  
  // Serial.print("y是：");
  // Serial.println(y);
  // delay(100);

  // bool p16 = digitalRead(16);

  // Serial.print("按下去是：");
  // Serial.println(p16);
  // delay(100);
  
  if(p16 == 1) {
    analogWrite(4, xf);
    analogWrite(0, yf);
  } else {
      analogWrite(4, 0);
      analogWrite(0, 0);
  }

  


}

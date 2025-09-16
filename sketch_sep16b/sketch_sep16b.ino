void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  // int sum = 0;
  // for(int i = 1; i <= 10; i++) {
  //   sum += 1;
  //   Serial.println("現在的sum是：" + sum)
  // }

  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      Serial.print(j);
      Serial.print("*");
      Serial.print(i);
      Serial.print("=");
      Serial.print(i*j);
      Serial.print("\t");


      // if(i*j < 10){
      //   Serial.print("   ");
      // } else {
      //   Serial.print("  ");
      // }
    }
    Serial.println();
  }

  // Serial.println(sum);
  delay(500);
}

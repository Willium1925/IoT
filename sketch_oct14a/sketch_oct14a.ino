#define R_PIN 32
#define G_PIN 33
#define B_PIN 25

  // 按了開關後計數增加
  int count = 0;

  // 記錄每個顏色的狀態
  int rNow = 0;
  int gNow = 0;
  int bNow = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  // RGB 燈的個別腳位
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);  
  pinMode(B_PIN, OUTPUT);  

  digitalWrite(R_PIN, LOW);
  digitalWrite(G_PIN, LOW);
  digitalWrite(B_PIN, LOW);

  // 開關
  pinMode(16, INPUT_PULLUP); // 平常是高電位

  // 可變電阻
  pinMode(13, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 開關，平時是1，按了變0
  bool p16 = digitalRead(16);

  // 可變電阻的4096轉255，下面配合把 digitalWrite 改成 analogWrite
  int x = analogRead(13);
  float xf = x/16;

  if(p16 == 0) {
    count++;
    delay(500);
  }

  if(count > 2) {
    count = 0;
  }

  Serial.println(p16);
  delay(100);
  Serial.println(count);
  delay(100);


  switch(count){
    case 0:
        analogWrite(R_PIN, xf);
        analogWrite(G_PIN, gNow);
        analogWrite(B_PIN, bNow);
        rNow = xf;
        break;
    case 1:
        analogWrite(R_PIN, rNow);
        analogWrite(G_PIN, xf);
        analogWrite(B_PIN, bNow);
        gNow = xf;
        break;
    case 2:
        analogWrite(R_PIN, rNow);
        analogWrite(G_PIN, gNow);
        analogWrite(B_PIN, xf);
        bNow = xf;
        break;
  }

  /*digitalWrite(R_PIN, HIGH);
  delay(100);
  digitalWrite(R_PIN, LOW);

  digitalWrite(G_PIN, HIGH);
  delay(100);
  digitalWrite(G_PIN, LOW);

  digitalWrite(B_PIN, HIGH);
  delay(100);
  digitalWrite(B_PIN, LOW);*/

    /*switch(count){
    case 0:
        digitalWrite(R_PIN, LOW);
        digitalWrite(G_PIN, LOW);
        digitalWrite(B_PIN, LOW);
        break;
    case 1:
        digitalWrite(R_PIN, HIGH);
        digitalWrite(G_PIN, LOW);
        digitalWrite(B_PIN, LOW);
        break;
    case 2:
        digitalWrite(R_PIN, LOW);
        digitalWrite(G_PIN, HIGH);
        digitalWrite(B_PIN, LOW);
        break;
    case 3:
        digitalWrite(R_PIN, LOW);
        digitalWrite(G_PIN, LOW);
        digitalWrite(B_PIN, HIGH);
        break;
    case 4:
        digitalWrite(R_PIN, HIGH);
        digitalWrite(G_PIN, HIGH);
        digitalWrite(B_PIN, LOW);
        break;
    case 5:
        digitalWrite(R_PIN, LOW);
        digitalWrite(G_PIN, HIGH);
        digitalWrite(B_PIN, HIGH);
        break;
    case 6:
        digitalWrite(R_PIN, HIGH);
        digitalWrite(G_PIN, LOW);
        digitalWrite(B_PIN, HIGH);
        break;
    case 7:
        digitalWrite(R_PIN, HIGH);
        digitalWrite(G_PIN, HIGH);
        digitalWrite(B_PIN, HIGH);
        break;       
  }*/

}

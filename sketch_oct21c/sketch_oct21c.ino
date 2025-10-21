int TrigPin = 17;
int EchoPin = 16;

#define R_PIN 32
#define G_PIN 33

void setup() {
  // put your setup code here, to run once:
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(115200);

  // RGB 燈的個別腳位
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);

  digitalWrite(R_PIN, LOW);
  digitalWrite(G_PIN, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  // 公分，總之就是可以算出距離
  unsigned long distance = ping()/58;

  Serial.println(distance);
  Serial.println(" 公分");
  delay(100);

  analogWrite(G_PIN, distance);
  analogWrite(R_PIN, 1218-distance);

  


}
unsigned long ping(){
  // 方形波的低5秒，高10秒，再回到低，等於打出一個10微秒的波
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // 會自動計算打出去後到接收回覆的瞬間的時間差
  return pulseIn(EchoPin, HIGH);
}
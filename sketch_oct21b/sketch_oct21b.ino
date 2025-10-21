int TrigPin = 17;
int EchoPin = 16;

void setup() {
  // put your setup code here, to run once:
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(115200);



}

void loop() {
  // put your main code here, to run repeatedly:
  // 公分，總之就是可以算出距離
  unsigned long distance = ping()/58;

  Serial.println(distance);
  Serial.println(" 公分");
  delay(100);
  


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
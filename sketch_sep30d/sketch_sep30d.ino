void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(13);
  Serial.println(val);
  delay(100);
}

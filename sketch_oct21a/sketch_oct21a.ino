#define R_PIN 32
#define G_PIN 33
#define B_PIN 25



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  digitalWrite(R_PIN, LOW);
  digitalWrite(G_PIN, LOW);
  digitalWrite(B_PIN, LOW);

    // 開關
  pinMode(16, INPUT_PULLUP); // 平常是高電位

}

void loop() {
  // put your main code here, to run repeatedly:
    
  // 開關，平時是1，按了變0
  bool p16 = digitalRead(16);
  Serial.println(p16);


  if(p16 == 0) {
  int rr = random(255);
  int gr = random(255);
  int br = random(255);

  analogWrite(R_PIN, rr);
  analogWrite(G_PIN, gr);
  analogWrite(B_PIN, br);

  }



}

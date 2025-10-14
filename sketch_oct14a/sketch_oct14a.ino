#define R_PIN 32
#define G_PIN 33
#define B_PIN 25

  int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);  
  pinMode(B_PIN, OUTPUT);  

  digitalWrite(R_PIN, LOW);
  digitalWrite(G_PIN, LOW);
  digitalWrite(B_PIN, LOW);

  pinMode(16, INPUT_PULLUP); // 平常是高電位


}

void loop() {
  // put your main code here, to run repeatedly:
  bool p16 = digitalRead(16);

  if(p16 == 0) {
    count++;
    delay(500);
  }

  if(count > 7) {
    count = 0;
  }

  Serial.println(p16);
  delay(100);

  switch(count){
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

}

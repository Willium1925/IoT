#define NOTE_C6 1047
#define NOTE_D6 1175
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1976
#define NOTE_C7 2093

int melody[] = {
NOTE_C6, NOTE_C6, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_A6, NOTE_G6,
NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_D6, NOTE_D6, NOTE_C6,
NOTE_G6, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_D6,
NOTE_G6, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_D6,
NOTE_C6, NOTE_C6, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_A6, NOTE_G6
};

int noteDurations[] = {
500, 500, 500, 500, 500, 500, 1000,
500, 500, 500, 500, 500, 500, 1000,
500, 500, 500, 500, 500, 500, 1000,
500, 500, 500, 500, 500, 500, 1000,
500, 500, 500, 500, 500, 500, 1000
};

void setup() {
  pinMode(14, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    tone(14, melody[i], noteDurations[i]);
    delay(noteDurations[i] * 1.3); // 稍微拉開間距
  }
  delay(2000); // 播完後暫停2秒再重播
}
hw_timer_t * timer = NULL;

// 平行化（多線程），代替delay以，讓板子的休眠期間的不作用不作用
void ARDUINO_ISR_ATTR interrupt_func(){
  digitalWrite(0, !digitalRead (0));
}

void setup() {
  pinMode(17, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  digitalWrite (4, LOW);
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);

  timer = timerBegin(1000000);
  timerAttachInterrupt(timer, &interrupt_func);
  timerAlarm(timer, 5000000, true, 0);
}

  bool flag = 0;


void loop() {

  //digitalWrite(0, HIGH);
  //delay(5000);
  bool button_value = digitalRead (17);

  if(!button_value && !flag){
    flag = 1;
    digitalWrite (4, HIGH);
  } else if (button_value && flag){
    flag = 0;
    digitalWrite(4, LOW);
  }

  //digitalWrite(0, LOW);
  //delay(5000);
}
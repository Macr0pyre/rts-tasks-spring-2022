int ledMas[] = {3, 5, 6, 9, 10};
unsigned long intervalMas[] = {500000, 170000, 700, 70, 35};

int ledState[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long previousMilliseconds[] = {0, 0, 0, 0, 0};

void setup() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    pinMode(ledMas[ledN], OUTPUT);
  }
}

void loop() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    unsigned long currentMilliseconds = micros();
    if (currentMilliseconds - previousMilliseconds[ledN] >= intervalMas[ledN]) {
      previousMilliseconds[ledN] = currentMilliseconds;

      if (ledState[ledN] == LOW) {
        ledState[ledN] = HIGH;
      }
      else {
        ledState[ledN] = LOW;
      }
      digitalWrite(ledMas[ledN], ledState[ledN]);
    }
  }
}

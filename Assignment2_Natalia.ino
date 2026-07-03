// Task 5: Beeping Countdown
// Combines the buzzer (Tasks 1-2) and 7-segment display (Tasks 3-4)

int segmentPins[] = {2, 3, 4, 5, 6, 7, 9}; // a, b, c, d, e, f, g
int numSegments = 7;
int buzzerPin = 8;

// Digit patterns copied from Task 4
byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

// showDigit function — copied from Task 4
void showDigit(int n) {
  if (n < 0 || n > 9) return;
  for (int i = 0; i < numSegments; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT); // set up the buzzer

  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT); // set up each segment
  }

  Serial.println("=== Beeping Countdown Starting ===");

  int count = 9;

  while (count >= 1) {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);
    tone(buzzerPin, 1000, 200); // short beep

    delay(1000);
    count = count - 1;
  }

  showDigit(0);
  tone(buzzerPin, 1500, 1000); // longer completion tone

  Serial.println("=== Countdown Complete ===");
}

void loop() { }
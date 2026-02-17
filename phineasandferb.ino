int ENA = 5;  // PWM Speed Pin
int IN1 = 9; // Direction Pin 1
int IN2 = 10; // Direction Pin 2
int leds = 13; // leds on Pin 13

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(leds, OUTPUT);
}

void loop() {
  // Rotate Forward at Full Speed
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255); // Max Speed (0-255)
  digitalWrite(leds, HIGH);
  delay(3000); // Run for 3 seconds

  // digitalWrite(IN1, LOW);
  // digitalWrite(IN2, HIGH);
  // analogWrite(ENA, 255);
  // delay(1000);
}


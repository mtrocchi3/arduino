int analogPin = A0;   // KY-037 analog interface
int ledRed = 5;
int ledGreen = 6;
int ledBlue = 4;
int peakToPeak = 0;
int led1 = 2;
int led2 = 10;
int led3 = 11;

void setup()
{
  pinMode(analogPin, INPUT);    
  Serial.begin(9600);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
   digitalWrite(led1, HIGH);
   digitalWrite(led2, HIGH);
   digitalWrite(led3, HIGH);
   setColor(255, 0, 0);
   if (peakToPeak > 10) {
      digitalWrite(led1, LOW);
   }
   if (peakToPeak > 100) {
      digitalWrite(led2, LOW);
   }
   if (peakToPeak > 300) {
      digitalWrite(led3, LOW);
   }
   if (peakToPeak > 500) {
      setColor(0, 255, 0);
   }

  // code from Chase
   unsigned int sampleWindow = 50; // sample window in milliseconds
   unsigned int signalMax = 0;
   unsigned int signalMin = 1023;
   unsigned long startMillis = millis();
   while (millis() - startMillis < sampleWindow) {
      int sample = analogRead(analogPin); // read from AO pin
      if (sample > signalMax) {
         signalMax = sample;
      }
      if (sample < signalMin) {
         signalMin = sample;
      }
   }
   peakToPeak = signalMax - signalMin; // represents signal amplitude
   Serial.println(peakToPeak);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(ledRed, redVal);
  analogWrite(ledGreen, greenVal);
  analogWrite(ledBlue, blueVal);
}

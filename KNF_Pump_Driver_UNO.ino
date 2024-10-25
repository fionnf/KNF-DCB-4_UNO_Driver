// Pin Definitions
const int pumpPowerPin = 9; // PWM output for controlling pump speed (DCB-4 model)

void setup() {
  pinMode(pumpPowerPin, OUTPUT);
}

void loop() {
  int speed = 128; // Set speed from 0 (off) to 255 (full speed)
  
  analogWrite(pumpPowerPin, speed); // Send PWM signal to control speed
  delay(5000); // Run for 5 seconds
  
  analogWrite(pumpPowerPin, 0); // Turn off pump
  delay(5000); // Off for 2 seconds
}
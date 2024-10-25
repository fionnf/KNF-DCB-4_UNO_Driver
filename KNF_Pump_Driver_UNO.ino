const int pumpControlPin = 9; // PWM pin for control signal
int modelType = 0; // 0 for KP, 1 for KT

void setup() {
  pinMode(pumpControlPin, OUTPUT);
  Serial.begin(9600); // For debugging flow rate
}

void loop() {
  int pwmValue = 128; // Example PWM value (range 0-255)
  float controlVoltage = pwmValue * (5.0 / 255.0); // Convert PWM to control voltage

  // Calculate flow rate based on model
  float flowRate;
  if (modelType == 0) { // KP model
    flowRate = 30 * controlVoltage; // Linear relationship for KP
  } else { // KT model
    flowRate = 26 * controlVoltage; // Linear relationship for KT
  }

  // Output PWM signal to control pump
  analogWrite(pumpControlPin, pwmValue);
  
  // Print flow rate for monitoring
  Serial.print("Control Voltage: ");
  Serial.print(controlVoltage);
  Serial.print(" V, Flow Rate: ");
  Serial.print(flowRate);
  Serial.println(" mL/min");
  
  delay(1000); // Run this every second
}
const int pumpControlPin = 9; // PWM pin for control signal
int modelType = 1; // 0 for KP, 1 for KT (set based on pump label)

// Desired flow rate in mL/min
float desiredFlowRate = 10; // Example value, adjust as needed

void setup() {
  pinMode(pumpControlPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Adjust the starting point of the control voltage (0 at 0.5V)
  float controlVoltage;
  if (modelType == 0) { // KP model
    controlVoltage = (desiredFlowRate / 33.33) + 0.5; // Adjust for KP
  } else { // KT model
    controlVoltage = (desiredFlowRate / 28.89) + 0.5; // Adjust for KT
  }

  // Ensure the control voltage is within the allowable range (0.5V to 5V)
  if (controlVoltage > 5.0) {
    controlVoltage = 5.0; // Cap voltage at 5V
  }
  if (controlVoltage < 0.5) {
    controlVoltage = 0.5; // Minimum control voltage is 0.5V
  }

  // Calculate the corresponding PWM value (0-255) based on control voltage (from 0.5V to 5V)
  int pwmValue = (controlVoltage - 0.5) * (255.0 / 4.5); // Adjust for 0.5V starting point

  // Output PWM signal to control pump
  analogWrite(pumpControlPin, pwmValue);
  
  // Print details for monitoring
  Serial.print("Desired Flow Rate: ");
  Serial.print(desiredFlowRate);
  Serial.print(" mL/min, Control Voltage: ");
  Serial.print(controlVoltage);
  Serial.print(" V, PWM Value: ");
  Serial.println(pwmValue);
  
  delay(1000); // Wait for 1 second before repeating
}
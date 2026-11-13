/*
  Smart Retractable Safety Knife - Working Prototype Logic
  This firmware monitors a capacitive grip sensor and a pressure sensor.
  If the grip is lost, or if pressure suddenly drops while the blade is deployed (indicating a slip),
  the solenoid retracts the blade instantly to prevent injury.
*/

// --- Pin Definitions ---
const int fsrPin = A0;           // Force Sensitive Resistor (Detects cutting pressure)
const int gripSensorPin = 2;     // Capacitive touch sensor (Detects hand grip)
const int solenoidPin = 9;       // Triggers the retraction mechanism (via MOSFET)
const int deployButtonPin = 3;   // Button to initially deploy the blade

// --- Thresholds & Timers ---
const int pressureThreshold = 150; // Minimum analog value to be considered "cutting"
bool bladeDeployed = false;
bool isCutting = false;

void setup() {
  Serial.begin(115200);
  
  pinMode(fsrPin, INPUT);
  pinMode(gripSensorPin, INPUT);
  pinMode(deployButtonPin, INPUT_PULLUP);
  
  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, LOW); // Solenoid off by default (blade retracted)
  
  Serial.println("System Initialized: Smart Safety Knife");
}

void loop() {
  // Read sensor values
  int pressureValue = analogRead(fsrPin);
  bool isGripped = digitalRead(gripSensorPin);
  bool deployPressed = (digitalRead(deployButtonPin) == LOW);
  
  isCutting = (pressureValue > pressureThreshold);

  // LOGIC 1: Blade Deployment
  // Only allow deployment if the handle is securely gripped
  if (deployPressed && isGripped && !bladeDeployed) {
    deployBlade();
  }

  // LOGIC 2: Safety Retraction (Fail-safes)
  if (bladeDeployed) {
    // Condition A: User drops or lets go of the knife
    if (!isGripped) {
      Serial.println("SAFETY TRIGGER: Grip lost. Retracting blade.");
      retractBlade();
    }
    
    // Condition B: Sudden slip (pressure drops rapidly while blade was deployed)
    // Note: In a full production model, this requires derivative logic (rate of pressure change).
    // For this prototype, if it drops below threshold after cutting began, it retracts.
    else if (!isCutting && deployPressed == false) {
      Serial.println("SAFETY TRIGGER: Pressure lost (slip detected). Retracting blade.");
      retractBlade();
    }
  }
  
  delay(10); // Polling delay for stability
}

void deployBlade() {
  bladeDeployed = true;
  // Engage solenoid to release safety lock and allow manual/motor deployment
  digitalWrite(solenoidPin, HIGH);
  Serial.println("Status: Blade DEPLOYED.");
  delay(200); // Debounce
}

void retractBlade() {
  bladeDeployed = false;
  // Cut power to solenoid, causing spring-loaded fail-safe to yank blade back instantly
  digitalWrite(solenoidPin, LOW);
  Serial.println("Status: Blade RETRACTED.");
  delay(500); // Prevent immediate re-deployment
}
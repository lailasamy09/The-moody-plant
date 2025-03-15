#include <LiquidCrystal.h>

// Pin configuration
const int soilMoisturePin = A0;  // Analog pin connected to the soil moisture sensor
const int redPin = 6;            // Red LED pin
const int greenPin = 7;          // Green LED pin
const int bluePin = 8;           // Blue LED pin

// Create LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Mood-Reading Plant");
  
  // Initialize LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start the serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the moisture value (0-1023)
  int moistureLevel = analogRead(soilMoisturePin);

  // Print moisture level to the serial monitor for debugging
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Clear the LCD screen
  lcd.clear();
  
  // Display mood and control LEDs based on moisture level
  if (moistureLevel > 600) {  // High moisture = Happy mood
    lcd.print("Sad Plant :(");
    setMood(0, 255, 0);  // Green LED for happy
  } else if (moistureLevel > 400) {  // Medium moisture = Neutral mood
    lcd.print("Neutral Plant :| ");
    setMood(255, 255, 0);  // Yellow LED for neutral
  } else {  // Low moisture = Sad mood
    lcd.print("Happy Plant :)");
    setMood(255, 0, 0);  // Red LED for sad
  }

  // Wait for a while to update the display
  delay(1000);
}

// Function to set the RGB LED color
void setMood(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

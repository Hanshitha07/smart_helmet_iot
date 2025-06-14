#include <LiquidCrystal.h>
#include <DHT.h>

// LCD pin config: RS=12, EN=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// DHT11 config
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Sensors and actuators
#define MQ2_PIN A0
#define MQ4_PIN A1
#define TRIG_PIN 8
#define ECHO_PIN 9
#define BUZZER_PIN 10
#define RELAY_PIN 6

void setup() {
  // Initialize pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RELAY_PIN, LOW);

  // Initialize LCD and Serial
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);

  // Show startup message
  lcd.setCursor(0, 0);
  lcd.print("Smart Helmet");
  lcd.setCursor(0, 1);
  lcd.print("System Start...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int smokeVal = analogRead(MQ2_PIN);
  int methaneVal = analogRead(MQ4_PIN);
  float distance = getDistance();

  Serial.print("Temp: "); Serial.print(temp); Serial.print(" C, ");
  Serial.print("Humidity: "); Serial.print(hum); Serial.print(" %, ");
  Serial.print("Smoke: "); Serial.print(smokeVal); Serial.print(", ");
  Serial.print("Methane: "); Serial.print(methaneVal); Serial.print(", ");
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");

  // Display temp and humidity
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp, 1);
  lcd.print("C H:");
  lcd.print(hum, 0);

  bool danger = false;
  String message = "";

  // Detect gas or object danger
  if (smokeVal > 100) {
    danger = true;
    message = "Smoke Alert!";
  } else if (methaneVal > 300) {
    danger = true;
    message = "Methane Alert!";
  } else if (distance < 15) {
    danger = true;
    message = "Obj Close!";
  }

  // If danger, activate buzzer and relay
  if (danger) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(message);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("All Safe       ");
  }

  delay(1000);  // Update every second
}

// Get distance from ultrasonic sensor
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2.0;
  return distance;
}
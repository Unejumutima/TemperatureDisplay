#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// -------- DHT setup --------
#define DHTPIN 2
#define DHTTYPE DHT11
#define DHTPOWER 3   // 🔥 NEW: Digital pin used as 5V supply

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String nameText = "Ikirezi Unejumutima Honorine";

void setup() {
  Serial.begin(9600);

  // 🔥 NEW: turn pin 3 into "5V power source"
  pinMode(DHTPOWER, OUTPUT);
  digitalWrite(DHTPOWER, HIGH);

  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float temp = dht.readTemperature();

  // Check sensor
  if (isnan(temp)) {
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error   ");
    return;
  }

  // -------- LCD Row 1 (Scrolling Name) --------
  static int pos = 0;

  String displayName = nameText + "   ";
  if (displayName.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(displayName);
  } else {
    lcd.setCursor(0, 0);
    lcd.print(displayName.substring(pos, pos + 16));

    pos++;
    if (pos > displayName.length() - 16) pos = 0;
  }

  // -------- LCD Row 2 (Temperature) --------
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C   ");

  // -------- Serial Output --------
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  delay(1000);
}
#include <LiquidCrystal.h>
#include <DHT.h>

// Pins used by standard 16x2 LCD Shields
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define DHTPIN 2       // Connect sensor Data pin to Digital Pin 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Temp Reader");
  delay(1000);
  lcd.clear();
}

void loop() {
  delay(2000); // Wait 2 seconds between updates

  float tempF = dht.readTemperature(true); // Fahrenheit
  float humidity = dht.readHumidity();

  if (isnan(tempF) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    return;
  }

  // Row 1: Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempF, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("F   ");

  // Row 2: Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 0);
  lcd.print("%   ");
}

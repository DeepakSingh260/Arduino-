#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN , DHTTYPE);

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  
  dht.begin();
}

void loop() {
  delay(1000);
 float h = dht.readHumidity();
 float t= dht.readTemperature();
 lcd.setCursor(2,0);
 lcd.print("Humidity: ");
 lcd.print(h);
 lcd.setCursor(2,1);
 lcd.print("Temp: ");
 lcd.print(t);

}

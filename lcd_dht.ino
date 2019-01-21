#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8  //menggunakan pin 1 untuk pemasangan sensornya
#define DHTTYPE DHT11 //memilih tipe DHT11, bisa diubah menjadi DHT22, DHT21

DHT dht(DHTPIN, DHTTYPE);

// Setting LCD RS E D4 D5 D6 D7
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);
const int buzzer = 4;

//Icon di arduino
byte icoterm[8] = //icon for termometer
{
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte icohum[8] = //icon for humidity
{
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110,
};

void setup() {
  // pilih LCD 16 x 2

  lcd.begin(16, 2);
  dht.begin();

  lcd.setCursor(2, 0);
  lcd.print("SENSOR CUACA");
  lcd.setCursor(0, 1);
  lcd.print("Inisialisasi....");

  delay(5000);
  tone(buzzer, 3000);
  delay(100);
  tone(buzzer, 2000);
  delay(100);
  tone(buzzer, 1000);
  delay(100);

  noTone(buzzer);
}

void loop() {

  int kelembaban = dht.readHumidity(); //menyimpan nilai Humidity pada variabel kelembaban
  int suhu = dht.readTemperature(); //menyimpan nilai Temperature pada variabel suhu
  if (suhu < 25 && kelembaban >= 80) {
    tone(buzzer, 100);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Berembun/Kabut");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  } else if (suhu >= 25 && suhu <= 29 && kelembaban >= 80) {
    tone(buzzer, 300);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Mendung/Hujan");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  } else if (suhu > 29 && kelembaban >= 80) {
    tone(buzzer, 500);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Hujan Lebat");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  } else if (suhu < 25 && kelembaban < 80) {
    tone(buzzer, 100);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Dingin/Sejuk");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  } else if (suhu >= 25 && suhu <= 29 && kelembaban < 80) {
    tone(buzzer, 300);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Berawan/Cerah");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  } else if (suhu > 29 && kelembaban < 80) {
    tone(buzzer, 500);
    delay(50);
    noTone(buzzer);
    lcd.clear();
    lcd.createChar(1, icoterm);
    lcd.createChar(2, icohum);
    lcd.setCursor(0, 0);
    lcd.print("Cerah/Panas");
    lcd.setCursor(0, 1);
    lcd.write(2);
    lcd.setCursor(2, 1);
    lcd.print(kelembaban);
    lcd.print("%");
    lcd.setCursor(9, 1);
    lcd.write(1);
    lcd.setCursor(11, 1);
    lcd.print(suhu);
    lcd.print((char)223);
    lcd.print("C");
  }
  delay(300000);
}

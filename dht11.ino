#include "DHT.h"            

const int DHTPIN = 2;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
int LDR = A0;
int value;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();         // Khởi động cảm biến
  pinMode(0,OUTPUT);
}

void loop() {
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ

  Serial.print("Nhiet do: ");
  Serial.println(t);               //Xuất nhiệt độ
  Serial.print("Do am: ");
  Serial.println(h);               //Xuất độ ẩm
  
  Serial.println();                //Xuống hàng
  delay(1000);                     //Đợi 1 giây

    value = analogRead(LDR);
  // put your main code here, to run repeatedly:
  Serial.print("Value ");
  Serial.println();
  Serial.println(value);
  delay(1000);
}

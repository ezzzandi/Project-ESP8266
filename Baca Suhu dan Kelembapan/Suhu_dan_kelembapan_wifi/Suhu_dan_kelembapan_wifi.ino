#include <SimpleDHT.h>
#include <ESP8266WiFi.h>

/* pin yang dikoneksikan dengan DHT22:
      VCC: 3.3V
      GND: GND
      DATA: 5
**/
int pinDHT22 = 5;
SimpleDHT22 dht22(pinDHT22);

//Deklarasi variabel untuk menyimpan data
float suhu;
float kelembapan;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Pengecekan sampel DHT22...");


  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&suhu, &kelembapan, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Gagal membaca sensor, err="); Serial.println(err); delay(2000);
    return;
  }

  Serial.print("Sampel OK: ");
  Serial.print((float)suhu); Serial.print(" *C, ");
  Serial.print((float)kelembapan); Serial.println(" RH%");

  // Delay 2.5 detik
  delay(2500);
}

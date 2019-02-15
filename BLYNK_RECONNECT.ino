
#define BLYNK_PRINT Serial
#define sure 20
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;



char auth[] = "..................."; // BLYNK TOKEN




char ssid[] = "................";     // WiFi adı
char pass[] = "................";     // WiFi şifresi



bool wifidurum = true;




void setup()
{
  Serial.begin(9600);
  WiFi.begin (ssid, pass);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, uyari);
  timer.setInterval(100L, kontrol);
}





void uyari()
{

  if (wifidurum)
  {
    // KENDİ İSTEDİĞİM İŞLEMLERİ YAPTIRDIĞIM YER
  }
  
}



void loop()
{
  if (Blynk.connected())
  {
    Blynk.run();
    timer.run();
    uyari ();
  }

  else
  {
    wifidurum = false;
    kontrol ();
  }
}




void kontrol()
{
  if (!wifidurum)
  {
    while ( WiFi.status () != WL_CONNECTED )
    {
      Serial.println ("baglanti koptu");
      delay (500);
    }
    WiFi.begin (ssid, pass);
    Blynk.begin(auth, ssid, pass);
  }
  wifidurum = true;
}

/*
 * GCI READ TIME FROM SERVER
 * THIS PROJECT HAS NO RELEVANCE OUTSIDE GCI
 * (C) ADITYA PREREPA 11/19/18
 */

#include <ESP8266WiFi.h>
#include <time.h>

int ledPin = 2;
// Built in LED
const char* wifi_name = "onhub";
const char* pass = "ekchotaghar";

int zone = 4 * 3600;
// Im in Fremont, California, so UTC-8 is my time zone.
// This changes.
int dst = 0;

void setup() {
  
  pinMode(ledPin,OUTPUT);
  // Set ledPin to OUTPUT
  digitalWrite(ledPin,LOW);
  // Start it off LOW
  Serial.begin(115200);
  // Begin serial monitor at baud rate 11520
  
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println(wifi_name);

  WiFi.begin(wifi_name,pass);

  Serial.println();
  Serial.print("Connecting");

  // Bit of a perk I did here. While its initializing
  // the connection, you get "Connecting-----" after ever
  // quarter of a second. 
  while(WiFi.status() != WL_CONNECTED) {
      delay(250);
      Serial.print("-");        
  }

  digitalWrite(ledPin,HIGH);
  Serial.println();
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  // Gives the local IP of the NodeMCU device, and 
  // you can only use this within your network. 
  // Plug this IP into your web brower to get 
  // The interface in some situations
  Serial.println(WiFi.localIP() );

  configTime(zone, dst, "pool.ntp.org","time.nist.gov");
  // Gets time from internet. Inputs are the two websites
  // That give you the time, and you enter your timezone, 
  // and dst. Timezone is just <your_UTC_zone> * 3600. dst is 0.
  Serial.println("\n Got for Internet time");
  /*
  while (!time (nullptr)) {
    Serial.print("-");
    delay(500);
  }
  */
  
  Serial.println("\n Time recieved. Great job, not messed up :)");   

}

void loop() {
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  delay(1000);
}

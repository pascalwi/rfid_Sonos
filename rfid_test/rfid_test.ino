#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN D8
#define RST_PIN D3
const int ledPin = D4;
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
 
void setup(void){
SPI.begin();
rfid.PCD_Init();
 
Serial.begin(115200);
Serial.println("Boot RFID-Reader...");
 
pinMode(ledPin, OUTPUT);
}
 
void loop(void){
digitalWrite(ledPin,LOW);
handleRFID();
}
 
void handleRFID() {
if (!rfid.PICC_IsNewCardPresent()) return;
if (!rfid.PICC_ReadCardSerial()) return;
Serial.println(printHex(rfid.uid.uidByte, rfid.uid.size));
 
digitalWrite(ledPin,HIGH);
delay(500);
digitalWrite(ledPin,LOW);
 
rfid.PICC_HaltA();
rfid.PCD_StopCrypto1();
}
 
String printHex(byte *buffer, byte bufferSize) {
String id = "";
for (byte i = 0; i < bufferSize; i++) {
id += buffer[i] < 0x10 ? "0" : "";
id += String(buffer[i], HEX);
}
return id;
}

#include <iostream>
#include <string>

#include <SPI.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <Arduino.h>

#include "devices/peripherals/keyboard/keyboard.hpp"
#include "devices/peripherals/buttons/buttons.hpp"
#include "devices/rfid/rfid.hpp"
#include "devices/peripherals/peripherals.hpp"
#include "devices/queue/queue.hpp"

/* Peripheral instances */
Keyboard kb;    // Instance of the keyboard peripheral
Button btn;     // Instance of the button peripheral
RFID rf(SS_PIN, RST_PIN);   // Instance of the RFID peripheral

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  SPI.begin();          // Initialize SPI bus
  rf.init();            // Initialize RFID
  kb.init();            // Initialize keyboard
  btn.init();           // Initialize button
}

void loop() {

  char read = kb.keypad.getKey();  // Read a key from the keyboard

  // Check if a new RFID card is present and read its serial if available
  if (rf.reader.PICC_IsNewCardPresent() && rf.reader.PICC_ReadCardSerial()) {
    rf.read_tag();   // Read RFID tag details
    delay(1000);
    delay(2000);
    Serial.println("1) To open the door, approach the TAG to the reader");
    Serial.println("2) To register cards, press any key");
    Serial.println();
  } else if (btn_intr) {   // Check if the button is pressed or the password is correct
    rf.handle_events(&btn);   // Handle events based on button input
    btn_intr = false;         // Reset button interrupt flag
    Serial.println();
    Serial.println("1) To open the door, approach the TAG to the reader");
    Serial.println("2) To register cards, press any key");
    Serial.println();
  } else if (read != NULL) {
    rf.handle_events(&kb);   // Handle events based on keyboard input
    Serial.println();
    Serial.println("1) To open the door, approach the TAG to the reader");
    Serial.println("2) To register cards, press any key");
    Serial.println();
  }
  
  // Instruct the PICC when in the ACTIVE state to go to a "stop" state
  rf.reader.PICC_HaltA(); 
  
  // Stop the encryption of the PCD, should be called after authenticated communication, 
  // otherwise, new communications cannot be initiated
  rf.reader.PCD_StopCrypto1();
}

#include <SPI.h>
#include <MFRC522Extended.h>
#include <Arduino.h>

#include "devices/peripherals/keyboard/keyboard.hpp"
#include "devices/peripherals/buttons/buttons.hpp"
#include "devices/rfid/rfid.hpp"
#include "devices/peripherals/peripherals.hpp"
#include "devices/queue/queue.hpp"
#include "devices/clockCalendar/clockCalendar.hpp"

/* Peripheral instances */
Keyboard kb;    // Instance of the keyboard peripheral
Button btn;     // Instance of the button peripheral
RFID rf(SS_PIN, RST_PIN);   // Instance of the RFID peripheral
ClockCalendar clk;
Queue list;

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  SPI.begin();          // Initialize SPI bus
  clk.init();         // Initialize clockCalendar
  rf.init();            // Initialize RFID
  init_keyboard(kb);            // Initialize keyboard
  init_button(btn);           // Initialize button
}

void loop() {

  char read = kb.keypad.getKey();  // Read a key from the keyboard

  // Check if a new RFID card is present and read its serial if available
  if (rf.reader.PICC_IsNewCardPresent() && rf.reader.PICC_ReadCardSerial()) {
    rf.read_tag();   // Read RFID tag details
    delay(500);
    
    uint8_t id[10];    // Declare an array 'id' to store a UID (10 bytes)
    char char_id[2 * sizeof(id) + 1];    // Declare a char array 'char_id' to store the hexadecimal representation of the UID
    // Copy each byte of the UID from the RFID module to the 'id' array
    for (int i = 0; i < 10; i++) {
        id[i] = rf.reader.uid.uidByte[i];
    }
    std::ostringstream hexStream;    // Converting to hexadecimal
    hexStream << std::hex << std::setfill('0');
    // Loop through each byte in 'id' array and append its hexadecimal representation to the stringstream
    for (int i = 0; i < 10; ++i) {
        hexStream << std::setw(2) << static_cast<int>(id[i]);
    }
    std::string hexString = hexStream.str();   // Convert the stringstream to a string containing the hexadecimal representation of the UID
    list.insert(hexString + " - Status:" + rf.log_label );   // Insert the hexadecimal UID followed by " Entry" into the queue

    delay(500);
    list.printLog();   // Print the log entries in the queue
    delay(2000);
    //Serial.println("1) To open the door, approach the TAG to the reader");
    //Serial.println("2) To register cards, press any key");
    //Serial.println();
  } else if (btn_intr) {   // Check if the b
  // Button is pressed or the password is correct
    rf.handle_events(&btn);   // Handle events based on button input
    btn_intr = false;         // Reset button interrupt flag

    list.insert(rf.log_label);   // Insert the hexadecimal UID followed by " Entry" into the queue
    delay(500);
    list.printLog();   // Print the log entries in the queue

    //Serial.println();
    //Serial.println("1) To open the door, approach the TAG to the reader");
    //Serial.println("2) To register cards, press any key");
    //Serial.println();
  } else if (read != NULL) {
    rf.handle_events(&kb);   // Handle events based on keyboard input
    //Serial.println();
    //Serial.println("1) To open the door, approach the TAG to the reader");
    //Serial.println("2) To register cards, press any key");
    //Serial.println();
  }
  
  // Instruct the PICC when in the ACTIVE state to go to a "stop" state
  rf.reader.PICC_HaltA(); 
  
  // Stop the encryption of the PCD, should be called after authenticated communication, 
  // otherwise, new communications cannot be initiated
  rf.reader.PCD_StopCrypto1();

}

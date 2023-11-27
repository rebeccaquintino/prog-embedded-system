#include "../rfid/rfid.hpp"

// Define constants
#define SIZE_BUFFER 18
#define SIZE_BUFFER_DEFULT 8
#define MAX_SIZE_BLOCK 16
#define LEDG_PIN 4
#define LEDR_PIN 2

// Key object used for authentication
MFRC522::MIFARE_Key key;

// Authentication status code
MFRC522::StatusCode status;

// Initialize RFID module
void RFID::init() {
    // Set pin modes for LEDs
    pinMode(LEDG_PIN, OUTPUT);
    pinMode(LEDR_PIN, OUTPUT);

    // Initialize RFID reader
    reader.PCD_Init();

    // Initial messages on the serial monitor
    //Serial.println();
    //Serial.println("1) To open the door, approach the TAG to the reader");
}

/* Read to RFID tag*/
void RFID::read_tag() {
    // Dump technical details of the card/tag
    //reader.PICC_DumpDetailsToSerial(&(reader.uid));

    // Prepare the key - all keys are set to FFFFFFFFFFFFh (Factory default)
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    // Buffer for storing read data
    byte buffer[SIZE_BUFFER] = {0};

    // Block to operate on
    byte block = 1;
    byte dataSize = SIZE_BUFFER;

    // Authenticate the block
    status = reader.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(reader.uid));
    if (status != MFRC522::STATUS_OK) {
        // Authentication failed, print error message and indicate failure
        //Serial.print(F("Authentication failed: "));
        //Serial.println(reader.GetStatusCodeName(status));
        //Serial.println();
        digitalWrite(LEDR_PIN, HIGH);
        delay(2000);
        digitalWrite(LEDR_PIN, LOW);
        return;
    }

    // Read data from the block
    status = reader.MIFARE_Read(block, buffer, &dataSize);
    byte* id = &buffer[0];
    byte correctId[MAX_SIZE_BLOCK] = "spacelab";

    // Set default values for the correct ID
    for (byte i = SIZE_BUFFER_DEFULT; i < MAX_SIZE_BLOCK; i++) {
        correctId[i] = ' ';
    }
    bool wrongId = false;

    // Check if the read ID matches the correct ID
    for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++) {
        if (id[i] != correctId[i]) {
            wrongId = true;
        }
    }

    if ((status != MFRC522::STATUS_OK) || (wrongId)) {
        // Reading failed or incorrect ID, print error message and indicate failure
        //Serial.println(F("Door did not open."));
        digitalWrite(LEDR_PIN, HIGH);
        delay(2000);
        digitalWrite(LEDR_PIN, LOW);

        log_label = " no entry";

    } else {
        // Door opened successfully, print success message and indicate success
        //Serial.print(F("Door opened!"));
        //Serial.println();
        digitalWrite(LEDG_PIN, HIGH);
        delay(2000);
        digitalWrite(LEDG_PIN, LOW);
        
        log_label = " entry   ";
    }

    // Print the read data
    //Serial.print(F("\nBlock data ["));
    //Serial.print(block);
    //Serial.print(F("]: "));
    //for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++) {
        //Serial.write(buffer[i]);
    //}
    //Serial.println(" ");
    //Serial.println();
    return;
}
/* Write to RFID tag*/
void RFID::write_tag() {
    // Dump technical details of the card/tag
    //reader.PICC_DumpDetailsToSerial(&(reader.uid));

    // Prepare the key - all keys are set to FFFFFFFFFFFFh (Factory default)
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    // Buffer for storing data to be written
    byte buffer[MAX_SIZE_BLOCK] = "spacelab";   //if you change the buffer, remember to change the datasize and correctId
    byte block; // Block to perform the operation on
    byte dataSize; // Size of data to operate on (in bytes)

    // Set a default data size for the buffer
    dataSize = 8; //change the datasize if you change the buffer

    // Fill any remaining space in the buffer with whitespace
    for (byte i = dataSize; i < MAX_SIZE_BLOCK; i++) {
        buffer[i] = ' ';
    }

    // Block defined for the operation
    block = 1;

    // Authenticate is a command for authentication to enable secure communication
    status = reader.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(reader.uid));

    if (status != MFRC522::STATUS_OK) {
        // Authentication failed, print error message and indicate failure
        //Serial.print(F("PCD_Authenticate() failed: "));
        //Serial.println(reader.GetStatusCodeName(status));
        //Serial.println();
        delay(500);
        return;
    }
    // else Serial.println(F("PCD_Authenticate() success: "));

    // Buffer for storing read data
    byte buffer_read[SIZE_BUFFER] = {0};

    // Read data from the block
    byte dataSizeRead = SIZE_BUFFER;
    status = reader.MIFARE_Read(block, buffer_read, &dataSizeRead);
    byte* id = &buffer_read[0];
    byte correctId[MAX_SIZE_BLOCK] = "spacelab"; 

    // Set default values for the correct ID
    for (byte i = SIZE_BUFFER_DEFULT; i < MAX_SIZE_BLOCK; i++) {
        correctId[i] = ' ';
    }
    bool idsMatch = true;

    // Check if the read ID matches the correct ID
    for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++) {
        if (id[i] != correctId[i]) {
            idsMatch = false;
        }
    }

    // Write to the block
    status = reader.MIFARE_Write(block, buffer, MAX_SIZE_BLOCK);
    if (status != MFRC522::STATUS_OK) {
        // Writing failed, print error message and indicate failure
        //Serial.print(F("MIFARE_Write() failed: "));
        //Serial.println(reader.GetStatusCodeName(status));
        //Serial.println();
        delay(500);
        return;
    } else if (!idsMatch) {
        // Writing success and IDs don't match, print success message
        //Serial.println(F("MIFARE_Write() success: "));
        //Serial.println();
        delay(500);
    } else if (idsMatch) {
        // IDs match, indicating that the TAG is already registered
        //Serial.println(F("TAG already registered"));
        //Serial.println();
        delay(500);
    }
}

/* Function that operates the take_actions according to the action chosen by the user */  
void RFID::handle_events(Peripherals *btn_or_keyboard) {
    // Get the result of the action from the passed peripheral (button or keyboard)
    input result = btn_or_keyboard->take_action();

    // Handle the result based on the enumerated input
    switch (result) {
    case RESET:
        // If the result is a reset action, indicate success, open the door, and wait for a while
        digitalWrite(LEDG_PIN, HIGH);
        //Serial.println("Reset button pressed. Door opened!");
        //Serial.println();
        delay(1000);
        digitalWrite(LEDG_PIN, LOW);
        log_label = " exit";         
        break;
    case RIGHT_PASS:
        // If the result is a correct password, initiate recording mode and prompt the user to bring the RFID tag
        //Serial.println("Initiating recording mode.");
        delay(1000);
        //Serial.println(">>> Bring the RFID tag near the reader in...");
        //Serial.println("3");
        delay(1000);
        //Serial.println("2");
        delay(1000);
        //Serial.println("1");
        delay(3000);

        digitalWrite(LEDG_PIN, HIGH);
        delay(500);
        digitalWrite(LEDG_PIN, LOW);

        //Serial.println();
        // Check if a new RFID card is present and read its serial if available, then write to the card
        if (reader.PICC_IsNewCardPresent() && reader.PICC_ReadCardSerial()) {
            write_tag();
        }
        break;
    case WRONG_PASS:
        // If the result is an incorrect password, indicate failure, blink the red LED, and wait
        //Serial.println("Incorrect password.");
        //Serial.println();
        digitalWrite(LEDR_PIN, HIGH);
        delay(500);
        digitalWrite(LEDR_PIN, LOW);
        break;
    case NO_INPUT:
        // If there is no input, indicate that the door did not open, blink the red LED, and wait
        digitalWrite(LEDR_PIN, HIGH);
        //Serial.println("Door did not open!");
        //Serial.println();
        delay(1000);
        digitalWrite(LEDR_PIN, LOW);
        log_label = " no input";
        return; // Exit the function if there is no input
    }
}

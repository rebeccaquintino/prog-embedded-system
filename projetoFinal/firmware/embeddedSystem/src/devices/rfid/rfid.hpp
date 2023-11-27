#pragma once
#include <MFRC522.h>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include "devices/peripherals/peripherals.hpp"
#include "devices/queue/queue.hpp"

// Define the SS_PIN and RST_PIN for the RFID module
#define SS_PIN 21
#define RST_PIN 22

/* RFID class */
class RFID {
public:
    std::string log_label;
    // RFID reader object
    MFRC522 reader;
    // Constructor for initializing the RFID reader
    RFID(int ss_pin, int rst_pin) : reader(ss_pin, rst_pin) {}
    // Function to read a RFID tag
    void read_tag();
    // Function to write to a RFID tag
    void write_tag();
    // Function to initialize the RFID module
    void init();
    // Function to handle events based on RFID input and other peripherals
    void handle_events(Peripherals *btn_or_keyboard);
};

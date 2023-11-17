#pragma once
#include <MFRC522.h>
#include "devices/peripherals/peripherals.hpp"

#define SS_PIN          21
#define RST_PIN         22

class RFID {
    public:
        MFRC522 reader;
        RFID(int ss_pin, int rst_pin) : reader(ss_pin, rst_pin){}
        void read_tag();   
        void write_tag();
        void init();
        void handle_events(Peripherals *btn_or_keyboard);
};  
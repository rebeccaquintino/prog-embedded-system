#pragma once
#include <Keypad.h>
#include "../peripherals.hpp"

class Keyboard: public Peripherals {
    private:
        uint8_t COL_PIN[4] = { 27, 14, 13, 12 };
        uint8_t ROW_PIN[4] = { 32, 33, 25, 26 };
        char password[4] = {'1','2','3','4'}; 
        char keys[4][4] = {{ '1', '2', '3', 'A' },
                           { '4', '5', '6', 'B' },
                           { '7', '8', '9', 'C' },
                           { '*', '0', '#', 'D' }};
    public:
        Keypad keypad = Keypad(makeKeymap(keys), ROW_PIN, COL_PIN, 4, 4);  
        void init() override;
        input take_action() override;
};



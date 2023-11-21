#pragma once
#include <Keypad.h>
#include "../peripherals.hpp"

/* Keyboard class */

class Keyboard : public Peripherals {
private:
    // Pins for columns and rows of the keypad
    uint8_t COL_PIN[4] = {27, 14, 13, 12};
    uint8_t ROW_PIN[4] = {32, 33, 25, 26};
    // Default password for the keyboard
    char password[4] = {'1', '2', '3', '4'};
    // Keymap for the keypad
    char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

public:
    // Keypad object for handling input
    Keypad keypad = Keypad(makeKeymap(keys), ROW_PIN, COL_PIN, 4, 4);
    // Function to initialize the keyboard
    friend void init_keyboard(Keyboard& keyboard);
    // Function to take an action based on keyboard input
    input take_action() override;
};
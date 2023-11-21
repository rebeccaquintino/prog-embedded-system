#pragma once

// Enum to represent different types of inputs
enum input{
    WRONG_PASS,  // Incorrect password
    RIGHT_PASS,  // Correct password
    RESET,       // Reset action
    NO_INPUT,    // No input
};

// Abstract base class representing peripherals
class Peripherals {
    public:
        //virtual void init() = 0;   // Pure virtual function for initializing peripherals
        virtual input take_action() = 0;   // Pure virtual function for taking an action and returning the input
};
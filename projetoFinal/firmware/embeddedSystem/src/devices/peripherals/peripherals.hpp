#pragma once

enum input{
    WRONG_PASS,
    RIGHT_PASS,
    RESET,
    NO_INPUT,
};

class Peripherals {
    public:
        virtual void init() = 0;
        virtual input take_action() = 0;
};
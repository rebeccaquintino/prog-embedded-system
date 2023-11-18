#pragma once
#include "../peripherals.hpp"
#include "../../rfid/rfid.hpp"


extern volatile bool btn_intr;

/* Button class*/
class Button: public Peripherals {  
    private:
        const int BUTTON_RESET_PIN = 5; 
    public:
        int interrupt;
        void init() override;
        input take_action() override;        
};
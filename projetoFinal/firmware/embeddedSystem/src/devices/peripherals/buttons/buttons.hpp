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
        friend void init_button(Button& button);
        input take_action() override;     
};
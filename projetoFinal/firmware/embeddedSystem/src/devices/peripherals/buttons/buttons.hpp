#pragma once
#include "../peripherals.hpp"
#include "../../rfid/rfid.hpp"


extern volatile bool btn_intr;

class Button: public Peripherals {  
    public:
        int interrupt;
        void init() override;
        input take_action() override;        
};
#include <Arduino.h>
#include "../buttons/buttons.hpp"

/* Variable that returns whether the button was pressed */
volatile bool btn_intr = false;

/* Interrupt function for the button */
void handleInterrupt(){
    if(!btn_intr) { 
        btn_intr = true; 
  }
}
/* Button initialization function */
void Button::init(){
    // Configuring the button pin as an input and activating the internal pull-up
    pinMode(BUTTON_RESET_PIN , INPUT);  
    // Setting the external interrupt on the button pin
    attachInterrupt(digitalPinToInterrupt(BUTTON_RESET_PIN), handleInterrupt, FALLING);
}
/* Button action function */
input Button::take_action() {
    if(btn_intr){
        delay(100); // wait 100ms to avoid button rebound
        btn_intr =  false;
        return RESET;  
    }
    else{
        btn_intr =  false;
        return NO_INPUT;
    }
}
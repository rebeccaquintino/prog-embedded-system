#include <Arduino.h>
#include <Keypad.h>
#include "../keyboard/keyboard.hpp"
#include "../peripherals.hpp"

/* Keyboard initialization function */
void Keyboard::init(){
  Serial.println("2) To register cards, press any key");
  Serial.println();
  delay(1000);
}
/* Keyboard action function */
input Keyboard::take_action() { 
  // Variables for storing user input and counting key presses
  input right_pass;
  char pressed_keys[4];
  int counter = 0;
  // Display message to enter registration password after a delay
  delay(500);
  Serial.println(">>> Enter your registration password");
  Serial.println();
  // Loop to read 4 keys from the keypad
  while(counter < 4){
    char key = keypad.getKey();
    // Check if a key is pressed
    if (key) {
    pressed_keys[counter] = key;
    counter++;
    }  
  }
  // Check the entered password against the stored password
  for(int i = 0 ; i < 4; i++){
    if(pressed_keys[i] == this->password[i]) {
        right_pass = RIGHT_PASS;
    }
    else{
        right_pass = WRONG_PASS;
        break;    // Break the loop if any key does not match
    }
    
  }
  return right_pass;    // Return the result of the password comparison
}

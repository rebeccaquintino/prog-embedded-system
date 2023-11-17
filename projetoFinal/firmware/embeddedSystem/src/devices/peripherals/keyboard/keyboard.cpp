#include <Arduino.h>
#include <Keypad.h>
#include "../keyboard/keyboard.hpp"
#include "../peripherals.hpp"

void Keyboard::init(){
  Serial.println("2) Para cadastramento de cartoes, pressione qualquer tecla");
  Serial.println();
  delay(1000);
}

input Keyboard::take_action() { 

  input right_pass;
  char pressed_keys[4];
  int counter = 0;

  delay(500);
  Serial.println(">>> Coloque a senha para cadastramento");
  Serial.println();

  while(counter < 4){
    char key = keypad.getKey();

    if (key) {
    pressed_keys[counter] = key;
    counter++;
    }  
  }

  for(int i = 0 ; i < 4; i++){
    if(pressed_keys[i] == this->password[i]) {
        right_pass = RIGHT_PASS;
    }
    else{
        right_pass = WRONG_PASS;
        break;
    }
    
  }
  return right_pass; 
}

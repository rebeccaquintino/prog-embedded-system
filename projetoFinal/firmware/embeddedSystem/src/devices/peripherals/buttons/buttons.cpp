#include <Arduino.h>
#include "../buttons/buttons.hpp"

const int BUTTON_RESET_PIN = 5; 

volatile bool btn_intr = false;

/* Função de interrupção para o botão */
void handleInterrupt(){
    if(!btn_intr) { 
        btn_intr = true; 
  }
}
void Button::init(){
    // Configurando o pino do botão como entrada e ativa a pull-up interna
    pinMode(BUTTON_RESET_PIN , INPUT);  
    // Configurando a interrupção externa no pino do botão
    attachInterrupt(digitalPinToInterrupt(BUTTON_RESET_PIN), handleInterrupt, FALLING);
}
input Button::take_action() {
    if(btn_intr){
        delay(100); // aguarda 100ms para evitar rebote do botão
        btn_intr =  false;
        return RESET;  
    }
    else{
        btn_intr =  false;
        return NO_INPUT;
    }
}
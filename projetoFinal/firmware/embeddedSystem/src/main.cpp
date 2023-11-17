#include <SPI.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <Arduino.h>
#include "devices/peripherals/keyboard/keyboard.hpp"
#include "devices/peripherals/buttons/buttons.hpp"
#include "devices/rfid/rfid.hpp"
#include "devices/peripherals/peripherals.hpp"
#include "devices/queue/queue.hpp"

/* Instancias dos periféricos */
Keyboard kb;
Button btn;
RFID rf(SS_PIN, RST_PIN);

void setup() {
   // Inicia a serial
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rf.init();
  kb.init();
  btn.init();
}

void loop() {
  char read = kb.keypad.getKey();

  
  if (rf.reader.PICC_IsNewCardPresent() && rf.reader.PICC_ReadCardSerial()) {
      rf.read_tag();
      delay(2000);
      Serial.println();
      Serial.println("1) Para abertura da porta aproxime a TAG do leitor");
      Serial.println("2) Para cadastramento de cartoes, pressione qualquer tecla");
      Serial.println();
  } 
  else if(btn_intr) {             //verifica se senha está correta ou o botão está ativado
          rf.handle_events(&btn);
          btn_intr = false;
          Serial.println();
          Serial.println("1) Para abertura da porta aproxime a TAG do leitor");
          Serial.println("2) Para cadastramento de cartoes, pressione qualquer tecla");
          Serial.println();
        } else if(read != NULL){
            rf.handle_events(&kb);
            Serial.println();
            Serial.println("1) Para abertura da porta aproxime a TAG do leitor");
            Serial.println("2) Para cadastramento de cartoes, pressione qualquer tecla");
            Serial.println();
        }
  // instrui o PICC quando no estado ACTIVE a ir para um estado de "parada"
  rf.reader.PICC_HaltA(); 
  // "stop" a encriptação do PCD, deve ser chamado após a comunicação com autenticação, caso contrário novas comunicações não poderão ser iniciadas
  rf.reader.PCD_StopCrypto1();
}

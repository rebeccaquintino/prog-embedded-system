#include <MFRC522.h>
#include "../rfid/rfid.hpp"

#define SIZE_BUFFER     18
#define SIZE_BUFFER_DEFULT 8
#define MAX_SIZE_BLOCK  16
#define LEDG_PIN        4
#define LEDR_PIN        2

//esse objeto 'chave' é utilizado para autenticação
MFRC522::MIFARE_Key key;
//código de status de retorno da autenticação
MFRC522::StatusCode status;

void RFID::init(){

    pinMode(LEDG_PIN, OUTPUT);
    pinMode(LEDR_PIN, OUTPUT);
    
    reader.PCD_Init(); 
    // Mensagens iniciais no serial monitor
    Serial.println();
    Serial.println("1) Para abertura da porta aproxime a TAG do leitor");
    delay(1000);
}

void RFID::read_tag() {

    //imprime os detalhes tecnicos do cartão/tag
    reader.PICC_DumpDetailsToSerial(&(reader.uid)); 

    //Prepara a chave - todas as chaves estão configuradas para FFFFFFFFFFFFh (Padrão de fábrica).
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    //buffer para colocar os dados lidos
    byte buffer[SIZE_BUFFER] = {0};

    //bloco que faremos a operação
    byte bloco = 1;
    byte tamanho = SIZE_BUFFER;

    //faz a autenticação do bloco que vamos operar
    status = reader.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, bloco, &key, &(reader.uid)); //line 834 of MFRC522.cpp file
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Authentication failed: "));
        Serial.println(reader.GetStatusCodeName(status));
        Serial.println();
        digitalWrite(LEDR_PIN, HIGH);
        delay(1000);
        digitalWrite(LEDR_PIN, LOW);
        return;
    }
    

    //faz a leitura dos dados do bloco
    status = reader.MIFARE_Read(bloco, buffer, &tamanho);
    byte* id = &buffer[0]; 
    byte right_id[MAX_SIZE_BLOCK] = "spacelab";
    
    for(byte i = SIZE_BUFFER_DEFULT; i < MAX_SIZE_BLOCK; i++)
    {
        right_id[i] = ' ';
    }
    bool wrong_id = false;
    
    for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++){    
        if(id[i] != right_id[i]){
            wrong_id = true;
        }
    }

    if ((status != MFRC522::STATUS_OK) || (wrong_id)) {
        Serial.println(F("Porta não abriu."));
        Serial.println();
        digitalWrite(LEDR_PIN, HIGH);
        delay(1000);
        digitalWrite(LEDR_PIN, LOW);
    }
    else{
        Serial.print(F("Porta abriu!"));
        Serial.println();
        digitalWrite(LEDG_PIN, HIGH);
        delay(1000);
        digitalWrite(LEDG_PIN, LOW);
    }

    Serial.print(F("\nDados bloco ["));
    Serial.print(bloco);
    Serial.print(F("]: "));

    //imprime os dados lidos
    for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++)
    {
        Serial.write(buffer[i]);
    }
    Serial.println(" ");
    Serial.println();
    return;
    }

    void RFID::write_tag() {

    //imprime os detalhes tecnicos do cartão/tag
    reader.PICC_DumpDetailsToSerial(&(reader.uid)); 
    // aguarda 30 segundos para entrada de dados via Serial
    // Serial.setTimeout(30000L) ;     
    // Serial.println(F("Insira os dados a serem gravados com o caractere '#' ao final\n[máximo de 16 caracteres]:"));

    //Prepara a chave - todas as chaves estão configuradas para FFFFFFFFFFFFh (Padrão de fábrica).
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    //Prepara a chave - todas as chaves estão configuradas para FFFFFFFFFFFFh (Padrão de fábrica).
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    //buffer para armazenamento dos dados que iremos gravar
    // byte buffer[MAX_SIZE_BLOCK] = "";
    byte buffer[MAX_SIZE_BLOCK] = "spacelab";
    byte bloco; //bloco que desejamos realizar a operação
    byte tamanhoDados; //tamanho dos dados que vamos operar (em bytes)

    //recupera no buffer os dados que o usuário inserir pela serial
    //serão todos os dados anteriores ao caractere '#'
    // tamanhoDados = Serial.readBytesUntil('#', (char*)buffer, MAX_SIZE_BLOCK);
    tamanhoDados = 8;

    //espaços que sobrarem do buffer são preenchidos com espaço em branco
    for(byte i=tamanhoDados; i < MAX_SIZE_BLOCK; i++)
    {
        buffer[i] = ' ';
    }
    
    bloco = 1; //bloco definido para operação
    //String str = (char*)buffer; //transforma os dados em string para imprimir
    //Serial.println(str);

    //Authenticate é um comando para autenticação para habilitar uma comuinicação segura
    status = reader.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,
                                        bloco, &key, &(reader.uid));

    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(reader.GetStatusCodeName(status));
        Serial.println();
        delay(1000);
        return;
    }
    //else Serial.println(F("PCD_Authenticate() success: "));

     byte tamanho = SIZE_BUFFER;
    //faz a leitura dos dados do bloco
    status = reader.MIFARE_Read(bloco, buffer, &tamanho);
    byte* id = &buffer[0]; 
    byte right_id[MAX_SIZE_BLOCK] = "spacelab";
    
    for(byte i = SIZE_BUFFER_DEFULT; i < MAX_SIZE_BLOCK; i++)
    {
        right_id[i] = ' ';
    }
    bool equal_id = true;
    
    for (uint8_t i = 0; i < MAX_SIZE_BLOCK; i++){    
        if(id[i] != right_id[i]){
            equal_id = false;
        }
    }
    
    //Grava no bloco
    status = reader.MIFARE_Write(bloco, buffer, MAX_SIZE_BLOCK);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Write() failed: "));
        Serial.println(reader.GetStatusCodeName(status));
        Serial.println();
        delay(1000);
        return;
    }
    else if(!equal_id) {
        Serial.println(F("MIFARE_Write() success: "));
        Serial.println();
        delay(1000);
    }
    else if(equal_id) {
        Serial.println(F("TAG já cadastrada"));
        Serial.println();
        delay(1000);
    }
}

void RFID::handle_events(Peripherals *btn_or_keyboard) {

    input result = btn_or_keyboard->take_action();

    switch (result)
    {
    case RESET:
        digitalWrite(LEDG_PIN, HIGH);
        Serial.println("Botão de Reset pressionado. Porta abriu!");
        Serial.println();
        delay(1000);
        digitalWrite(LEDG_PIN, LOW);
        delay(1000);
        break;
    case RIGHT_PASS:
        Serial.println("Iniciando gravação.");
        delay(1000);
        Serial.println(">>> Aproxime a TAG no leitor em...");
        Serial.println("3");
        delay(1000);
        Serial.println("2");
        delay(1000);
        Serial.println("1");
        delay(3000);
        Serial.println();
        if (reader.PICC_IsNewCardPresent() && reader.PICC_ReadCardSerial()) {
            write_tag();
        } 
        delay(3000);
        break;
    case WRONG_PASS:
        Serial.println("Senha incorreta.");
        Serial.println();
        digitalWrite(LEDR_PIN, HIGH);
        delay(3000);
        digitalWrite(LEDR_PIN, LOW);
        break;
    case NO_INPUT:
        digitalWrite(LEDR_PIN, HIGH);
        Serial.println("Porta não abriu!");
        Serial.println();
        delay(1000);
        digitalWrite(LEDR_PIN, LOW);
        delay(1000);
        return;
    }
}
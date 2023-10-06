#include "Oled.h"
#include "Oled_classe.h"
#include "estados.h"
#include "maquina_refrigerante.h"
#include <iostream>

int main()
{
    Maquina soda_Maquina;
    soda_Maquina.display->init();
    soda_Maquina.display->clear();
    std::string mensagem_inicial = "dinheiro aqui";
    printString((char *)mensagem_inicial.c_str());

    while (true)
    {
        soda_Maquina.comando_->comando = soda_Maquina.comando_->wait_for_comando();
        soda_Maquina.estado_update();
    }
}

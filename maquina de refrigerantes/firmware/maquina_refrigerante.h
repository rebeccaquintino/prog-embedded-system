#pragma once
#include "Oled_classe.h"
#include "comandos.h"
#include "estados.h"
#include <iostream>
#include <ostream>

class Estado;

class Maquina 
{
  public:
    std::string refrigerante_;
    float troco_;
    Estado *estado_atual_;
    Comando *comando_;
    Oled *display;
    Maquina();
    ~Maquina(){};
    void estado_update();
};

#pragma once
#include "Oled_classe.h"
#include "comandos.h"
#include "estados.h"
#include <iostream>
#include <ostream>

class IEstado;

class Maquina 
{
  public:
    std::string refrigerante_;
    IEstado *estado_atual_;
    Comando *comando_;
    Oled *display;
    Maquina();
    ~Maquina(){};
    void estado_update();
};

#include "maquina_refrigerante.h"
#include <iostream>
#include <ostream>

Maquina::Maquina()
{
    estado_atual_ = &S000::estado_instance();
    refrigerante_ = "Nada escolhido";
    display = new Oled;
    comando_ = new Comando;
}

void Maquina::estado_update()
{
    this->estado_atual_->exit(this);
    this->estado_atual_->proximo_estado(this);
    this->estado_atual_->init(this);
    std::cout << "Estado: " << this->estado_atual_->estado_string() << std::endl;
    std::cout << "Refrigerante: " << this->refrigerante_<< std::endl;
    std::cout << "Comando: " << this->comando_->comando_string() << std::endl;
}

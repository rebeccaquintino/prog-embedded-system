#include "Oled_classe.h"
#include "Oled.h"
#include <cstring>
#include <sstream>

static volatile unsigned int *output    = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *data      = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

void Oled::init(void)
{
    oledInit();
}

void Oled::clear(void)
{
    oledClear();
}

void Oled::print_display(std::string refrigerante, float saldo, float troco)
{
    std::stringstream refrigerante_stream;
    std::stringstream saldo_stream;
    std::stringstream troco_stream;

    this->clear();

    refrigerante_stream << "Bebida: " << refrigerante;
    setLine(0);
    printString((char *)refrigerante_stream.str().c_str());

    saldo_stream << "Saldo R$ " << saldo;
    setLine(1);
    printString((char *)saldo_stream.str().c_str());

    troco_stream << "Troco R$ " << troco;
    setLine(2);
    printString((char *)troco_stream.str().c_str());
}

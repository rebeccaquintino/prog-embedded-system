#include "comandos.h"


static volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

Comando::Comando()
{
    this->comando = NADA;
}

std::string Comando::comando_string()
{
    switch (comando)
    {
    case NADA:
        return "Nenhuma moeda";
    case M025:
        return "Inserir 25 centavos";
    case M050:
        return "Inserir 50 centavos";
    case M100:
        return "Inserir 1 real";
    case DEV:
        return "Devolução";
    case ETIRPS:
        return "ETIRPS";
    case MEET:
        return "MEET";
    default:
        return "Não consegui identificar a opção";
    }
}

Comandos Comando::wait_for_comando()
{
    while (true)
    {
        /* Keys are mapped to GPIO bits 16 to 20 
           Switches SW0 to SW5 are mapped to GPIO bits 8 to 13 */

        if ((*data >> 15U) & 1U) // KEY 1 are M025
        {
            return M025;
        }
        if ((*data >> 16U) & 1U) // KEY 2 are M050
        {
            return M050;
        }
        if ((*data >> 17U) & 1U) // KEY 3 are M100
        {
            return M100;
        }
        if ((*data >> 18U) & 1U) // KEY 4 are ETIRPS drink
        {
            return ETIRPS;
        }
        if ((*data >> 19U) & 1U) // KEY 5 are MEET drink
        {
            return MEET;
        }
        if ((*data >> 7U)  & 1U) // SW 1 are DEV
        {
            return DEV;
        }
    }
}
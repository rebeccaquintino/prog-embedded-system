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
        return "Inseriu nada";
    case M025:
        return "Inseriu 25 centavos";
    case M050:
        return "Inseriu 50 centavos";
    case M100:
        return "Inseriu 1 real";
    case DEV:
        return "Devolveu";
    case ETIRPS:
        return "Escolheu ETIRPS";
    case MEET:
        return "Escolheu MEET";
    default:
        return "Não consegui identificar a opção";
    }
}

Comandos Comando::wait_for_comando()
{
    while (true)
    {
        /* Keys are mapped to GPIO bits 17 to 21 
           Switches SW0 to SW5 are mapped to GPIO bits 9 to 14 */

        if ((*data >> 16U) & 1U) // BTNU are M025
        {
            return M025;
        }
        if ((*data >> 17U) & 1U) // BTNL are M050
        {
            return M050;
        }
        if ((*data >> 18U) & 1U) // BTND are M100
        {
            return M100;
        }
        if ((*data >> 19U) & 1U) // BTNR are ETIRPS drink
        {
            return ETIRPS;
        }
        if ((*data >> 20U) & 1U) // BTNC are MEET drink
        {
            return MEET;
        }
        if ((*data >> 8U) & 1U) // SW 0 are DEV
        {
            if (!(this->comando == DEV)) {
                return DEV;
            }
        }
    }
}
#include <string>

typedef enum 
{
    NADA = 0,
    M025, 
    M050,
    M100,
    DEV,
    MEET,
    ETIRPS,
}Comandos;

class Comando
{
  public:
    Comandos comando;
    Comando();
    std::string comando_string();
    Comandos wait_for_comando();
};
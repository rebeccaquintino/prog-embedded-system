#include "Oled.h"
#include "estados.h"
#include "maquina_refrigerante.h"
#include <string>

inline std::string S000::estado_string()
{
    return estado_string_;
}
void S000::init(Maquina *mech)
{
    mech->display->clear();
    if (mech->comando_->comando != DEV && mech->comando_->comando != CONFIRM) {
        mech->display->print_display(estado_string_, moeda_, troco_);
    } else if(mech->comando_->comando == CONFIRM) {
        mech->refrigerante_ = "Ainda não escolhido";
        setLine(0);
        printString("Bebida disponível : ");
        setLine(1);
        printString("Obrigada!");
    }
}
void S000::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S000::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S025::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S050::estado_instance();
        break;
    case M100:
        mech->estado_atual_ = &S100::estado_instance();
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S000::estado_instance()
{
    static S000 estado_instance;
    return estado_instance;
}
inline std::string S025::estado_string()
{
    return estado_string_;
}
void S025::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S025::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S025::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S050::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S075::estado_instance();
        break;
    case M100:
        mech->estado_atual_ = &S125::estado_instance();
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S025::estado_instance()
{
    static S025 estado_instance;
    return estado_instance;
}
inline std::string S050::estado_string()
{
    return estado_string_;
}
void S050::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S050::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S050::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S075::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S100::estado_instance();
        break;
    case M100:
        mech->estado_atual_ = &S150::estado_instance();
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S050::estado_instance()
{
    static S050 estado_instance;
    return estado_instance;
}
inline std::string S075::estado_string()
{
    return estado_string_;
}
void S075::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S075::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S075::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S100::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S125::estado_instance();
        break;
    case M100:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.25f;
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S075::estado_instance()
{
    static S075 estado_instance;
    return estado_instance;
}
inline std::string S100::estado_string()
{
    return estado_string_;
}
void S100::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S100::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S100::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S125::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S150::estado_instance();
        break;
    case M100:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.50f;
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S100::estado_instance()
{
    static S100 estado_instance;
    return estado_instance;
}
inline std::string S125::estado_string()
{
    return estado_string_;
}
void S125::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S125::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S125::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S150::estado_instance();
        break;
    case M050:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.25f;
        break;
    case M100:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.75f;
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    }
}
Estado &S125::estado_instance()
{
    static S125 estado_instance;
    return estado_instance;
}
inline std::string S150::estado_string()
{
    return estado_string_;
}
void S150::init(Maquina *mech)
{
    mech->display->clear();
    mech->display->print_display(estado_string_, moeda_, troco_);
    troco_ = 0.0f;
}
void S150::exit(Maquina *mech)
{
    troco_ = 0.0f;
    mech->display->clear();
}
void S150::proximo_estado(Maquina *mech)
{
    switch (mech->comando_->comando)
    {
    case NADA:
        troco_ = 0.0f;
        break;
    case M025:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.25f;
        break;
    case M050:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 0.50f;
        break;
    case M100:
        mech->estado_atual_ = &S150::estado_instance();
        troco_ = 1.00f;
        break;
    case DEV:
        troco_ = moeda_;
        mech->display->print_display("R$ 0.00", 0.0f, troco_);
        mech->estado_atual_ = &S000::estado_instance();
        break;
    case ETIRPS:
        mech->refrigerante_ = "ETIRPS";
        break;
    case MEET:
        mech->refrigerante_ = "MEET";
        break;
    case CONFIRM:
        if (mech->refrigerante_ == "ETIRPS" || mech->refrigerante_ == "MEET") {
            mech->estado_atual_ = &S000::estado_instance();
        } else{
            setLine(3);
            printString("Escolha uma opção de bebida");
        }
        break;
    }
}
Estado &S150::estado_instance()
{
    static S150 estado_instance;
    return estado_instance;
}
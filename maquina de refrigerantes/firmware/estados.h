#pragma once
#include "maquina_refrigerante.h"

class Maquina;

class IEstado
{
  public:
    virtual void init(Maquina *) = 0;
    virtual void exit(Maquina *) = 0;
    virtual void proximo_estado(Maquina *) = 0;
    virtual std::string estado_string() = 0;
    virtual ~IEstado()
    {
    }
};

class S000 : public IEstado
{
  public:
    void init(Maquina *);
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S000()
    {
        moeda_ = 0.0f;
        troco_ = 0.0f;
        estado_string_ = "S000";
    }
    S000(const S000 &other);
    S000 &operator=(const S000 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};

class S025 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S025()
    {
        moeda_ = 0.25f;
        troco_ = 0.0f;
        estado_string_ = "S025";
    }
    S025(const S025 &other);
    S025 &operator=(const S025 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};

class S050 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S050()
    {
        moeda_ = 0.50f;
        troco_ = 0.0f;
        estado_string_ = "S050";
    }
    S050(const S050 &other);
    S050 &operator=(const S050 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};

class S075 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S075()
    {
        moeda_ = 0.75f;
        troco_ = 0.0f;
        estado_string_ = "S075";
    }
    S075(const S075 &other);
    S075 &operator=(const S075 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};

class S100 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S100()
    {
        moeda_ = 1.00f;
        troco_ = 0.0f;
        estado_string_ = "S100";
    }
    S100(const S100 &other);
    S100 &operator=(const S100 &other);
    float troco_;
    float moeda_;
    std::string estado_string_;
};
class S125 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S125()
    {
        moeda_ = 1.25f;
        troco_ = 0.0f;
        estado_string_ = "S125";
    }
    S125(const S125 &other);
    S125 &operator=(const S125 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};
class S150 : public IEstado
{
  public:
    void init(Maquina *) ;
    void exit(Maquina *) ;
    void proximo_estado(Maquina *) ;
    inline std::string estado_string() ;
    static IEstado &estado_instance();

  private:
    S150()
    {
        moeda_ = 1.50f;
        troco_ = 0.0f;
        estado_string_ = "S150";
    }
    S150(const S150 &other);
    S150 &operator=(const S150 &other);
    float moeda_;
    float troco_;
    std::string estado_string_;
};
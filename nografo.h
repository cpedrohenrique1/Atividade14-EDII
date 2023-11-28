#ifndef NOGRAFO_H
#define NOGRAFO_H

#include <QString>

template <class L, class U>
class NoGrafo
{
private:
    L vertice;
    U peso;

public:
    NoGrafo() : vertice(),
                peso()
    {
    }
    NoGrafo(const L &vertice, const U &peso) : vertice(),
                                                   peso()
    {
        if (verificarVertice(vertice))
        {
            throw QString("Vertice invalido");
        }
        if (verificarPeso(peso))
        {
            throw QString("Peso invalido");
        }
        this->peso = peso;
        this->vertice = vertice;
    }
    virtual bool verificarVertice(const L& vertice) = 0;
    virtual bool verificarPeso(const U& peso) = 0;
    U getPeso() const
    {
        return peso;
    }
    void setPeso(const U &peso)
    {
        if (verificarPeso(peso)){
            throw QString("Peso invalido");
        }
        this->peso = peso;
    }
    L getVertice() const
    {
        return vertice;
    }
    void setVertice(const L &vertice)
    {
        if (verificarVertice(vertice))
        {
            throw QString("Vertice invalido");
        }
        this->vertice = vertice;
    }
};

#endif // NOGRAFO_H

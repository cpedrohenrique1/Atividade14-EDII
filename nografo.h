#ifndef NOGRAFO_H
#define NOGRAFO_H

#include <QString>

template <class TYPE>
class NoGrafo
{
private:
    int vertice;
    TYPE peso;

public:
    NoGrafo() : vertice(0),
                peso()
    {
    }
    NoGrafo(const int &vertice, const int &peso) : vertice(0),
                                                   peso()
    {
        if (vertice <= 0)
        {
            throw QString("Vertice invalido");
        }
        this->peso = peso;
        this->vertice = vertice;
    }
    TYPE getPeso() const
    {
        return peso;
    }
    void setPeso(const TYPE &peso)
    {
        this->peso = peso;
    }
    int getVertice() const
    {
        return vertice;
    }
    void setVertice(const int &vertice)
    {
        if (vertice <= 0)
        {
            throw QString("Vertice negativo");
        }
        this->vertice = vertice;
    }
};

#endif // NOGRAFO_H

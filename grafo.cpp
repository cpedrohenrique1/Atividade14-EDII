#include "grafo.h"

Grafo::Grafo() : peso(0),
                 vertice(0)
{
}
Grafo::Grafo(const int &vertice, const int &peso)
{
    if (peso < 0)
    {
        throw QString("peso nao pode ser < 0");
    }
    if (vertice < 0)
    {
        throw QString("vertice nao pode ser < 0");
    }
    this->peso = peso;
    this->vertice = vertice;
}
int Grafo::getPeso() const
{
    return peso;
}
void Grafo::setPeso(const int &peso)
{
    if (peso < 0)
    {
        throw QString("peso nao pode ser < 0");
    }
    this->peso = peso;
}
int Grafo::getVertice() const
{
    return vertice;
}
void Grafo::setVertice(const int &vertice)
{
    if (vertice < 0)
    {
        throw QString("vertice nao pode ser < 0");
    }
    this->vertice = vertice;
}
#include "nografo.h"

NoGrafo::NoGrafo() :    vertice(0),
                        peso(0)
{}

NoGrafo::NoGrafo(const int& vertice, const int& peso) : vertice(0),
                                                        peso(0)
{
    if (vertice < 0){
        throw QString("Vertice negativo");
    }
    if (peso < 0){
        throw QString("Peso negativo");
    }
    this->peso = peso;
    this->vertice = vertice;
}
int NoGrafo::getPeso()const{
    return peso;
}
void NoGrafo::setPeso(const int& peso){
    if (peso < 0){
        throw QString("Peso negativo");
    }
    this->peso = peso;
}
int NoGrafo::getVertice()const{
    return vertice;
}
void NoGrafo::setVertice(const int& vertice){
    if (vertice < 0){
        throw QString("Vertice negativo");
    }
    this->vertice = vertice;
}
#ifndef GRAFO_H
#define GRAFO_H

#include <QString>

class Grafo
{
private:
    int vertice;
    int peso;
public:
    Grafo();
    Grafo(const int& vertice, const int& peso);
    int getPeso()const;
    void setPeso(const int& peso);
    int getVertice()const;
    void setVertice(const int& vertice);
};

#endif // GRAFO_H

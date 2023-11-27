#ifndef GRAFO_H
#define GRAFO_H

#include <QString>
#include "lista.h"
#include "nografo.h"

class Grafo
{
private:
    Lista<NoGrafo> **lista;
    int n_vertices;
public:
    Grafo();
    Grafo(const int& n_vertices);
    void setPeso(const int& vertice1, const int& vertice2);
    int getPeso(const int& vertice1, const int& vertice2);
    int getNVertices()const;
    ~Grafo();
};

#endif // GRAFO_H

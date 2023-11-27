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
    ~Grafo();
};

#endif // GRAFO_H

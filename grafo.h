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
    NoGrafo* getNoExistente(int vertice1, int vertice2);
    void inserirAresta(const int& vertice1, const int& vertice2, const int& peso);
    void setAresta(const int& vertice1, const int& vertice2, const int& peso);
    int getNVertices()const;
    void removerAresta(int vertice1, int vertice2);
    Lista<NoGrafo>** getLista()const;
    ~Grafo();
};

#endif // GRAFO_H

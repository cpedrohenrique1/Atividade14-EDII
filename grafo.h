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
    void inserirAresta(const int& vertice1, const int& vertice2, const int& peso);
    void setAresta(const int& vertice1, const int& vertice2, const int& peso);
    int getNVertices()const;
    void removerAresta(const int& vertice1, const int& vertice2);
    NoGrafo getNOGrafo(const int& indice, const int& j)const;
    int getTamanhoLista(const int& vertice)const;
    ~Grafo();
};

#endif // GRAFO_H

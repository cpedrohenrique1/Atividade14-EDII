#include "grafo.h"

Grafo::Grafo() :    n_vertices(0),
                    lista(0)
{}
Grafo::Grafo(const int &n_vertices) :   n_vertices(0),
                                        lista(0)
{
    if (n_vertices <= 0)
    {
        throw QString("vertice nao pode ser <= 0");
    }
    this->n_vertices = n_vertices;
    try{
        lista = new Lista<NoGrafo>*[n_vertices];
        for (int i = 0; i < n_vertices; ++i){
            lista[i] = new Lista<NoGrafo>;
        }
    }catch(std::bad_alloc& e){
        throw QString("Nao foi possivel alocar memoria");
    }
}

Grafo::~Grafo(){
    if (lista){
        for (int i = 0; i < n_vertices; ++i){
            if (lista[i]){
                delete lista[i];
                lista[i] = 0;
            }
        }
        delete[] lista;
        lista = 0;
    }
}
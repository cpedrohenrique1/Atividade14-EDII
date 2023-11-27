#include "grafo.h"

Grafo::Grafo() : n_vertices(0),
                 lista(0)
{
}
Grafo::Grafo(const int &n_vertices) : n_vertices(0),
                                      lista(0)
{
    if (n_vertices <= 0)
    {
        throw QString("vertice nao pode ser <= 0");
    }
    this->n_vertices = n_vertices;
    try
    {
        lista = new Lista<NoGrafo> *[n_vertices];
        for (int i = 0; i < n_vertices; ++i)
        {
            lista[i] = new Lista<NoGrafo>;
        }
    }
    catch (std::bad_alloc &e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

NoGrafo *Grafo::getNoExistente(int vertice1, int vertice2)
{
    --vertice1;
    --vertice2;
    if ((vertice1 < 0 || vertice1 >= n_vertices) || (vertice2 < 0 || vertice2 >= n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    NO<NoGrafo> *iterator = lista[vertice1]->acessarInicio();
    for (int i = 0; i < lista[vertice1]->getQuantidadeElementos(); ++i)
    {
        if (iterator->getDado()->getVertice() == vertice2)
        {
            return iterator->getDado();
        }
        iterator = iterator->getProximo();
    }
    return 0;
}

void Grafo::setPeso(const int &vertice1, const int &vertice2, const int &peso)
{
    if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    if (peso < 0)
    {
        throw QString("Peso nao pode ser < 0");
    }
    NoGrafo *no = getNoExistente(vertice1, vertice2);
    if (no)
    {
        no->setPeso(peso);
        no = getNoExistente(vertice2, vertice1);
        no->setPeso(peso);
        return;
    }
    lista[vertice1]->inserirInicio(NoGrafo(vertice2, peso));
    lista[vertice2]->inserirInicio(NoGrafo(vertice1, peso));
}

int Grafo::getNVertices() const
{
    return n_vertices;
}

Grafo::~Grafo()
{
    if (lista)
    {
        for (int i = 0; i < n_vertices; ++i)
        {
            if (lista[i])
            {
                delete lista[i];
                lista[i] = 0;
            }
        }
        delete[] lista;
        lista = 0;
    }
}

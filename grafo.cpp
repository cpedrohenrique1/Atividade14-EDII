#include "grafo.h"

Grafo::Grafo() : lista(0),
    n_vertices(0)

{
}
Grafo::Grafo(const int &n_vertices) : lista(0),
    n_vertices(0)
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
    for (int i = 0; i < lista[vertice1]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice1]->acessarPosicao(i).getVertice() == vertice2)
        {
            return lista[vertice1]->acessarPosicao(i);
        }
        iterator = iterator->getProximo();
    }
    return 0;
}

void Grafo::inserirAresta(const int& vertice1, const int& vertice2, const int& peso){
    if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    if (peso < 0)
    {
        throw QString("Peso nao pode ser < 0");
    }
    for (int i = 0; i < lista[vertice1 - 1]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice1 - 1]->acessarPosicao(i).getVertice() == vertice2)
        {
            throw QString("Aresta ja existe");
        }
    }
    lista[vertice1 - 1]->inserirInicio(NoGrafo(vertice2, peso));
    lista[vertice2 - 1]->inserirInicio(NoGrafo(vertice1, peso));
}

void Grafo::setAresta(const int &vertice1, const int &vertice2, const int &peso)
{
    if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    if (peso < 0)
    {
        throw QString("Peso nao pode ser < 0");
    }
    for (int i = 0; i < lista[vertice1 - 1]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice1 - 1]->acessarPosicao(i).getVertice() == vertice2)
        {
            lista[vertice1 - 1]->retirarPosicao(i);
            lista[vertice1 - 1]->inserirPosicao(i, NoGrafo(vertice2, peso));
            break;
        }
    }
    for (int i = 0; i < lista[vertice2 - 1]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice2 - 1]->acessarPosicao(i).getVertice() == vertice1)
        {
            lista[vertice2 - 1]->retirarPosicao(i);
            lista[vertice2 - 1]->inserirPosicao(i, NoGrafo(vertice1, peso));
            break;
        }
    }
}

void Grafo::removerAresta(int vertice1, int vertice2){
    --vertice1;
    --vertice2;
    if ((vertice1 < 0 || vertice1 >= n_vertices) || (vertice2 < 0 || vertice2 >= n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    for (int i = 0; i < lista[vertice1]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice1]->acessarPosicao(i).getVertice() == vertice2)
        {
            lista[vertice1]->retirarPosicao(i);
            break;
        }
    }
    for (int i = 0; i < lista[vertice2]->getQuantidadeElementos(); ++i)
    {
        if (lista[vertice2]->acessarPosicao(i).getVertice() == vertice1)
        {
            lista[vertice2]->retirarPosicao(i);
            break;
        }
    }
}

int Grafo::getNVertices() const
{
    return n_vertices;
}

Lista<NoGrafo>** Grafo::getLista()const{
    return lista;
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

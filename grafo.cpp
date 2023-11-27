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

void Grafo::setAresta(const int &vertice1, const int &vertice2, const int &peso)
{
    if ((vertice1 - 1 < 0 || vertice1 - 1 > n_vertices) || (vertice2 - 1 < 0 || vertice2 - 1 > n_vertices))
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

void Grafo::removerAresta(const int& vertice1, const int& vertice2){
    if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
    {
        throw QString("Vertice nao existe");
    }
    NO<NoGrafo> *no = lista[vertice1]->acessarInicio();
    for (int i = 0; i < lista[vertice1]->getQuantidadeElementos(); ++i)
    {
        if (no->getDado()->getVertice() == vertice2)
        {
            lista[vertice1]->retirarPosicao(i);
            break;
        }
        no = no->getProximo();
    }
    no = lista[vertice2]->acessarInicio();
    for (int i = 0; i < lista[vertice2]->getQuantidadeElementos(); ++i)
    {
        if (no->getDado()->getVertice() == vertice1)
        {
            lista[vertice2]->retirarPosicao(i);
            break;
        }
        no = no->getProximo();
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

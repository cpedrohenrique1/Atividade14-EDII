#ifndef GRAFO_H
#define GRAFO_H

#include <QString>
#include "lista.h"
#include "nografo.h"

template<class L, class U>
class Grafo
{
private:
    Lista<NoGrafo<L,U>> **lista;
    int n_vertices;

public:
    Grafo() : lista(0),
              n_vertices(0)
    {
    }
    Grafo(const int &n_vertices) : lista(0),
                                   n_vertices(0)
    {
        if (n_vertices <= 0)
        {
            throw QString("vertice nao pode ser <= 0");
        }
        this->n_vertices = n_vertices;
        try
        {
            lista = new Lista<L> *[n_vertices];
            for (int i = 0; i < n_vertices; ++i)
            {
                lista[i] = new Lista<L>;
            }
        }
        catch (std::bad_alloc &e)
        {
            throw QString("Nao foi possivel alocar memoria");
        }
    }
    virtual L getVertice(L noGrafo) const = 0;
    inserirAresta(const int &vertice1, const int &vertice2, const int &peso)
    {
        if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
        {
            throw QString("Vertice nao existe");
        }
        if (vertice1 == vertice2)
        {
            throw QString("Vertice nao pode ser igual");
        }
        if (peso < 0)
        {
            throw QString("Peso nao pode ser < 0");
        }
        for (int i = 0; i < lista[vertice1 - 1]->getQuantidadeElementos(); ++i)
        {
            if (getVertice(lista[vertice1 - 1]->acessarPosicao(i)) == vertice2)
            {
                throw QString("Aresta ja existe");
            }
        }
        lista[vertice1 - 1]->inserirInicio(L(vertice2, peso));
        lista[vertice2 - 1]->inserirInicio(L(vertice1, peso));
    }
    setAresta(const int &vertice1, const int &vertice2, const int &peso)
    {
        if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
        {
            throw QString("Vertice nao existe");
        }
        if (vertice1 == vertice2)
        {
            throw QString("Vertice nao pode ser igual");
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
    int getNVertices() const
    {
        return n_vertices;
    }
    void removerAresta(const int &vertice1, const int &vertice2)
    {
        if ((vertice1 < 0 || vertice1 > n_vertices) || (vertice2 < 0 || vertice2 > n_vertices))
        {
            throw QString("Vertice nao existe");
        }
        if (vertice1 == vertice2)
        {
            throw QString("Vertice nao pode ser igual");
        }
        for (int i = 0; i < lista[vertice1 - 1]->getQuantidadeElementos(); ++i)
        {
            if (lista[vertice1 - 1]->acessarPosicao(i).getVertice() == vertice2)
            {
                lista[vertice1 - 1]->retirarPosicao(i);
            }
        }
        for (int i = 0; i < lista[vertice2 - 1]->getQuantidadeElementos(); ++i)
        {
            if (lista[vertice2 - 1]->acessarPosicao(i).getVertice() == vertice1)
            {
                lista[vertice2 - 1]->retirarPosicao(i);
            }
        }
    }
    getLista() const
    {
        return lista;
    }
    ~Grafo()
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
};

#endif // GRAFO_H

#ifndef TABHASH_H
#define TABHASH_H

#include "lista.h"
#include <cmath>

template <class L>
class TabHash
{
protected:
    Lista<L> **tabela;
    int tamanhoTabela;

public:
    TabHash() : tabela(0),
                tamanhoTabela(0)
    {
    }

    TabHash(const int &tamanhoTabela) : tabela(0),
                                        tamanhoTabela(0)
    {
        if (tamanhoTabela <= 0)
        {
            throw QString("Nao foi possivel, tamanho invalido ou colisao invalida");
        }
        this->tamanhoTabela = tamanhoTabela;
        try
        {
            tabela = new Lista<L> *[this->tamanhoTabela];

            for (int i = 0; i < this->tamanhoTabela; ++i)
            {
                tabela[i] = new Lista<L>;
            }
        }
        catch (std::bad_alloc &e)
        {
            throw QString("nao foi possivel alocar memoria");
        }
    }

    ~TabHash()
    {
        for (int i = 0; i < tamanhoTabela; ++i)
        {
            if (tabela[i])
            {
                delete tabela[i];
                tabela[i] = 0;
            }
        }
        if (tabela)
        {
            delete[] tabela;
            tabela = 0;
        }
    }

    int getTamanhoTabela() const
    {
        return tamanhoTabela;
    }

    virtual int getChave(const L &entrada) const = 0;

    void IncluirDados(const L &entrada)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        int chave = getChave(entrada);
        if (chave >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        tabela[chave]->inserirInicio(entrada);
    }

    void ExcluirDados(int chave)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        if (chave < 0 || chave >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        NO<L> *iterator = tabela[chave]->acessarInicio();
        for (int i = 0; i < tabela[chave]->getQuantidadeElementos(); ++i)
        {
            if (getChave(iterator->getDado()) == temp)
            {
                tabela[chave]->retirarPosicao(i);
                return;
            }
            iterator = iterator->getProximo();
        }
    }

    L Consultar(int chave)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        if (chave < 0)
        {
            throw QString("Chave invalida");
        }
        if (chave >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        NO<L> *iterator = tabela[chave]->acessarInicio();
        for (int i = 0; i < tabela[chave]->getQuantidadeElementos(); ++i)
        {
            if (getChave(iterator->getDado()) == chave)
            {
                return iterator->getDado();
            }
            iterator = iterator->getProximo();
        }
        return L();
    }
};

#endif // TABHASH_H

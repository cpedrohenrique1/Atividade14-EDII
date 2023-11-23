#include "tabhashgrafo.h"

TabHashGrafo::TabHashGrafo() : TabHash<Grafo>()
{
}
TabHashGrafo::TabHashGrafo(const int &tamanhoTabela) : TabHash<Grafo>(tamanhoTabela)
{
}
int TabHashGrafo::getChave(const Grafo &entrada) const
{
    return entrada.getVertice();
}
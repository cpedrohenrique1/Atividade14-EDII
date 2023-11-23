#ifndef TABHASHGRAFO_H
#define TABHASHGRAFO_H

#include "tabhash.h"
#include "grafo.h"

class TabHashGrafo : public TabHash<Grafo>
{
public:
    TabHashGrafo();
    TabHashGrafo(const int& tamanhoTabela);
    int getChave(const Grafo& entrada)const override;
};

#endif // TABHASHGRAFO_H

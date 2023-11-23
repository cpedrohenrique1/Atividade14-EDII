#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"
#include "tabhashgrafo.h"

class Tabela
{
private:
    QTableWidget *tabela;
    TabHashGrafo *vetor;
    int tamanho_tabela;

public:
    Tabela();
    Tabela(QTableWidget *parent, const int &tamanho);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    void inserirElemento(const int &vertice, const int& peso);
    void alterarElemento(const int &vertice, const int& peso);
    void removerElemento(const int &vertice);
    int getTamanhoTabela() const;
};

#endif // TABELA_H

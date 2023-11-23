#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"
#include "tabhash.h"

class Tabela
{
private:
    QTableWidget *tabela;
    TabHash *vetor;
    int tamanho_tabela;

public:
    Tabela();
    Tabela(QTableWidget *parent, const int &tamanho);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    QString buscaElemento(const int &matricula);
    void inserirElemento(const int &matricula, const QString &nomeCompleto);
    void alterarElemento(const int &matricula, const QString &nomeCompleto);
    void removerElemento(const int &matricula);
    int getTamanhoTabela() const;
};

#endif // TABELA_H

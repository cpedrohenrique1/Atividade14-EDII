#include "tabela.h"

Tabela::Tabela() : tabela(0),
                   vetor(0),
                   tamanho_tabela(0)
{}

Tabela::Tabela(QTableWidget *parent, const int &tamanho) : tabela(0),
                                                           vetor(0),
                                                           tamanho_tabela(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    if (tamanho <= 0)
        throw QString("tamanho invalido");
    this->tamanho_tabela = tamanho;
    this->tabela = parent;
    try
    {
        vetor = new TabHashGrafo(tamanho);
    }
    catch (const std::bad_alloc &e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

int Tabela::getTamanhoTabela() const
{
    if (!vetor)
    {
        throw QString("vetor nao localizado {getTamanhoVetor}");
    }
    return vetor->getTamanhoTabela();
}

Tabela::~Tabela()
{
    if (vetor)
        delete vetor;
}

void Tabela::start()
{
    if (!tabela)
        throw QString("tabela nao localizada {start}");
    tabela->setColumnCount(0);
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // tabela->verticalHeader()->setVisible(false);
}

void Tabela::limpar()
{
    if (!tabela)
        throw QString("tabela nao localizada, {limpartabela}");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void Tabela::atualizar()
{
    if (!tabela)
        throw QString("tabela nao localizada {atualizar}");

    if (!vetor)
        throw QString("vetor nao localizado {atualizar}");

    limpar();

    for (int i = 0; i < tamanho_tabela; ++i)
    {
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        tabela->setItem(i, 1, new QTableWidgetItem(nomeCompleto));
        vetor.
    }
}

void Tabela::inserirElemento(const int &vertice, const int& peso)
{
    if (vertice < 0 || vertice >= tamanho_tabela)
        throw QString("numero de vertice nao condiz com os padroes {inserirElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {inserirElemento}");

    vetor->IncluirDados(Grafo(peso, vertice));
    atualizar();
}

void Tabela::alterarElemento(const int &vertice, const int& peso)
{
    if (vertice < 0 || vertice >= tamanho_tabela)
        throw QString("numero de vertice nao condiz com os padroes {alterarElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {alterarElemento}");

    vetor->ExcluirDados(vertice);
    vetor->IncluirDados(Grafo(peso, vertice));
    atualizar();
}

void Tabela::removerElemento(const int &vertice)
{
    if (!vetor)
        throw QString("vetor nao localizado {removerElemento}");
    if (vertice < 0 || vertice >= tamanho_tabela)
        throw QString("numero de vertice nao condiz com os padroes {removerElemento}");
    vetor->ExcluirDados(vertice);
    atualizar();
}

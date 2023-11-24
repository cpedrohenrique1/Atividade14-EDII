#include "tabela.h"

Tabela::Tabela() : tabela(0),
                   tabela_hash(0),
                   tamanho_tabela(0)
{
}

Tabela::Tabela(QTableWidget *parent, const int &tamanho, const int &colisoes) : tabela(0),
                                                                                tabela_hash(0),
                                                                                tamanho_tabela(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    if (tamanho <= 0)
        throw QString("tamanho invalido");
    if (colisoes <= 0)
        throw QString("numero de colisoes invalido");
    this->tabela = parent;
    try
    {
        tabela_hash = new TabHashAluno(tamanho, colisoes);
        this->tamanho_tabela = tabela_hash->getTamanhoTabela();
    }
    catch (const std::bad_alloc &e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

TabHashAluno *Tabela::getVetor() const
{
    return tabela_hash;
}

int Tabela::getTamanhoTabela() const
{
    return tamanho_tabela;
}

Tabela::~Tabela()
{
    if (tabela_hash)
        delete tabela_hash;
}

void Tabela::start()
{
    if (!tabela)
        throw QString("tabela nao localizada {start}");
    tabela->setColumnCount(tabela_hash->getColisoes() + 1);
    tabela->setColumnWidth(0, 10);
    tabela->setColumnWidth(1, 300);
    tabela->setColumnWidth(2, 300);
    tabela->setColumnWidth(3, 300);
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
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

    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {atualizar}");

    limpar();
    Lista<Aluno> **vetor = tabela_hash->getVetor();
    for (int i = 0; i  < tamanho_tabela; ++i){
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        for (int j = 1; j < vetor[i]->getQuantidadeElementos() + 1; ++j){
            Aluno aluno = vetor[i]->acessarPosicao(j - 1);
            tabela->setItem(i, j, new QTableWidgetItem(QString::number(aluno.getChave()) + "; " + aluno.getNome()));
        }
    }
}

QString Tabela::buscaElemento(const int &matricula)
{
    if (matricula >= tamanho_tabela || matricula < 0)
        throw QString("Numero invalido, tem que ser entre 0 e " + QString::number(tamanho_tabela - 1));

    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {buscaelemento}");
    return tabela_hash->Consultar(matricula).getNome();
}

void Tabela::inserirElemento(const int &matricula, const QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {inserirElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao 'remover' {inserirElemento}");

    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {inserirElemento}");

    if (tabela_hash->Consultar(matricula).getNome() != "")
        throw QString("Este elemento ja existe, se deseja alterar, use o botao 'alterar' {inserirElemento}");
    Aluno aluno(matricula, nomeCompleto.toUpper());
    tabela_hash->IncluirDados(aluno);
    atualizar();
}

void Tabela::alterarElemento(const int &matricula, const QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {alterarElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao remover {alterarElemento}");

    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {alterarElemento}");

    if (tabela_hash->Consultar(matricula).getNome() == "")
    {
        throw QString("Elemento nao existe, se deseja adicionar use o botao 'inserir' {alterarElemento}");
    }
    else
    {
        tabela_hash->ExcluirDados(matricula);
    }
    Aluno aluno(matricula, nomeCompleto.toUpper());
    tabela_hash->IncluirDados(aluno);
    atualizar();
}

void Tabela::removerElemento(const int &matricula)
{
    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {removerElemento}");
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {removerElemento}");
    tabela_hash->ExcluirDados(matricula);
    atualizar();
}

#include "tabela.h"

Tabela::Tabela() : tabela(0),
                   tamanho_tabela(0)
{
}

Tabela::Tabela(QTableWidget *parent, const int &tamanho, const int &colisoes) : tabela(0),
                                                                                tamanho_tabela(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    if (tamanho <= 0)
        throw QString("tamanho invalido");
    if (colisoes <= 0)
        throw QString("numero de colisoes invalido");
    this->tamanho_tabela = tamanho;
    this->tabela = parent;
    try
    {
        // vetor = new TabHashAluno(tamanho, colisoes);
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

    tabela->setColumnCount(2);
    QStringList cabecalho = {"Matricula", "Nome Completo"};
    tabela->setHorizontalHeaderLabels(cabecalho);
    tabela->setColumnWidth(0, 100); // Matricula
    tabela->setColumnWidth(1, 650); // Nome
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

    if (!vetor)
        throw QString("vetor nao localizado {atualizar}");

    limpar();

    int j = 0;
    for (int i = 0; i < tamanho_tabela; ++i)
    {
        QString nomeCompleto = vetor->Consultar(i).getNome();
        if (nomeCompleto == ""){
            continue;
        }
        tabela->insertRow(j);
        tabela->setItem(j, 0, new QTableWidgetItem(QString::number(i)));
        tabela->setItem(j, 1, new QTableWidgetItem(nomeCompleto));
        ++j;
    }
}

QString Tabela::buscaElemento(const int &matricula)
{
    if (matricula >= tamanho_tabela || matricula < 0)
        throw QString("Numero invalido, tem que ser entre 0 e " + QString::number(tamanho_tabela - 1));

    if (!vetor)
        throw QString("vetor nao localizado {buscaelemento}");
    return vetor->Consultar(matricula).getNome();
}

void Tabela::inserirElemento(const int &matricula, const QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {inserirElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao 'remover' {inserirElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {inserirElemento}");

    if (vetor->Consultar(matricula).getNome() != "")
        throw QString("Este elemento ja existe, se deseja alterar, use o botao 'alterar' {inserirElemento}");
    Aluno aluno(matricula, nomeCompleto.toUpper());
    vetor->IncluirDados(aluno);
    atualizar();
}

void Tabela::alterarElemento(const int &matricula, const QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {alterarElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao remover {alterarElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {alterarElemento}");

    if (vetor->Consultar(matricula).getNome() == "")
    {
        throw QString("Elemento nao existe, se deseja adicionar use o botao 'inserir' {alterarElemento}");
    }
    else
    {
        vetor->ExcluirDados(matricula);
    }
    Aluno aluno(matricula, nomeCompleto.toUpper());
    vetor->IncluirDados(aluno);
    atualizar();
}

void Tabela::removerElemento(const int &matricula)
{
    if (!vetor)
        throw QString("vetor nao localizado {removerElemento}");
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {removerElemento}");
    vetor->ExcluirDados(matricula);
    atualizar();
}

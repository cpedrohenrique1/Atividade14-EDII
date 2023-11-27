#ifndef NOGRAFO_H
#define NOGRAFO_H

#include <QString>

class NoGrafo
{
private:
    int vertice;
    int peso;
public:
    NoGrafo();
    NoGrafo(const int& vertice, const int& peso);
    int getPeso()const;
    void setPeso(const int& peso);
    int getVertice()const;
    void setVertice(const int& vertice);
};

#endif // NOGRAFO_H

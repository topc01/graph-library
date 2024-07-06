#pragma once

#include <vector>

class grafo
{
    std::vector<std::vector<int> > ady;
    int size;
public:
    grafo();
    grafo(int);
    void add_arco(int, int);
    int add_nodo();
    bool hay_arco(int, int);
    bool hay_camino(int, int);
};

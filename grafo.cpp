#include "grafo.h"
#include <vector>

grafo::grafo()
{
    std::vector< std::vector<int> > ady;
    this->ady = ady;
}

grafo::grafo(int nodes)
{
    std::vector< std::vector<int> > ady;
    for (int i = 0; i < nodes; i++)
    {
        std::vector<int> fila;
        ady.push_back(fila);
    }
    this->ady = ady;
    this->size = nodes;
}

void grafo::add_arco(int d, int h)
{
    ady[d].push_back(h);
    ady[h].push_back(d);
}

int grafo::add_nodo()
{
    std::vector<int> fila;
    ady.push_back(fila);
    this->size += 1;
    return size - 1;
}

bool grafo::hay_arco(int d, int h)
{
    int len = ady[d].size();
    for (int i = 0; i < len; i++)
    {
        if (ady[d][i] == h) return true;
    }
    return false;
}

bool grafo::hay_camino(int d, int h)
{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++) visited[i] = false;

    std::vector<int> stack;
    stack.push_back(d);
    visited[d] = true;
    
    while(stack.size() != 0)
    {
        int node = stack.back();
        stack.pop_back();

        int len = ady[node].size();
        for (int i = 0; i < len; i++)
        {
            if (!visited[ady[node][i]])
            {
                stack.push_back(ady[node][i]);
                visited[ady[node][i]] = true;
            }
        }
    }

    return visited[h];
}


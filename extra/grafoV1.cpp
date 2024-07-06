#include "grafo.h"
#include <vector>
#include <list>

grafo::grafo()
{
    std::vector< std::vector<bool> > matriz;
    this->matriz = matriz;
}

grafo::grafo(int cant)
{
    std::vector< std::vector<bool> > matriz;
    for (int i = 0; i < cant; i++)
    {
        std::vector<bool> fila;
        for (int j = 0; j < cant; j++)
        {
            fila.push_back(false);
        }
        matriz.push_back(fila);
    }
    this->matriz = matriz;
    this->size = cant;
}

void grafo::add_arco(int d, int h)
{
    this->matriz[d][h] = 1;
}

int grafo::add_nodo()
{
    std::vector<bool> fila;
    matriz.push_back(fila);
    for (int i=0; i<size+1; i++)
    {
        matriz[i].push_back(false);
        matriz[size].push_back(false);
    }
    this->size += 1;
    return size-1;
}

bool grafo::hay_arco(int d, int h)
{
    return matriz[d][h];
}

bool grafo::hay_camino(int d, int h)
{
    if (d == h) return true;

    bool *visto = new bool[size];
    for (int i = 0; i < size; i++) visto[i] = false;

    std::list<int> queue;

    visto[d] = true;
    queue.push_back(d);

    std::list<int>::iterator i;

    while (!queue.empty())
    {
        d = queue.front();
        queue.pop_front();

        // for (i = adj)
    }

    return false;
}

/*
bool grafo::isReachable(int s, int d)
{
    // Base case
    if (s == d)
      return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
     
    // If BFS is complete without visiting d
    return false;
}
*/
 
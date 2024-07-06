#include <vector>
#include <iostream>

#include "grafo.h"

using namespace std;

int main()
{
    grafo g1(3);
    g1.add_arco(0, 1);
    g1.add_arco(1, 2);
    bool a = g1.hay_arco(1, 0);
    cout << "a: " << a << endl;
    bool b = g1.hay_camino(2, 0);
    cout << "b: " << b << endl;
    cout << "Fin del programa\n";
}
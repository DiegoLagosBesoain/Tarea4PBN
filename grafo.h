#include <vector> 
class grafo {
    private:
        int cantidad_de_nodos;
        int modo;//en 0 es una matriz, en 1 es la lista,
        std::vector<std::vector<int>> grafo_forma;//cualquiera de las dos formas es una lista de listas
        int numero_de_arcos;
    public:
        grafo(int);
        void arco(int ,int );
        int add_nodo();
        bool hay_arco(int ,int );
        bool hay_camino(int , int );









};
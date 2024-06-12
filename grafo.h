#include <cmath>
#include <vector>
class grafo {
private:
  int cantidad_de_nodos;
  int modo; // en 0 es una matriz, en 1 es la lista,
  std::vector<std::vector<int>>
      grafo_forma; // cualquiera de las dos formas es una lista de listas
  int numero_de_arcos;
  void verificar_forma();
  std::vector<std::vector<int>> lista_de_adyacencias_a_matriz();
  std::vector<std::vector<int>> matriz_al_ista_de_adyacencias();

public:
  grafo(int);
  void add_arco(int, int);
  int add_nodo();
  bool hay_arco(int, int);
  bool hay_camino(int, int);
};
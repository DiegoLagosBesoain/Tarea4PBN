#include "grafo.h"
// en 0 es una matriz, en 1 es la lista,
grafo::grafo(int n) {

  grafo_forma.resize(0);
  cantidad_de_nodos = n;
  numero_de_arcos = 0;
  modo = 1;
}

int grafo::add_nodo() {

  if (modo == 0) {
    grafo_forma.resize(cantidad_de_nodos + 1);
    cantidad_de_nodos++;
    grafo_forma[cantidad_de_nodos - 1].resize(cantidad_de_nodos, 0);
  }
  if (modo == 1) {
    cantidad_de_nodos++;
  }
  verificar_forma();
  return cantidad_de_nodos;
}

void grafo::add_arco(int x, int y) {
  if (modo == 0) {
    grafo_forma[x][y] = 1;
  }
  if (modo == 1) {
    grafo_forma.resize(numero_de_arcos + 1);
    grafo_forma[numero_de_arcos].push_back(x);
    grafo_forma[numero_de_arcos].push_back(y);
    // { (1,2), (2,3)} ---> (2,1)   {(1,2), (2,3), (2,1),(x,y)}
  }

  numero_de_arcos++;
  verificar_forma();
}

bool grafo::hay_arco(int x, int y) {
  if (modo == 0) {
    if (grafo_forma[x][y] == 1) {
      return true;
    }
  }

  if (modo == 1) {
    for (int i = 0; i < grafo_forma.size(); i++) {
      if ((grafo_forma[i][0] == x) && (grafo_forma[i][1] == y)) {
        return true;
      }
    }
  }
  return false;
  // que retorne true si existe el arco y false en caso contrario.
}

bool grafo::hay_camino(int x, int y) { return false; }
// que retorne true si es posible encontrar un camino de uno o más arcos que
// una el nodo d al nodo h y false en caso contrario.

void grafo::verificar_forma() {

  int n = cantidad_de_nodos;
  if ((modo == 0) && (numero_de_arcos <= (n * std::log2(n)) / 2)) {
    matriz_al_ista_de_adyacencias();
    modo = 1;
  }

  if ((modo == 1) && (numero_de_arcos >= n * std::log2(n))) {
    lista_de_adyacencias_a_matriz();
    modo = 0;
  }
}
std::vector<std::vector<int>> grafo::lista_de_adyacencias_a_matriz() {

  std::vector<std::vector<int>> matriz;
  matriz.resize(cantidad_de_nodos);
  for (int i = 0; i < cantidad_de_nodos; i++)
    for (int j = 0; j < cantidad_de_nodos; j++) {
      matriz[i].push_back(0);
    }
  for (int i = 0; i < grafo_forma.size(); i++) {
    matriz[grafo_forma[i][0]][grafo_forma[i][1]] = 1;
  }

  return matriz;
}

// en 0 es una matriz, en 1 es la lista,

std::vector<std::vector<int>> grafo::matriz_al_ista_de_adyacencias() {

  std::vector<std::vector<int>> lista;
  lista.resize(cantidad_de_nodos);

  for (int i = 0; i < cantidad_de_nodos; i++)
    for (int j = 0; j < cantidad_de_nodos; j++) {
      if (grafo_forma[i][j] == 1) {
        lista.resize(lista.size() + 1);
        lista[lista.size() - 1].push_back(i);
        lista[lista.size() - 1].push_back(j);
      }
    }

  return lista;
}
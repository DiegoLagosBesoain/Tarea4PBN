#include "grafo.h"
#include <algorithm>

// en 0 es una matriz, en 1 es la lista,

bool existe_elemento(std::vector<int> vector_de_elementos, int elemento) {

  auto elemento_en_cuestion = std::find(vector_de_elementos.begin(),
                                        vector_de_elementos.end(), elemento);

  if (elemento_en_cuestion != vector_de_elementos.end()) {
    return true;
  } else {
    return false;
  }
}

grafo::grafo(int n) {

  grafo_forma.resize(0);
  cantidad_de_nodos = n;
  numero_de_arcos = 0;
  modo = 1;
}
//=======================================================================================
int grafo::add_nodo() {

  if (modo == 0) {

    for (int i = 0; i < (int)grafo_forma.size(); i++) {
      grafo_forma[i].resize(cantidad_de_nodos + 1);
    }

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
//=======================================================================================
void grafo::add_arco(int x, int y) {

  if ((cantidad_de_nodos< x) || (cantidad_de_nodos < y)) {
    return;
  }

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
//=======================================================================================
bool grafo::hay_arco(int x, int y) {
  if (modo == 0) {
    if (grafo_forma[x][y] == 1) {
      return true;
    }
  }

  if (modo == 1) {
    for (int i = 0; i < (int)grafo_forma.size(); i++) {
      if ((grafo_forma[i][0] == x) && (grafo_forma[i][1] == y)) {
        return true;
      }
    }
  }
  return false;
  // que retorne true si existe el arco y false en caso contrario.
}
//=======================================================================================
void grafo::verificar_forma() {

  int n = cantidad_de_nodos;
  if ((modo == 0) && (numero_de_arcos <= (n * std::log2(n)) / 2)) {
    grafo_forma = matriz_al_lista_de_adyacencias();
    modo = 1;
  }

  if ((modo == 1) && (numero_de_arcos >= n * std::log2(n))) {
    grafo_forma = lista_de_adyacencias_a_matriz();
    modo = 0;
  }
}
//=======================================================================================
std::vector<std::vector<int>> grafo::lista_de_adyacencias_a_matriz() {

  std::vector<std::vector<int>> matriz;
  matriz.resize(cantidad_de_nodos);
  for (int i = 0; i < cantidad_de_nodos; i++)
    for (int j = 0; j < cantidad_de_nodos; j++) {
      matriz[i].push_back(0);
    }
  for (int i = 0; i < (int)grafo_forma.size(); i++) {
    matriz[grafo_forma[i][0]][grafo_forma[i][1]] = 1;
  }

  return matriz;
}

// en 0 es una matriz, en 1 es la lista,
//=======================================================================================
std::vector<std::vector<int>> grafo::matriz_al_lista_de_adyacencias() {

  std::vector<std::vector<int>> lista;
  lista.resize(0);

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
void grafo::mostrar_grafo() {

  for (int i = 0; i < (int)grafo_forma.size(); i++) {
    for (int j = 0; j < (int)grafo_forma[i].size(); j++) {

      std::cout << grafo_forma[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

//=======================================================================================
bool grafo::hay_camino(int x, int y) {

  std::vector<int> apariciones;
  std::vector<int> caminos;
  apariciones.push_back(x);
  if (hay_arco(x, y)) {
    return true;
  }

  if (modo == 0) {
    for (int i = 0; i < cantidad_de_nodos; i++) {
      if (grafo_forma[x][i] == 1) {
        if (!existe_elemento(apariciones, i)) {
          caminos.push_back(i);
          apariciones.push_back(i);
        }
      }
      // std::find(vec.begin(), vec.end(), elemento);
    }
  }
  if (modo == 1) {

    for (int i = 0; i < (int)grafo_forma.size(); i++) {
      if (grafo_forma[i][0] == x) {
        if (!existe_elemento(apariciones, grafo_forma[i][1])) {
          caminos.push_back(grafo_forma[i][1]);
          apariciones.push_back(grafo_forma[i][1]);
        }
      }
    }
  }
  if (caminos.size() < 1)
    return false;

  for (int i = 0; i < (int)caminos.size(); i++) {
    if (hay_camino(caminos[i], y, apariciones))
      return true;
  }

  return false;
}

//=======================================================================================
bool grafo::hay_camino(int x, int y, std::vector<int> apariciones) {
  apariciones.push_back(x);
  std::vector<int> caminos;
  if (hay_arco(x, y)) {
    return true;
  }

  if (modo == 0) {
    for (int i = 0; i < cantidad_de_nodos; i++) {
      if (grafo_forma[x][i] == 1) {

        if (!existe_elemento(apariciones, i)) {
          caminos.push_back(i);
          apariciones.push_back(i);
        }
      }
    }
  }

  if (modo == 1) {

    for (int i = 0; i < (int)grafo_forma.size(); i++) {
      if (grafo_forma[i][0] == x) {
        if (!existe_elemento(apariciones, grafo_forma[i][1])) {
          caminos.push_back(grafo_forma[i][1]);
          apariciones.push_back(grafo_forma[i][1]);
        }
      }
    }
  }

  if (caminos.size() < 1)
    return false;

  for (int i = 0; i < (int)caminos.size(); i++) {
    if (hay_camino(caminos[i], y, apariciones))
      return true;
  }

  return false;
}
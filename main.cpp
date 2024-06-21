#include "grafo.h"

int main() {
  grafo g = grafo(2);
  
g.add_arco(1, 2);
g.add_arco(2, 1); 
std::cout <<" entre: "<< g.hay_camino(1,2)<<std::endl;
g.mostrar_grafo();

  return 0;
}
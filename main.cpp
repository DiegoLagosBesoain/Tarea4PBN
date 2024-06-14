#include "grafo.h"

int main() {
  grafo g = grafo(4);
  
  g.add_arco(0, 1);
  g.add_arco(0, 2);
  std::cout<<"entre\n";
  //g.add_arco(0, 3);
  //g.add_arco(1, 2);
  //g.add_arco(2, 1);
  g.add_arco(3, 1);
  g.add_arco(2, 3);
  //g.add_arco(3, 0);
  std::cout<<"entre\n";
  g.add_arco(1, 1);
  g.add_arco(1,3);
  g.add_arco(3,3);
  g.add_arco(1,2);

  g.mostrar_grafo();
  //std::cout <<g.hay_arco(0,0)<<"\n";
  std::cout << g.hay_camino(3,2)<<std::endl;

  return 0;
}
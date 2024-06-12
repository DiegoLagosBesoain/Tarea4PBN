#include "grafo.h"

grafo::grafo(int n){
    grafo_forma.resize(n);
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            grafo_forma[i].push_back(0);


        }

    }
    cantidad_de_nodos=n;
    numero_de_arcos=0;
    modo=0;

}
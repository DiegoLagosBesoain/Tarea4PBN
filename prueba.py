from grafo import *
from sys import getsizeof
# string vacio .
def castellano(booleano):
    if not booleano :
        return "no "
    return ""
g=grafo(2) #debiera partir como *lista* de adyacencias
g.add_arco(1, 2)
g.add_arco(2, 1) #debiera cambiar a *matriz*, porque e=n=2, e=nlog2(n) porque
print(g.hay_camino(1,2))
g.mostrar_grafo()
g.add_nodo() #vuelta a *lista* porque e=2, n=3. 3log2(3)/2=3x1,6/2=2,4
g.add_nodo()

g.add_arco(2, 3)
g.mostrar_grafo()
g.add_arco(1,1)
g.add_arco(4,4)
g.add_arco(3,3)
g.add_arco(3,1)
g.add_arco(1,2)
print(g.hay_camino(1,4))
g.mostrar_grafo()



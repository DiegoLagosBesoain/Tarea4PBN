# Compilador y nombres de ejecutables
CC = g++
SWIG = swig
EXE = ejecutable

# Flags del compilador
FLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
SWIG_FLAGS = -python -c++
PYTHON_INCLUDE = /usr/include/python3.8

# Nombre de la biblioteca
LIBRARY = _grafo.so

# Target para construir la biblioteca compartida
$(LIBRARY): grafo_wrap.o grafo.o
	$(CC) -shared grafo_wrap.o grafo.o -o $(LIBRARY) -lpython3.8

# Target para ejecutar el ejecutable
run: $(EXE)
	./$(EXE)

# Target para construir el ejecutable
$(EXE): main.o grafo.o
	$(CC) $(FLAGS) main.o grafo.o -o $(EXE)

# Target para construir main.o
main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o main.o

# Target para construir grafo.o
grafo.o: grafo.cpp grafo.h
	$(CC) $(FLAGS) -fPIC -c grafo.cpp -o grafo.o

# Target para construir grafo_wrap.o usando SWIG
grafo_wrap.o: grafo_wrap.cxx
	$(CC) -fPIC -c grafo_wrap.cxx -o grafo_wrap.o -I$(PYTHON_INCLUDE)

# Target para generar grafo_wrap.cxx usando SWIG
grafo_wrap.cxx: grafo.i
	$(SWIG) $(SWIG_FLAGS) grafo.i

# Target para limpiar los archivos de construcción
clean:
	rm -f *.o $(EXE) $(LIBRARY) grafo_wrap.cxx

.PHONY: clean run
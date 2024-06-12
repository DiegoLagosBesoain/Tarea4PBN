CC=g++
EXE=ejecutable
FLAGS=

run: $(EXE)
	./$(EXE)

$(EXE): main.o grafo.o
	$(CC) $(FLAGS) main.o grafo.o -o $(EXE)

main.o: main.cpp 
	$(CC) $(FLAGS) main.cpp -c -o main.o

grafo.o: grafo.cpp 
	$(CC) $(FLAGS) grafo.cpp -c -o grafo.o
clear:
	rm *.o $(EXE)

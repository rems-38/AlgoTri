main:main.o fonctions.o 
	gcc -o $@ $^ -g

main.o: main.c fonctions.h 
	gcc -c $< -g

fonctions.o: fonctions.c fonctions.h 
	gcc -c $< -g

clean: 
	rm -rf *.o main

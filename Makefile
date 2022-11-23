main:main.o fonctions.o 
	gcc -o $@ $^

main.o: main.c fonctions.h 
	gcc -c $<

fonctions.o: fonctions.c fonctions.h 
	gcc -c $<

clean: 
	rm -rf *.o main

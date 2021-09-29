hanoi: ExemploPilha.c PilhaDinamica.o
	gcc -o Teste.exe ExemploPilha.c PilhaDinamica.o	
	
PilhaDinamica.o: PilhaDinamica.c PilhaDinamica.h
	gcc -c PilhaDinamica.c		
	
clean:
	rm -rf *.o
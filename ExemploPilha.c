#include "PilhaDinamica.h"
//#include "PilhaEstatica.h"
#include <stdio.h>

void Imprimir(TipoPilha P1,TipoPilha P2,TipoPilha P3){		
	ImprimePilha(&P1);
	printf("[Pino 1]\n\n\n\n");	
	
	ImprimePilha(&P2);
	printf("[Pino 2]\n\n\n\n");	
	
	ImprimePilha(&P3);
	printf("[Pino 3]\n\n\n\n");
}

int main(){	
	TipoPilha P[3];
	TipoItem item;
	
	CriaPilha(&P[1]);
	CriaPilha(&P[2]);
	CriaPilha(&P[3]);
	
	item.chave = 5;
	Insere(&P[1], item);
	
	item.chave = 4;
	Insere(&P[1], item);
	
	item.chave = 3;
	Insere(&P[1], item);
	
	item.chave = 2;
	Insere(&P[1], item);
	
	item.chave = 1;
	Insere(&P[1], item);	
	Imprimir(P[1],P[2],P[3]);
	int PinoE=1;
	int Pino=1;
	int mov=0;

    do
    {
        printf("\nDigite o Pino de saida (0 - SAIR)\n");
        scanf("%d", &PinoE);
		
		if (PinoE == 1 || PinoE == 2 || PinoE == 3){
			
			do
			{
				printf("\nDigite o Pino de entrada (0 - SAIR)\n");
				scanf("%d", &Pino);
				
				if (Pino == 1 || Pino == 2 || Pino == 3){
					if (!PilhaVazia(&P[PinoE])){						
						if (PilhaVazia(&P[Pino])){
							mov++;
							Insere(&P[Pino], Remove(&P[PinoE]));
							Pino=0;							
						} else if (TopoPilha(&P[PinoE]).chave < TopoPilha(&P[Pino]).chave){
							mov++;
							Insere(&P[Pino], Remove(&P[PinoE]));
							Pino=0;
						} else {
							printf("\nOP INVALIDA\n");
							Pino=0;
						}						
					}
				}
				else{
					PinoE = Pino;
					system("cls || clear");
				}        
				
			} while(Pino);		
			
		}
		else{
			system("cls || clear");
		}        
		
		Imprimir(P[1],P[2],P[3]);
        
    } while(PinoE);
	
	
	/*item = TopoPilha(&P1);
	printf("TOPO = %d \n", item.chave);
	
	printf("TOPO = %d \n", Remove(&P1).chave);
	/*ImprimePilha(&L);
	Remove(&L);
	ImprimePilha(&L);
	Remove(&L);
	ImprimePilha(&L);
	Remove(&L);
	ImprimePilha(&L);	*/

	LimparTudo(&P[1]);
	LimparTudo(&P[2]);
	LimparTudo(&P[3]);
	//ImprimePilha(&P1);
	
}

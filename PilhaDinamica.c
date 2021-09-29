#include "PilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(TipoPilha *L){
	L->primeiro = NULL;
}
int Insere(TipoPilha *L, TipoItem I){
	TipoApontador P;
	
	P = (TipoApontador) malloc(sizeof(TipoNo));
	if (P == NULL){		
		return PILHA_CHEIA;
	}
	
	P->item = I;
	P->prox = NULL;
	
	if (PilhaVazia(L)){
		P->prox = NULL;
		L->primeiro = P;
	} else {
		P->prox = L->primeiro;
		L->primeiro = P;
	} 
	
	
}

TipoItem Remove(TipoPilha *L){
	TipoApontador p;
	p = L->primeiro;
	TipoItem I;
	I.chave = -1;
	
	if (PilhaVazia(L)){		
		return I;
		printf("Deu nao \n");
	}
	I = p->item;
	//unico elemento
	if (L-> primeiro->prox == NULL){		
		CriaPilha(L);
		free(p);
		return I;
	}
	//inicio	
	L->primeiro = L->primeiro->prox;	
	free(p);
	return I;
}

TipoItem TopoPilha(TipoPilha *L){
	if (!PilhaVazia(L)){
		return L->primeiro->item;
	}
	TipoItem I;
	I.chave = -1;
	return I;
}

char PilhaVazia(TipoPilha *L){
	return L->primeiro == NULL;
}
char PilhaCheia(TipoPilha *L);

void ImprimePilha(TipoPilha *L){
	TipoApontador P = L->primeiro;
	
	int i = 0;
	
	while(P != NULL) {		
		printf("[ %d ]\n",P->item.chave);		
		P = P->prox;
		i++;
	}
	
	printf("___|___\n\n")	;
}

void LimparTudo(TipoPilha *L){
	printf("\nLimpando");
	while (!PilhaVazia(L)){
		Remove(L);
		printf(".");
	}
	printf("\n");
}

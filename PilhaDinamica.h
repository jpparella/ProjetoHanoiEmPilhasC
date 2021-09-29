#ifndef PILHADINAMICA_H

#define PILHADINAMICA_H

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define PILHA_CHEIA -3

typedef int TipoChave;
typedef struct{
	TipoChave chave;	
} TipoItem;

typedef struct TipoNo{
	TipoItem item;
	struct TipoNo *prox;
} TipoNo;

typedef struct TipoNo *TipoApontador;

typedef struct{
	TipoApontador primeiro;
} TipoPilha;

void CriaPilha(TipoPilha *L);
int Insere(TipoPilha *L, TipoItem I);
TipoItem Remove(TipoPilha *L);
TipoItem TopoPilha(TipoPilha *L);

char PilhaVazia(TipoPilha *L);
char PilhaCheia(TipoPilha *L);

void ImprimePilha(TipoPilha *L);

void LimparTudo(TipoPilha *L);

#endif
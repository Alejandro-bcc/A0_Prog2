#include "fila_jornal.h"

void requisitar_noticia(char *titulo, char *texto){

	getchar();
	printf("\nDigite o título: ");
	fgets(titulo, 33, stdin);
	printf("Digite o texto: ");
	fgets(texto, 513, stdin);
}

noticia* criar_noticia(){

	noticia *nova = (noticia*) malloc(sizeof(noticia));
	if(!nova)
		return NULL;

	requisitar_noticia(nova->titulo, nova->texto);
	nova->idade = 0;
	nova->prox = NULL;

	return nova;
}

int inserir_noticia(noticia *nova, fila_jornal *fila){

	if(!nova)
		return -1;

	if(!fila)
		return -2;

	if(fila->final){

		fila->final->prox = nova;
		nova->prox = NULL;
		fila->final = nova;
	} else{

		fila->inicio = nova;
		fila->final = nova;
	}

	return 0;
}

noticia* remover_noticia(fila_jornal *fila){

	noticia *retorno;

	if(!fila)
		return NULL;

	if(!fila->inicio)
		return NULL;

	retorno = fila->inicio;
	fila->inicio = retorno->prox;

	if(!retorno->prox)
		fila->final = NULL;

	return retorno;
}

void atualizar_fila(fila_jornal *fila){

	if(!fila)
		return;
	
	int i = 0;
	/* it: iterador  */
	for(noticia *it = fila->inicio; (it && it->idade == 3); it = it->prox){
	}
}

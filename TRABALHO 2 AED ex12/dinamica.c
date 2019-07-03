#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "dinamica.h"

struct no{
    int info;
    char nome[20];
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Lista *lst, char nome[20]){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    strcpy(N->nome,nome); //copia o nome do soldado para N->nome
    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    *lst = N;

    return 1;
}


int remove_elem(Lista *lst, char nome[20]){
    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = (*lst)->prox;

    if(*lst == (*lst)->prox) // lista com um unico no
        *lst = NULL;

    else if(strcmp(aux->nome, nome) == 0){ // elemento a ser removido na primeira posicao
        (*lst)->prox = aux->prox;
    }
    else{
        while(strcmp(aux->prox->nome, nome) != 0){
            aux = aux->prox;
        }
        if(strcmp(aux->prox->nome, (*lst)->nome) == 0){
            Lista aux2 = aux->prox;
            aux->prox = (aux2)->prox;
            free(aux2);
            (*lst) = aux;
            }
            else{
                Lista aux2 = aux->prox;
                aux->prox = (aux2)->prox;
                free(aux2);
            }
    }
    return 1;
}


int tamanho(Lista lst){
    int tam = 1;
    Lista aux = lst->prox;
    while(aux != lst){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void primeiro(Lista lst){
    int x = rand()%tamanho(lst);
    printf("Numero sorteado: %d\n", x);
    Lista aux = lst->prox;
    while(lst != lst->prox){ //enquanto nao tiver apenas um soldado
        for(int i = 1; i < x; i++){
            aux = aux->prox;
        }
        Lista aux2 = aux->prox;
        printf("Morreu: %s\n", aux->nome);
        remove_elem(&lst,aux->nome);

        aux = aux2;
    }
    printf("Soldado sobrevivente: %s", lst->nome);
}

void segundo(Lista lst){
    int x = rand()%tamanho(lst);
    printf("Numero sorteado: %d\n", x);
    int sold = rand()%tamanho(lst);
    Lista s = lst->prox;
    for(int i = 1; i < sold; i++){ //percorre ate chegar no soldado sorteado para iniciar
        s = s->prox;
    }
    printf("Nome do soldado que iniciara: %s\n", s->nome);
    Lista aux = s;
    while(lst != lst->prox){
        for(int i = 1; i < x; i++){
           aux = aux->prox;
        }
        Lista aux2 = aux->prox;
        printf("Morreu: %s\n", aux->nome);
        remove_elem(&lst,aux->nome);

        aux = aux2;
    }
    printf("\n");
    printf("Soldado sobrevivente: %s", lst->nome);
}

void terceiro(Lista lst, char nome[]){
    int x = rand()%tamanho(lst);
    printf("Numero sorteado: %d\n", x);
    Lista s = lst->prox;
    while(strcmp(nome,s->nome) != 0) //percorre ate chegar no soldado escolhido para inicar
           s = s->prox;

    printf("Nome do soldado que iniciara: %s\n", s->nome);
    Lista aux = s;
    while(lst != lst->prox){
        for(int i = 1; i < x; i++){
           aux = aux->prox;
        }
        Lista aux2 = aux->prox;
        printf("Morreu: %s\n", aux->nome);
        remove_elem(&lst,aux->nome);

        aux = aux2;
    }
    printf("\n");
    printf("Soldado sobrevivente: %s", lst->nome);
}

void imprime_lista(Lista *lst){

    if(lista_vazia(*lst) == 1)
        printf("Vazia. \n");

    else{
        Lista aux = (*lst)->prox;
        while(aux != (*lst)){
            printf("%s \n", aux->nome);
            aux = aux->prox;
        }
        printf("%s\n", (*lst)->nome);
    }
}









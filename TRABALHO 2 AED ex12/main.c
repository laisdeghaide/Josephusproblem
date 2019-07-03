#include <stdio.h>
#include <stdlib.h>
#include "dinamica.h"

int main()
{
    Lista l = cria_lista();
    int x, op;
    char nome[10];
    printf("Digite a quantidade de soldados: ");
    scanf("%d",&x);

    printf("Digite os nomes dos soldados: ");
    for(int i = 0; i < x; i++){
        setbuf(stdin, NULL);
        scanf("%s",nome);
        insere_fim(&l,nome);
    }

    setbuf(stdin, NULL);
    printf("Escolha a opcao: \n");
    printf("1: Iniciar a contagem a partir do primeiro soldado\n");
    printf("2: Iniciar a contagem a partir de um soldado sorteado aleatoriamente\n");
    printf("3: Informar o nome do soldado para iniciar a contagem\n");
    scanf("%d",&op);


    switch(op){
       case 1: primeiro(l); break;
       case 2: segundo(l); break;
       case 3: {
           printf("Digite o nome que deseja iniciar a contagem: \n");
           scanf("%s",nome);
           terceiro(l,nome); break;
           }
    }

    return 0;
}


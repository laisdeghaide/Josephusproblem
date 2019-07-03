typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_fim(Lista *lst, char nome[20]);
int remove_elem(Lista *lst, char nome[20]);
void imprime_lista(Lista *lst);
void primeiro(Lista lst);
void segundo(Lista lst);
void terceiro(Lista lst, char nome[]);

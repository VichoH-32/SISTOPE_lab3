#include <string.h>

typedef struct _nodo{
    int data;
    struct _nodo *next;
    struct _nodo *prev;
}Node;

typedef struct _lista{
    int len;
    Node *first;
    Node *last;
}List;

List* new_List(){
    List *new = (List *)malloc(sizeof(List));
    new->len = 0;
    new->first = NULL,
    new->last = NULL;
    return new;
}

void add(List *lista, char *element){
    Node *new = (Node *)malloc(sizeof(Node));
    //new->data = strdup(element);
    sscanf(element, "%x", &(new->data));
    if(lista->len == 0){
        new->next = NULL;
        new->prev = NULL;
        lista->first = new;
        lista->last = new;
        lista->len = 1;
    }else{
        new->next = NULL;
        new->prev = lista->last;
        lista->last->next = new;
        lista->last = new;
        lista->len++;
    }
}

int get(List *lista, int pos){
    int i;
    Node *aux = lista->first;
    for(i = 0; i < lista->len && aux != NULL; i++){
        if(i == pos){
            return aux->data;
        }
        aux = aux->next;
    }
    return 0;
}

void print_List(List *lista){
    int i;
    Node *aux = lista->first;
    for(i = 0; i < lista->len && aux != NULL; i++){
        printf("i: %d - 0x%x\n", i, aux->data);
        aux = aux->next;
    }
}

void free_Node(Node *nodo){
    if(nodo != NULL){
        if(nodo->next != NULL)free_Node(nodo->next);
        //free(nodo->data);
        free(nodo);
    }
}

void free_List(List *lista){
    if(lista != NULL){
        if(lista->first != NULL)free_Node(lista->first);
        free(lista);
    }
}

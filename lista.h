#include <string.h>

typedef struct _nodo{
    ushort data; //direccion de 16 bits sin signo (short int = 2 bytes)
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
    sscanf(element, "%hx", &(new->data));//lee un short int en hex
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
    Node *aux;
    for(i = 0, aux = lista->first; i < lista->len && aux != NULL; i++, aux = aux->next){
        if(i == pos){
            return aux->data;
        }
    }
    return 0;
}

void print_List(List *lista){
    int i;
    Node *aux;// = lista->first;
    for(i = 0, aux = lista->first; i < lista->len && aux != NULL; i++, aux = aux->next){
        printf("i: %d - 0x%hx\n", i, aux->data);
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

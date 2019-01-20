#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.h"
#include "estructuras.h"
//#include <math.h>
/**
 * addres space = 2^16 ~ 64kB
 * page size = 2^offset
 * entries = 2^(root+second)
 *
 */

ushort root_bits = 0;
ushort second_bits = 0;
ushort offset = 0;


/*****************************************************
 * Funcion que recibe los parametros de las banderas *
 * @param argc         cantidad de argumentos        *
 * @param argv         arreglo con argumentos        *
 *****************************************************/
void getFlags(int argc, char **argv){
    int option;
    while( (option = getopt( argc, argv, "r:s:")) != -1){
        switch (option) {
            case 'r':
				 root_bits = atoi(optarg);
                break;
            case 's':
				second_bits = atoi(optarg);
                break;
            default:
                break;
        }
    }
}

List* readFile( char *fileName){
    char buff[1000];
    FILE *file;
    file = fopen( fileName , "r");
    if(file == NULL){
        printf( "No se ha podido abrir el archivo.\n");
        return NULL;
    }
    char *word;
    List *new = new_List();
    while(fgets(buff, 1000, file)){
        word = strtok( buff, "\n");
        add( new, word);
    }
    fclose( file);
    return new;
}

void createDirectionsFile(List *lista){
    FILE *fp = fopen("out1.txt", "w");
    int i;
    Node *aux;
    for(i = 0, aux = lista->first; i < lista->len && aux != NULL; i++, aux = aux->next){
        fprintf(fp, "0x%x\n", aux->data);
    }
    fclose(fp);
}

ushort shinkDirection(int shiftAmount, int num){
    ushort newNum = num,i;
    for(i = 0; i < shiftAmount; i++){
        newNum = (newNum << 1);
    }
    for(i = 0; i < shiftAmount; i++){
        newNum = (newNum >> 1);
    }
    return newNum;
}

int main(int argc, char **argv) {
    getFlags(argc, argv);
    printf("%d - %d\n", root_bits, second_bits);
    offset = 16 - root_bits - second_bits;
    if( offset <= 1 ){
        printf("ERROR: parametros invalidos, los bits de la raiz y secundario debe ser menor a 16\n");
        return 1;
    }
    List *directions = readFile("Archivo1.txt"); //Archivo2.txt para los marcos
    if(directions != NULL){
        print_List(directions);
        createDirectionsFile(directions);
        free_List(directions);

        //crear lvl 1 con 2^root_bits entradas
        //crear tabla lvl 2 con segundo archivo de entrada

        //leer direcciones
        //  por cada direccion, si cabe dentro del addres space:
        //      sacar vpn root de la direccion (shift right) y buscar en la
        //      tabla lvl 2.

        printf("\n--- TEST ---\n");
        ushort var = 0xFFFF;
        printf("val: %hx\n", var);
        printf("val: %hx\n", shinkDirection(root_bits + second_bits, var));
        printf("\n--- TEST ---\n");
    }
    return 0;
}

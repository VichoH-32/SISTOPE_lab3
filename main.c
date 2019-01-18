#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.h"
//#include <math.h>

int root_bits = 0;
int second_bits = 0;

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

int main(int argc, char **argv) {
    getFlags(argc, argv);
    List *directions = readFile("file.txt");
    print_List(directions);

    FILE *fp = fopen("salida1.txt", "w");
    

    free_List(directions);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int saleCantAristasAdyacentes(int pos){
	FILE *archivo;
    char caracter;
    archivo = fopen("prueba.txt","r");
    char aristasAdyacentes[50];
    int i=0;
    if (archivo == NULL){
                printf("\nError de apertura del archivo. \n\n");
    }else{
    	i=0;
    	while(feof(archivo) == 0){
    		caracter = fgetc(archivo);
    		if(fgetc(archivo) == '['){
    			aristasAdyacentes[i] = caracter;
				i++;
			}
		}
	}
	fclose(archivo);
	return (int)aristasAdyacentes[pos]-48;
}
int saleDestino(int pos){
	FILE *archivo;
    char caracter;
    archivo = fopen("prueba.txt","r");
    char aristasAdyacentes[50];
    int i=0;
    if (archivo == NULL){
                printf("\nError de apertura del archivo. \n\n");
    }else{
    	i=0;
    	while(feof(archivo) == 0){
    		caracter = fgetc(archivo);
    		if(fgetc(archivo) == '-'){
    			aristasAdyacentes[i] = caracter;
				i++;
			}
		}
	}
	fclose(archivo);
	return (int)aristasAdyacentes[pos]-48;
}
int salePeso(int pos){
	FILE *archivo;
    char caracter;
    char sig;
    archivo = fopen("prueba.txt","r");
    char aristasAdyacentes[50];
    int i=0;
    if (archivo == NULL){
                printf("\nError de apertura del archivo. \n\n");
    }else{
    	i=0;
    	while(feof(archivo) == 0){
    		caracter = fgetc(archivo);
    		sig = fgetc(archivo);
    		if(sig == ',' || sig == ']'){
    			aristasAdyacentes[i] = caracter;
				i++;
			}
		}
	}
	fclose(archivo);
	return (int)aristasAdyacentes[pos]-48;
}


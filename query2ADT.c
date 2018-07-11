#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "query2ADT.h"

typedef struct q2Node{
    char oaci[5];
    char iata[4];
    long tkoffs;
    long ldings;
    long suma;
    struct q2Node * next;
} q2Node;


typedef struct query2CDT{
	q2Node * first;
} query2CDT;

query2ADT newQuery2(){
    return calloc(1, sizeof(query2CDT));
}

void add2(query2ADT query, char * oaci, char * iata, int isOrigin){

    q2Node *aux;

    /*Si la lista esta vacia o el OACI del aeropuerto es menor (en orden alfabetico)
    que el primero de la lista, crear un nodo dedicado a ese aeropuerto e inicializar
    la cantidad de movimientos con 1*/

    if(query->first==NULL || strcmp(oaci, query->first->oaci)<0){

        aux=malloc(sizeof(q2Node));
        strcpy(aux->iata, iata);
        strcpy(aux->oaci, oaci);
        if(isOrigin){
            aux->tkoffs=1;
            aux->ldings=0;
        }
        else{
            aux->tkoffs=0;
            aux->ldings=1;
        }
        aux->suma=1;
        aux->next=query->first;
        query->first=aux;

        }

    /*Si el primero de la lista tiene el OACI que buscamos, agregar uno a la cantidad
    de movimientos*/

    else if(strcmp(oaci, query->first->oaci)==0){

            if(isOrigin)
                query->first->tkoffs++;
            else query->first->ldings++;

            query->first->suma++;
    }

    /*En cualquier otro caso, buscar hasta encontrar el OACI o crear un nuevo nodo si
    no se encontro*/

    else{
		int found=1;
        aux=query->first;
        while(aux->next!=NULL && !(strcmp(oaci, aux->next->oaci)<0) && !found){
            if(strcmp(oaci, aux->next->oaci)==0){

                if(isOrigin)
                    aux->next->tkoffs++;
                else aux->next->ldings++;
                aux->next->suma++;
                found=1;
            }
        }
		if(!found){
	        q2Node * new = malloc(sizeof(q2Node));
	        strcpy(new->iata, iata);
	        strcpy(new->oaci, oaci);
	        if(isOrigin){
	            new->tkoffs=1;
	            new->ldings=0;
	        }
	        else{
	            new->tkoffs=0;
	            new->ldings=1;
	        }
	        new->suma=1;
	        new->next=aux->next;
	        aux->next=new;
		}
    }
}

void printQuery2(query2ADT query, FILE * fd){

    if(query==NULL || query->first==NULL)
        return;

    fprintf(fd, "oaci;iata;cant_despg;cant_aterr;suma\n");
    for(q2Node *aux = query->first; aux!=NULL; aux=aux->next){
        fprintf(fd, "%4s;%3s;%ld;%ld;%ld\n", aux->oaci, aux->iata, aux->tkoffs, aux->ldings, aux->suma);
    }
    return;

}


void freeQuery2(query2ADT query){

    q2Node * aux = query->first, *aux1;
    while(aux!=NULL){

        aux1 = aux->next;
        free(aux);
        aux=aux1;
    }
	free(query);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "query3ADT.h"

typedef struct query3CDT{
    long days[DAYS];
} query3CDT;

query3ADT newQuery3(void){
    return calloc(1, sizeof(query3CDT));
}

void add3(query3ADT query, int day){
	if(day>=0&&day<=6){
		query->days[day]++;
	}
}

void printQuery3(query3ADT query, FILE * fd){

    if(query==NULL)
        return;

    char *days[DAYS]={"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    fprintf(fd, "DiaDeLaSemana:vuelos\n");
    for(int i=0; i<DAYS; i++){

        fprintf(fd, "%s:%ld\n", days[i], query->days[i]);
    }
    return;

}

void freeQuery3(query3ADT query){
    free(query);
}

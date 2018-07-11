#include <stdio.h>
#include <string.h>
#include "TAD.h"
#include "query1ADT.h"
#include "query2ADT.h"
#include "query3ADT.h"
#include "query4ADT.h"
#include "process_queries.h"
#define LOC 0
#define INT 1
#define ORIG 1
#define DEST 0

/*
    Yo creo que cuando pasemos los aeropuertos a memoria, usemos un vector de structs
    que tienen los siguientes datos (unicamente): oaci, desc, iata, local
    Estas son las cosas que irian en el while del main, cada vez que tomamos un vuelo.
*/

static int getDayOfWeek(VTFecha fecha){
	int f,k,m,d,c;

	k=fecha.dia;

	m=fecha.mes;
	m-=2;
	m=m>0?m:m+12;

	d=m>=11?( fecha.anio % 100)-1:fecha.anio%100;

	c=fecha.anio/100;

	f = k + ((13*m - 1)/5) + d + (d/4) + (c/4) - 2*c;//la regla de zeller
	f=f%7;

	return (f==0?7:f)-1;
}

//Agrega los datos provisorios al query1.
static void process_query1(query1ADT query, vueloADT vuelo,
	AeropuertoADT orig,AeropuertoADT dest){

    //getLocal y getDesc se supone que obtengan los datos correspondientes de la tabla
    //de aeropuertos que pasamos a memoria. No se si se la pasamos a una funcion o usamos
    //una variable global
	if(orig!=NULL){
		add1(query, getVueloOrigOaci(vuelo), getAeropuertoLocal(orig), getAeropuertoDenominacion(orig));
	}
	if(dest!=NULL){
		add1(query, getVueloDestOaci(vuelo), getAeropuertoLocal(dest), getAeropuertoDenominacion(dest));
	}
}

static void process_query2(query2ADT query, vueloADT vuelo,
	AeropuertoADT orig,AeropuertoADT dest){

    if(getVueloClasificacion(vuelo)==INT){
        if(orig!=NULL){ //Busca al aeropuerto en la lista de aeropuertos locales (segun oaci)
				char* iata=getAeropuertoIATA(orig);
				if(iata!=NULL&&strlen(iata)==3){
					add2(query, getVueloOrigOaci(vuelo),iata, ORIG);
				}
        }
        else if(dest!=NULL){
			char* iata=getAeropuertoIATA(dest);
			if(iata!=NULL&&strlen(iata)==3){
                add2(query, getVueloDestOaci(vuelo),iata, DEST);
			}
        }
    }
}

static void process_query3(query3ADT query, vueloADT vuelo){

    int c;
    if((c=getDayOfWeek(getVueloFecha(vuelo)))!=-1){  /*getDayOfWeek recibe una fecha y retorna un dia de semana [0-6],
                                                	si hay algun error retorna -1*/
        add3(query,c);
    }
}

static void process_query4(query4ADT query,vueloADT vuelo,
	AeropuertoADT orig,AeropuertoADT dest){

	int flagLocDes=orig!=NULL
	,flagLocAter=dest!=NULL;
	add4(query,getVueloOrigOaci(vuelo),flagLocDes,getVueloDestOaci(vuelo),flagLocAter);
}

void processVuelo(
	AeroListaADT aerolista,
	query1ADT query1,query2ADT query2,query3ADT query3, query4ADT query4,
	vueloADT vuelo){

	AeropuertoADT aOrig=NULL,aDest=NULL;

	aOrig=getAeropuertoFromAeroLista(aerolista,getVueloOrigOaci(vuelo));
	aDest=getAeropuertoFromAeroLista(aerolista,getVueloDestOaci(vuelo));
	process_query1(query1,vuelo,aOrig,aDest);
	process_query2(query2,vuelo,aOrig,aDest);
	process_query3(query3,vuelo);
	process_query4(query4,vuelo,aOrig,aDest);
}

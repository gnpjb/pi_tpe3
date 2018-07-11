#include <stdio.h>
#include <string.h>
#include "TAD.h"
#include "cargarNextVuelo.h"

#define DELIM ";"
#define MAX_LONG_LINEA 500
#define ASCIINUM_TO_INT(c) ((int)(c-'0'))

vueloADT cargarNextVuelo(FILE *f,vueloADT vuelo,int anio){
	char *field
	,linea[MAX_LONG_LINEA]
	,*p_linea;

	VTFecha fecha;
	if(!feof(f)){

		//obtenemos la linea
		p_linea=fgets(linea,MAX_LONG_LINEA,f);
		//obtenemos el primer campo(el dia)
		if(p_linea==NULL){
			return NULL;
		}
		field=strtok(linea,DELIM);
		if(field!=NULL){
			fecha.dia=ASCIINUM_TO_INT(field[0])*10+ASCIINUM_TO_INT(field[1]);
			fecha.mes=ASCIINUM_TO_INT(field[3])*10+ASCIINUM_TO_INT(field[4]);
			fecha.anio=ASCIINUM_TO_INT(field[6])*1000+ASCIINUM_TO_INT(field[7])*100+ASCIINUM_TO_INT(field[8])*10+ASCIINUM_TO_INT(field[9]);
			setVueloFecha(vuelo,fecha);
			//luego la hora
			field=strtok(NULL,DELIM);
			if(field!=NULL||fecha.anio!=anio){
				//luego ignoramos el siguiente
				field=strtok(NULL,DELIM);
				if(field!=NULL){

					//luego leemos clasificacion
					field=strtok(NULL,DELIM);
					if(field!=NULL){
						if(strcmp(field,"Internacional")==0){
							setVueloClasificacion(vuelo,V_INTERNACIONAL);
						}
						else if(strcmp(field,"Cabotaje")==0){
							setVueloClasificacion(vuelo,V_CABOTAJE);
						}
						else{
							setVueloClasificacion(vuelo,V_NA);
						}
						//luego leemos tipo de movimiento
						field=strtok(NULL,DELIM);
						if(field!=NULL){
							if(strcmp(field,"Aterrizaje")==0){
								setVueloTipoDeMov(vuelo,V_ATERRIZAJE);
							}
							else{
								setVueloTipoDeMov(vuelo,V_DESPEGUE);
							}

							//luego leemos oaci de origen
							field=strtok(NULL,DELIM);
							if(field!=NULL){
								if(field!=NULL)
								setVueloOrigOaci(vuelo,field);
								//luego leemos el oaci de dest
								field=strtok(NULL,DELIM);
								if(field!=NULL){
									if(field!=NULL)
									setVueloDestOaci(vuelo,field);

									}

								}

							}
						}
					}
			}
		}
	}

	return vuelo;
}

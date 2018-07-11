#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

//definicion de constantes que usara el TAD AeropuertoCDT
#define LONG_CODIGO_LOCAL 3
#define LONG_CODIGO_OACI 4
#define LONG_CODIGO_IATA 4

enum{V_INTERNACIONAL,V_CABOTAJE,V_NA};
enum{V_ATERRIZAJE,V_DESPEGUE};

typedef struct VEFecha{
	int dia;
	int mes;
	int anio;
}VTFecha;

typedef struct vueloCDT* vueloADT;

vueloADT newVuelo();

void setVueloFecha(vueloADT vuelo,VTFecha fecha);
void setVueloClasificacion(vueloADT vuelo,char clasificacion);
void setVueloTipoDeMov(vueloADT vuelo,char tipoDeMov);
void setVueloOrigOaci(vueloADT vuelo,char origOaci[]);
void setVueloDestOaci(vueloADT vuelo,char destOaci[]);

VTFecha getVueloFecha(vueloADT vuelo);
char getVueloClasificacion(vueloADT vuelo);
char getVueloTipoDeMov(vueloADT vuelo);
char *getVueloOrigOaci(vueloADT vuelo);
char *getVueloDestOaci(vueloADT vuelo);

void freeVuelo(vueloADT vuelo);




typedef struct AeropuertoCDT* AeropuertoADT;
typedef struct AeroListaCDT* AeroListaADT;

AeropuertoADT newAeropuerto();

void setAeropuertoLocal(AeropuertoADT aeropuerto, char local[]);
void setAeropuertoOACI(AeropuertoADT aeropuerto, char oaci[]);
void setAeropuertoIATA(AeropuertoADT aeropuerto, char iata[]);
void setAeropuertoDenominacion(AeropuertoADT aeropuerto,char *denominacion);

char* getAeropuertoLocal(AeropuertoADT aeropuerto);
char* getAeropuertoOACI(AeropuertoADT aeropuerto);
char* getAeropuertoIATA(AeropuertoADT aeropuerto);
char* getAeropuertoDenominacion(AeropuertoADT aeropuerto);

void freeAeropuerto(AeropuertoADT ap);


AeroListaADT newAeroLista();
void addAeroLista(AeroListaADT,AeropuertoADT);
AeropuertoADT getAeropuertoFromAeroLista(AeroListaADT,char oaci[]);
void freeAeroLista(AeroListaADT);

#endif

#ifndef QUERY4ADT_H_INCLUDED
#define QUERY4ADT_H_INCLUDED

enum{Q4_LOCAL,Q4_NO_LOCAL};

typedef struct query4CDT* query4ADT;

query4ADT newQuery4();
//locFlag es un flag que dicta si el oaci es de un aeropuerto local o no local
void add4(query4ADT query,char oaciDes[],char locFlagDes,char oaciAter[],char locFlagAter);
void printQuery4(query4ADT query, FILE *fd);

void freeQuery4(query4ADT query);


#endif

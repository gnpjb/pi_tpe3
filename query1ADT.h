#ifndef QUERY1ADT_H_INCLUDED
#define QUERY1ADT_H_INCLUDED

typedef struct query1CDT * query1ADT;

query1ADT newQuery1(void);
void add1(query1ADT,char * oaci, char * local, char * desc);
void printQuery1(query1ADT,FILE* file);
void freeQuery1(query1ADT);


#endif // QUERY1ADT_H_INCLUDED

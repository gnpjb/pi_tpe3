#ifndef QUERY3ADT_H_INCLUDED
#define QUERY3ADT_H_INCLUDED

#define DAYS 7
typedef struct query3CDT * query3ADT;

query3ADT newQuery3(void);
void add3(query3ADT, int);
void freeQuery3(query3ADT);
void printQuery3(query3ADT,FILE* file);

#endif // QUERY3ADT_H_INCLUDED

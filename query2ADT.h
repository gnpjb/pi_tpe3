#ifndef QUERY2ADT_H_INCLUDED
#define QUERY2ADT_H_INCLUDED

typedef struct query2CDT * query2ADT;

query2ADT newQuery2(void);
void add2(query2ADT, char *, char *, int);
void printQuery2(query2ADT,FILE* file);
void freeQuery2(query2ADT);

#endif // QUERY2ADT_H_INCLUDED

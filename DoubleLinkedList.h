#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Info;

typedef struct Dlistnode{
Info entery[150];
struct Dlistnode *next;
struct Dlistnode *pre;
}DlistNode;

typedef struct {
DlistNode *head;
DlistNode *tail;
int Size;
}DoubleList;

void CreateDoubleList(DoubleList *l);
int DoubleListEmpty(DoubleList *l);
int DoubleListFull(DoubleList *l);
void InsertInLast(DoubleList *l, Info e[]);
void InsertInPos(DoubleList *l, int pos, Info e[]);
void DeleteInPos(DoubleList *l, int pos, Info e[]);
int lenght(DoubleList *l);
void ReplaceLine(DoubleList *l, int pos, Info e[]);
int showLength(DoubleList * pdl,int pos);
int ShowAllLines(char *fileName);
int readFileIntoList(char* filename, DoubleList *pdl);
void destroy(DoubleList *list);
int UploadInNodes(char * Filename,DoubleList * pdl);
int UploadToFile(char * Filename,DoubleList * pdl);
void sortList(DoubleList *pdl);
void TraverseDoubleList(DoubleList *l, void (*p)(Info[]));


#endif // DOUBLELINKEDLIST_H_INCLUDED

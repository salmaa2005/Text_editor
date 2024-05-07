#include "DoubleLinkedList.h"

void CreateDoubleList(DoubleList *l)
{
	l->head = NULL;
	l->tail = NULL;
	l->Size = 0;
}

int DoubleListEmpty(DoubleList *l)
{
	if (l->head == NULL)
		return 1;
	else
		return 0;
}

int DoubleListFull(DoubleList *l)
{
	return 0;
}

void InsertInLast(DoubleList *l, Info e[])
{
	DlistNode *pn = (DlistNode *)malloc(sizeof(DlistNode));
	strcpy(pn->entery, e);
	pn->next = NULL;
	pn->pre = NULL;
	if (l->head == NULL)
	{
		l->head = pn;
		l->tail = pn;
	}
	else
	{
		pn->next = l->tail->next;
		pn->pre = l->tail;
		l->tail->next = pn;
		l->tail = pn;
	}
	l->Size++;
}

void InsertInPos(DoubleList *l, int pos, Info e[])
{
	DlistNode *pn, *temp, *temp2;
	pn = (DlistNode *)malloc(sizeof(DlistNode));
	strcpy(pn->entery, e);
	pn->next = NULL;
	pn->pre = NULL;
	if (l->head == NULL)
	{
		l->head = pn;
		l->tail = pn;
	}
	else if (pos == 0)
	{
		pn->next = l->head;
		l->head->pre = pn;
		l->head = pn;
	}
	else
	{
		temp = l->head;
		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		if (temp == NULL)
		{
			pn->pre = l->tail;
			l->tail->next = pn;
			l->tail = pn;
		}
		else
		{
			temp2 = temp->next;
			pn->pre = temp;
			pn->next = temp2;
			temp->next = pn;
		}
	}
	l->Size++;
}

/*
void InsertD(DoubleList * pdl , int pos ,Info e[])
{
	DlistNode * c=pdl->head;
	DlistNode * pn =(Node *)malloc(sizeof(Node));
	strcpy(pn->entry,e);
	pn->next=NULL ;
	pn->pre=NULL;
	if(pdl->head==NULL)
		pdl->head=pdl->tail=pn;
	else{
		Node *pq=pdl->head;
		for(int i=0;i<pos;i++)
			pq=pq->next;
		if(pq == pdl ->head)
		{
			pn->next=pdl->head;
			pdl->head->prev =pn;
			pdl->head=pn;
		}else if (pq == NULL)
		{
			pdl->tail->next=pn;
			pn->pre=pdl->tail;
			pdl->tail=pn;
		}
		else
		{
			pn->next=pq;
			pn->pre=pq->pre;
			pq->pre->next=pn;
			pq->pre=pn;
		}
	}

	pdl->Size++;
}
*/
void DeleteInPos(DoubleList *l, int pos, Info e[])
{
	DlistNode *pn, *temp;
	pn = l->head;
	if (l->Size == 1)
	{
		strcpy(e, pn->entery);
		l->head = NULL;
		l->tail = NULL;
		free(pn);
	}
	else if (pos == 0)
	{
		strcpy(e, pn->entery);
		pn->next = l->head->next;
		pn->next->pre = NULL;
		l->head = l->head->next;
		free(pn);
	}
	else if (pos == (l->Size - 1))
	{
		pn = l->tail;
		strcpy(e, pn->entery);
		temp = l->tail->pre;
		temp->next = NULL;
		free(pn);
	}
	else
	{
		for (int i = 0; i < pos; i++)
		{
			pn = pn->next;
		}
		strcpy(e, pn->entery);
		pn->pre->next = pn->next;
		pn->next->pre = pn->pre;
		free(pn);
	}
	l->Size--;
}

int lenght(DoubleList *l)
{
	return (l->Size);
}

void ReplaceLine(DoubleList *l, int pos, Info e[])
{
	DlistNode *temp;
	int index;
	char e2[150];
	temp = l->head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	strcpy(temp->entery, e);
}

int UploadToFile(char *Filename, DoubleList *pdl)
{
	FILE *f = fopen(Filename, "w");
	char lines[100];
	DlistNode *pn = pdl->head;
	if (f == NULL)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < pdl->Size; i++)
		{
			strcpy(lines, pn->entery);
			fprintf(f, "%s", lines);
			pn = pn->next;
		}
		fclose(f);
		return 1;
	}
}

// returns 0 if allocation failed
// returns 1 if successful
// adds a line to the end of the list
int addLineToDList(DoubleList *pdl, Info *line)
{
	DlistNode *pn = (DlistNode *)malloc(sizeof(DlistNode));
	if (!pn)
		return 0;
	strcpy(pn->entery, line);
	if (!pdl->head)
	{
		pdl->head = pn;
		pdl->tail = pn;
		pn->next = NULL;
		pn->pre = NULL;
	}
	else
	{
		pn->pre = pdl->tail;
		pn->next = NULL;
		pdl->tail->next = pn;
		pdl->tail = pn;
	}
	pdl->Size++;
	return 1;
}

int showLength(DoubleList *pdl, int pos)
{
	char e[150];
	DlistNode *n;
	int i = 0;
	if (pos == 0)
	{
		strcpy(e, pdl->head->entery);
	}
	else
	{
		for (n = pdl->head; i < pos - 1; i++)
		{
			n = n->next;
		}
		strcpy(e, n->entery);
	}
	e[strcspn(e, "\n")] = 0;
	return strlen(e);
}

int readFileIntoList(char *filename, DoubleList *pdl)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}
	char lines[100];
	int c = 0;
	Info e;
	while (fgets(lines, sizeof(lines), file))
	{
		InsertInPos(pdl, c, lines);
		c++;
	}
	fclose(file);
	return 1;
}

void destroy(DoubleList *list)
{
	DlistNode *tmp;
	while (list->Size)
	{
		tmp = list->head->next;
		free(list->head);
		list->head = tmp;
		list->Size--;
	}
	list->head = NULL;
	list->tail = NULL;
}

void sortList(DoubleList *pdl)
{
	DlistNode *pn = pdl->head;
	DlistNode *pq = NULL;
	Info e[100];
	if (pdl->head == NULL)
		return;
	else
	{
		while (pn != NULL)
		{
			pq = pn->next;
			while (pq != NULL)
			{
				if (strlen(pn->entery) > strlen(pq->entery))
				{
					strcpy(e, pn->entery);
					strcpy(pn->entery, pq->entery);
					strcpy(pq->entery, e);
				}
				pq = pq->next;
			}
			pn = pn->next;
		}
	}
}

void TraverseDoubleList(DoubleList *l, void (*p)(Info[]))
{
	DlistNode *pe;
	pe = l->head;
	if (l->Size == 0)
		(*p)("NO Data. \n");
	while (pe != NULL)
	{
		(*p)(pe->entery);
		pe = pe->next;
	}
}

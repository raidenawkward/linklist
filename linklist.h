#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdlib.h>
#include "define.h"

struct LinkList {
	LinkElement data;
	struct LinkList *next;
};

/// create link list with head
void linklist_create(struct LinkList **L);
void linklist_destory(struct LinkList **L);
/// get link list length without head node
int linklist_length(struct LinkList *L);

struct LinkList* linklist_get_pos_node(struct LinkList *L, int pos);
int linklist_insert_elem(struct LinkList **L, int pos, LinkElement e);
int linklist_remove(struct LinkList **L, int pos);

void linklist_traverse(struct LinkList *L,int (*f)(struct LinkList*));
int linklist_show_node(struct LinkList *L);

#endif //_LINKLIST_H

#include "linklist.h"
#include <stdio.h>

void linklist_create(struct LinkList **L) {
	*L = (struct LinkList*)malloc(sizeof(struct LinkList));
	(*L)->next = NULL;
	(*L)->data = 0x00;
}

void linklist_destory(struct LinkList **L) {
	if (!(*L))
		return;
	if ((*L)->next)
		linklist_destory(&(*L)->next);
	free((*L));
	(*L) = NULL;
}

Int32 linklist_length(struct LinkList *L) {
	Int32 length = 0;
	if (!L) {
		return length;
	}
	struct LinkList *p = L->next;
	while (p) {
		++length;
		p = p->next;
	}
	return length;
}

void linklist_traverse(struct LinkList *L,Int32 (*f)(struct LinkList*)) {
	struct LinkList *p = L;
	if (!f)
		return;
	while (p->next) {
		p = p->next;
		f(p);
	}
}

Int32 linklist_show_node(struct LinkList *L) {
	printf("%c\n",L->data);
	return 0;
}

struct LinkList* linklist_get_pos_node(struct LinkList *L, Int32 pos) {
	if (pos < 0)
		return NULL;
	struct LinkList *p = L;
	Int32 i = 0;
	for (; i <= pos; ++i) {
		if (!p->next) {
			return NULL;
		}
		p = p->next;
	}

	return p;
}

Int32 linklist_insert_elem(struct LinkList **L, Int32 pos, LinkElement e) {
	if (pos < 0)
		return -1;
	struct LinkList *p;
	p = pos > 0? linklist_get_pos_node(*L,pos - 1 < 0? 0:pos - 1) : *L;
	if (!p)
		return -1;

	struct LinkList *new = (struct LinkList*)malloc(sizeof(struct LinkList));
	new->data = e;
	new->next = p->next;
	p->next = new;

	return 1;
}

Int32 linklist_remove(struct LinkList **L, Int32 pos) {
	if (pos < 0)
		return -1;
	struct LinkList *p, *q;

	// get prev node
	if (pos == 0)
		p = (*L);
	else
		p = linklist_get_pos_node(*L,pos - 1 < 0? 0:pos - 1);
	if (!p)
		return -1;
	q = p->next;
	if (!q)
		return -1;
	p->next = q->next;
	free(q);

	return 1;
}

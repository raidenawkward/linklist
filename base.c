#include "linklist.h"
#include "base.h"
#include <stdio.h>

void linklist_create(struct LinkList **L) {
	*L = (struct LinkList*)malloc(sizeof(struct LinkList));
	if (!(*L))
		return;
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

Int32 linklist_clear(struct LinkList **L) {
	if (!*L)
		return ERROR;
	struct LinkList *p = (*L)->next;
	(*L)->next = NULL;
	linklist_destory(&p);
	return SUCCEED;
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
		if (f(p) < 0)
			return;
	}
}

Int32 linklist_show_node(struct LinkList *L) {
	printf("%c\n",L->data);
	return 0;
}

Int32 linklist_get_pos_elem(struct LinkList *L, int pos, LinkElement *e) {
	struct LinkList *node = linklist_get_pos_node(L,pos);
	if (!node)
		return ERROR;
	*e = node->data;
	return SUCCEED;
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

struct LinkList* linklist_get_last_node(struct LinkList *L) {
	if (!L)
		return NULL;
	struct LinkList *last = L;
	while (last->next) {
		last = last->next;
		if (!last->next)
			return last;
	}
	return last;
}

Int32 linklist_insert_elem(struct LinkList **L, Int32 pos, LinkElement e) {
	if (pos < 0)
		return ERROR;
	struct LinkList *p;
	p = pos > 0? linklist_get_pos_node(*L,pos - 1 < 0? 0:pos - 1) : *L;
	if (!p)
		return ERROR;

	struct LinkList *new = (struct LinkList*)malloc(sizeof(struct LinkList));
	if (!new)
		return ERROR;
	new->data = e;
	new->next = p->next;
	p->next = new;

	return SUCCEED;
}

Int32 linklist_remove(struct LinkList **L, Int32 pos) {
	if (pos < 0)
		return ERROR;
	struct LinkList *p, *q;

	// get prev node
	if (pos == 0)
		p = (*L);
	else
		p = linklist_get_pos_node(*L,pos - 1);
	if (!p)
		return ERROR;
	q = p->next;
	if (!q)
		return ERROR;
	p->next = q->next;
	free(q);

	return SUCCEED;
}

Int32 linklist_append_elem(struct LinkList **L, LinkElement e) {
	if (!*L)
		return ERROR;
	return linklist_insert_elem(L, linklist_length(*L), e);
}

Int32 linklist_join(struct LinkList **dest, struct LinkList **src, Int32 pos) {
	if (!(*dest) || !(*src) || !(*src)->next || pos < 0)
		return ERROR;
	struct LinkList *prev;
	struct LinkList *src_peeled = (*src)->next, *src_last;
	if (pos == 0)
		prev = (*dest);
	else
		prev = linklist_get_pos_node(*dest, pos - 1);
	if (!prev)
		return ERROR;
	Int32 src_length = linklist_length(*src);
	src_last = linklist_get_pos_node(*src, src_length - 1);
	if (!src_last)
		return ERROR;
	src_last->next = prev->next;
	prev->next = src_peeled;
	return SUCCEED;
}

Int32 linklist_insert_node(struct LinkList **L, struct LinkList *node, Int32 pos) {
	if (!(*L) || !node)
		return ERROR;

	struct LinkList *last = linklist_get_last_node(node);
	struct LinkList *prev;
	if (pos == 0)
		prev = *L;
	else
		prev = linklist_get_pos_node(*L,pos - 1);
	if (!prev)
		return ERROR;
	last->next = prev->next;
	prev->next = node;
	return SUCCEED;
}

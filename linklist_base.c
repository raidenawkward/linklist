#include "linklist.h"
#include "linklist_base.h"
#include <stdio.h>

void linklist_create(struct LinkList **L) {
	*L = (struct LinkList*)malloc(sizeof(struct LinkList));
	if (!(*L))
		return;
	(*L)->next = NULL;
	(*L)->data = 0x00;
}

struct LinkList* linklist_create_node() {
	struct LinkList *node = (struct LinkList*)malloc(sizeof(struct LinkList));
	if (!node)
		return NULL;
	node->next = NULL;
	node->data = 0x00;
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
		return 0;

	Int32 ret = 0;
	struct LinkList *p = (*L)->next;
	while(p) {
		struct LinkList *node = p;
		p = p->next;
		free(node);
		++ret;
	}

	(*L)->next = NULL;
	return ret;
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
		return false;
	*e = node->data;
	return true;
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

Boolean linklist_insert_elem(struct LinkList **L, Int32 pos, LinkElement e) {
	if (pos < 0)
		return false;
	struct LinkList *p;
	p = pos > 0? linklist_get_pos_node(*L,pos - 1 < 0? 0:pos - 1) : *L;
	if (!p)
		return false;

	struct LinkList *new = (struct LinkList*)malloc(sizeof(struct LinkList));
	if (!new)
		return false;
	new->data = e;
	new->next = p->next;
	p->next = new;

	return true;
}

Boolean linklist_remove(struct LinkList **L, Int32 pos) {
	if (pos < 0)
		return false;
	struct LinkList *p, *q;

	// get prev node
	if (pos == 0)
		p = (*L);
	else
		p = linklist_get_pos_node(*L,pos - 1);
	if (!p)
		return false;
	q = p->next;
	if (!q)
		return false;
	p->next = q->next;
	free(q);

	return true;
}

Boolean linklist_append_elem(struct LinkList **L, LinkElement e) {
	if (!*L)
		return false;
	return linklist_insert_elem(L, linklist_length(*L), e);
}

Boolean linklist_join(struct LinkList **dest, struct LinkList **src, Int32 pos) {
	if (!(*dest) || !(*src) || !(*src)->next || pos < 0)
		return false;
	struct LinkList *prev;
	struct LinkList *src_peeled = (*src)->next, *src_last;
	if (pos == 0)
		prev = (*dest);
	else
		prev = linklist_get_pos_node(*dest, pos - 1);
	if (!prev)
		return false;
	Int32 src_length = linklist_length(*src);
	src_last = linklist_get_pos_node(*src, src_length - 1);
	if (!src_last)
		return false;
	src_last->next = prev->next;
	prev->next = src_peeled;
	return true;
}

Boolean linklist_insert_node(struct LinkList **L, struct LinkList *node, Int32 pos) {
	if (!(*L) || !node)
		return false;

	struct LinkList *last = linklist_get_last_node(node);
	struct LinkList *prev;
	if (pos == 0)
		prev = *L;
	else
		prev = linklist_get_pos_node(*L,pos - 1);
	if (!prev)
		return false;
	last->next = prev->next;
	prev->next = node;
	return true;
}

/// external functions

/// method 1
// returns head of link list after reverse
static struct LinkList* _list_reverse_prev = NULL;
static struct LinkList* _list_reverse(struct LinkList **L) {
	if (!*L)
		return NULL;
	struct LinkList *next = (*L)->next;
	(*L)->next = _list_reverse_prev;
	_list_reverse_prev = (*L);
	if (next) {
		return _list_reverse(&next);
	}
	else {
		_list_reverse_prev = NULL;
		return (*L);
	}
}

Boolean linklist_reverse(struct LinkList **L) {
	if (!(*L) || !(*L)->next)
		return false;
	struct LinkList *list_peeled = (*L)->next;
	(*L)->next = _list_reverse(&list_peeled);
	_list_reverse_prev = NULL;
	return true;
}


/// functions for save and load

static FILE* _linklist_io_fp = NULL;

static Boolean _linklist_save_node(struct LinkList *node) {

}

static struct LinkList* _linklist_load_node(FILE* fp) {

}

Boolean linklist_save(struct LinkList *L, const char* path, struct linklist_operation *baseop) {
	if (!baseop || !path || !L)
		return false;
	if (!baseop->traverse)
		return false;
	_linklist_io_fp = fopen(path,"wb");
	if (!_linklist_io_fp)
		return false;

	baseop->traverse(L,_linklist_save_node);

	fclose(_linklist_io_fp);
	return true;
}

Boolean linklist_load(struct LinkList **L, const char* path, struct linklist_operation *baseop) {

}

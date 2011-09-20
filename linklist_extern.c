#include "linklist_extern.h"
#include <stdio.h>

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

Int32 linklist_reverse(struct LinkList **L) {
	if (!(*L) || !(*L)->next)
		return ERROR;
	struct LinkList *list_peeled = (*L)->next;
	(*L)->next = _list_reverse(&list_peeled);
	_list_reverse_prev = NULL;
	return SUCCEED;
}


/// functions for save and load

static FILE* _linklist_io_fp = NULL;

static Int32 _linklist_save_node(struct LinkList *node) {

}

static struct LinkList* _linklist_load_node(FILE* fp) {

}

Int32 linklist_save(struct LinkList *L, const char* path, struct linklist_operation *baseop) {
	if (!baseop || !path || !L)
		return ERROR;
	if (!baseop->traverse)
		return ERROR;
	_linklist_io_fp = fopen(path,"wb");
	if (!_linklist_io_fp)
		return ERROR;

	baseop->traverse(L,_linklist_save_node);

	fclose(_linklist_io_fp);
	return SUCCEED;
}

Int32 linklist_load(struct LinkList **L, const char* path, struct linklist_operation *baseop) {

}

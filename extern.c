#include "extern.h"
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

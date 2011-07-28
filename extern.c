#include "extern.h"
#include <stdio.h>

/// method 1
static struct LinkList* prev = NULL;
static struct LinkList* list_reverse(struct LinkList **L) {
	if (!*L)
		return NULL;
	struct LinkList *next = (*L)->next;
	(*L)->next = prev;
	prev = (*L);
	if (next) {
		return list_reverse(&next);
	}
	else {
		prev = NULL;
		return (*L);
	}
}

Int32 linklist_reverse(struct LinkList **L) {
	if (!(*L) || !(*L)->next)
		return ERROR;
	struct LinkList *list_peeled = (*L)->next;
	(*L)->next = list_reverse(&list_peeled);
	return SUCCEED;
}

#include "extern.h"
#include <stdio.h>

static first_node = 0;
static struct LinkList* list_reverse(struct LinkList **L) {
	if (!*L)
		return NULL;
	printf("reversing : %c\n",(*L)->data);
	if ((*L)->next) {
		struct LinkList* node_next = list_reverse(&((*L)->next));
		if (node_next) {
			node_next->next = (*L);
		}
		if (first_node) {
			(*L)->next = NULL;
			first_node = 0;
		}
	}
}

Int32 linklist_reverse(struct LinkList **L) {
	if (!(*L) || !(*L)->next)
		return ERROR;
	struct LinkList *list_peeled = (*L)->next;
	first_node = 1;
	list_reverse(&list_peeled);
	(*L)->next = list_peeled;
	return SUCCEED;
}

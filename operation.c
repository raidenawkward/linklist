#include "operation.h"
#include "base.h"
#include "extern.h"

struct LinkListOperation* linklist_get_operation() {
	struct LinkListOperation *op = (struct LinkListOperation*)malloc(sizeof(struct LinkListOperation));

	if (!op)
		return NULL;

	op->create = linklist_create;
	op->destory = linklist_destory;
	op->clear = linklist_clear;
	op->get_length = linklist_length;
	op->append_elem = linklist_append_elem;
	op->get_pos_elem = linklist_get_pos_elem;
	op->get_pos_node = linklist_get_pos_node;
	op->get_last_node = linklist_get_last_node;
	op->insert_elem = linklist_insert_elem;
	op->remove = linklist_remove;
	op->join = linklist_join;
	op->insert_node = linklist_insert_node;
	op->traverse = linklist_traverse;
	op->show_node = linklist_show_node;

	return op;
}

struct LinkListOperation_Extern* linklist_get_operation_extern() {
	struct LinkListOperation_Extern *op = (struct LinkListOperation_Extern*)malloc(sizeof(struct LinkListOperation_Extern));
	if (!op)
		return NULL;

	op->reverse = linklist_reverse;
	op->save = linklist_save;
	op->load = linklist_load;

	return op;
}

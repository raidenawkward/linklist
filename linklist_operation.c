#include "linklist_operation.h"
#include "linklist_base.h"
#include "linklist_extern.h"

struct linklist_operation* linklist_get_operation() {
	struct linklist_operation *op = (struct linklist_operation*)malloc(sizeof(struct linklist_operation));

	if (!op)
		return NULL;

	op->create = linklist_create;
	op->create_node = linklist_create_node;
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

	op->reverse = linklist_reverse;
	op->save = linklist_save;
	op->load = linklist_load;

	return op;
}


#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"
#include "linklist_operation.h"

static struct linklist_operation *linklist_op;
static struct linklist_operation_extern *linklist_op_extern;

int main(int argc, char** argv) {
	linklist_op = linklist_get_operation();
	linklist_op_extern = linklist_get_operation_extern();
	if (!linklist_op)
		return 1;
	if (!linklist_op_extern)
		return 1;

	struct LinkList *L,*L1;
	linklist_op->create(&L);
	linklist_op->create(&L1);

	linklist_op->append_elem(&L,'a');
	linklist_op->append_elem(&L,'b');
	linklist_op->append_elem(&L,'c');
	linklist_op->append_elem(&L,'d');
	linklist_op->append_elem(&L,'e');

	printf("before reverse :\n");
	linklist_op->traverse(L,linklist_op->show_node);
	linklist_op_extern->reverse(&L);

	printf("after reverse :\n");
	linklist_op->traverse(L,linklist_op->show_node);
	
	linklist_op_extern->reverse(&L);
	printf("after reverse again:\n");
	linklist_op->traverse(L,linklist_op->show_node);

	return 0;
}

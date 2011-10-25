#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"
#include "linklist_operation.h"

static struct linklist_operation *linklist_op;
static struct linklist_operation_extern *linklist_op_extern;

int main(int argc, char** argv) {
	linklist_op = linklist_get_operation();
	if (!linklist_op)
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
	linklist_op->reverse(&L);

	printf("after reverse :\n");
	linklist_op->traverse(L,linklist_op->show_node);
	
	linklist_op->reverse(&L);
	printf("after reverse again:\n");
	linklist_op->traverse(L,linklist_op->show_node);

	linklist_op->destory(&L);
	linklist_op->destory(&L1);
	free(linklist_op);
	return 0;
}

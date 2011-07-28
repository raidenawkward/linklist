#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"
#include "operation.h"

static struct LinkListOperation *linklist_op;

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

	linklist_op->append_elem(&L1,'1');
	linklist_op->append_elem(&L1,'2');
	linklist_op->append_elem(&L1,'3');

	//linklist_op->join(&L,&L1,1);
	linklist_op->insert_node(&L,L1->next,1);

	linklist_op->traverse(L,linklist_op->show_node);

	return 0;
}

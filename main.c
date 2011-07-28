#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"


int main(int argc, char** argv) {
	struct LinkList *L,*L1;
	linklist_create(&L);
	linklist_create(&L1);

	linklist_append_elem(&L,'a');
	linklist_append_elem(&L,'b');
	linklist_append_elem(&L,'c');

	linklist_append_elem(&L1,'1');
	linklist_append_elem(&L1,'2');
	linklist_append_elem(&L1,'3');

	//linklist_join(&L,&L1,1);
	linklist_insert_node(&L,L1->next,1);

	linklist_traverse(L,linklist_show_node);

	return 0;
}

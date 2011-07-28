#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"


int main(int argc, char** argv) {
	struct LinkList *L,*L1;
	linklist_create(&L);
	linklist_create(&L1);

	linklist_insert_elem(&L,0,'a');
	linklist_insert_elem(&L,0,'b');
	linklist_insert_elem(&L,0,'c');

	linklist_insert_elem(&L1,0,'1');
	linklist_insert_elem(&L1,0,'2');
	linklist_insert_elem(&L1,0,'3');

	linklist_join(&L,&L1,1);

	linklist_traverse(L,linklist_show_node);
	return 0;
}

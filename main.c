#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"


int main(int argc, char** argv) {
	struct LinkList *L;
	linklist_create(&L);
	linklist_insert_elem(&L,0,'a');
	linklist_insert_elem(&L,0,'b');
	linklist_insert_elem(&L,0,'c');
	printf("list length : %d\n",linklist_length(L));
	linklist_traverse(L,linklist_show_node);
	printf("removing \n");
	linklist_remove(&L,0);
	linklist_traverse(L,linklist_show_node);
	printf("list length : %d\n",linklist_length(L));
	linklist_destory(&L);
	printf("list length : %d\n",linklist_length(L));
	return 0;
}

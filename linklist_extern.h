#ifndef _LINKLIST_EXTERN_H
#define _LINKLIST_EXTERN_H

#include <stdlib.h>
#include "linklist_define.h"
#include "linklist.h"

/// reverse all nodes in link list except head node
Int32 linklist_reverse(struct LinkList **L);
/// save link list to file
Int32 linklist_save(struct LinkList *L, const char* path, struct linklist_operation *baseop);
/// load link list from file
Int32 linklist_load(struct LinkList **L, const char* path, struct linklist_operation *baseop);

#endif // _LINKLIST_EXTERN_H

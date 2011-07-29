#ifndef _EXTERN_H
#define _EXTERN_H

#include <stdlib.h>
#include "define.h"
#include "linklist.h"

/// reverse all nodes in link list except head node
Int32 linklist_reverse(struct LinkList **L);
/// save link list to file
Int32 linklist_save(struct LinkList *L, const char* path, struct LinkListOperation *baseop);
/// load link list from file
Int32 linklist_load(struct LinkList **L, const char* path, struct LinkListOperation *baseop);

#endif // _EXTERN_H

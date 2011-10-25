#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "linklist_define.h"

struct LinkList {
    LinkElement data;
    struct LinkList *next;
};

/// operations for link list with head node
struct linklist_operation {
	/// base operations
	void (*create)(struct LinkList **L);
	void (*destory)(struct LinkList **L);
	Int32 (*clear)(struct LinkList **L);
	Int32 (*get_length)(struct LinkList *L);
	Boolean (*append_elem)(struct LinkList **L, LinkElement e);
	Int32 (*get_pos_elem)(struct LinkList *L, int pos, LinkElement *e);
	struct LinkList* (*get_pos_node)(struct LinkList *L, Int32 pos);
	struct LinkList* (*get_last_node)(struct LinkList *L);
	Boolean (*insert_elem)(struct LinkList **L, Int32 pos, LinkElement e);
	Boolean (*remove)(struct LinkList **L, Int32 pos);
	Boolean (*join)(struct LinkList **dest, struct LinkList **src, Int32 pos);
	Boolean (*insert_node)(struct LinkList **L, struct LinkList *node, Int32 pos);
	void (*traverse)(struct LinkList *L,Int32 (*f)(struct LinkList*));
	Int32 (*show_node)(struct LinkList *L);
};

struct linklist_operation_extern {
	/// external operations
	Int32 (*reverse)(struct LinkList **L);
	Int32 (*save)(struct LinkList *L, const char* path, struct linklist_operation *baseop);
	Int32 (*load)(struct LinkList **L, const char* path, struct linklist_operation *baseop);
};

#endif // _LINKLIST_H

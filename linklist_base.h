#ifndef _LINKLIST_LINKLIST_BASE_H
#define _LINKLIST_BASE_H

#include <stdlib.h>
#include "linklist_define.h"
#include "linklist.h"

/// create link list with head node
void linklist_create(struct LinkList **L);
/// create link list node
struct LinkList* linklist_create_node();
/// destory all nodes include head node
void linklist_destory(struct LinkList **L);
/// destory all nodes but head node, false returns if NULL list
Int32 linklist_clear(struct LinkList **L);
/// get link list length without head node
Int32 linklist_length(struct LinkList *L);
/// append element to tail of link list
Boolean linklist_append_elem(struct LinkList **L, LinkElement e);
/// get value of link list on pos, false returns if failed
Int32 linklist_get_pos_elem(struct LinkList *L, int pos, LinkElement *e);
/// get link list node on pos, NULL if failed
struct LinkList* linklist_get_pos_node(struct LinkList *L, Int32 pos);
/// get the last node in list
struct LinkList* linklist_get_last_node(struct LinkList *L);
/// insert elem into link list on pos, false returns if failed
Boolean linklist_insert_elem(struct LinkList **L, Int32 pos, LinkElement e);
/// remove node on pos, false returns if failed
Boolean linklist_remove(struct LinkList **L, Int32 pos);
/// join another link list with head node into list dest
//  peel the head node of src, then join
Boolean linklist_join(struct LinkList **dest, struct LinkList **src, Int32 pos);
/// insert node or linked nodes to link list
Boolean linklist_insert_node(struct LinkList **L, struct LinkList *node, Int32 pos);

/// traverse in link list in sequence, NOT includes head node!
// traverse stops immediately if f returns less than 0
void linklist_traverse(struct LinkList *L,Int32 (*f)(struct LinkList*));
/// print link list node data as char
Int32 linklist_show_node(struct LinkList *L);

/// external functions

/// reverse all nodes in link list except head node
Boolean linklist_reverse(struct LinkList **L);
/// save link list to file
Boolean linklist_save(struct LinkList *L, const char* path, struct linklist_operation *baseop);
/// load link list from file
Boolean linklist_load(struct LinkList **L, const char* path, struct linklist_operation *baseop);


#endif //_LINKLIST_BASE_H

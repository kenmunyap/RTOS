#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct Element_t Element;

//Struct of linkedList
typedef struct{
	Element *head;
	Element *tail;
	int length;
}linkedList;

//Struct of Element;
typedef struct Element_t{
	struct Element_t *next;
	int data;
}Element;

//Function prototype
linkedList *create_linkedList();
void List_addLast(linkedList *list,Element *element);
void List_addFirst(linkedList *list,Element *element);
Element *List_removeLast(linkedList *list);
Element *List_removeFirst(linkedList *list);

#endif //__LINKED_LIST_H__
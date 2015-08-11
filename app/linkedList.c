#include <stdio.h>
#include <malloc.h>
#include "linkedList.h"


void initLinkedList(linkedList *list){
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
}

void List_addLast(linkedList *list,Element *element){
		if(list->head == NULL && list-> tail == NULL){
      list->head = element;
			list->tail = element;
		}else{
      list->tail->next = element;
      list->tail = element;
		}
    element->next = NULL;
		list->length++;
}

Element *List_removeFirst(linkedList *list){
    Element *element; 
    int length;
    if(list->head == NULL && list->tail == NULL){
        return NULL;
    }else if(list->head == list->tail){
      list->head = NULL;
      list->tail = NULL;
      list->length--;
    }else{
      list->head = list->head->next;
      list->length--;
    }
    return element;
}

// void List_addFirst(linkedList *list,Element *element){
		
		
		// if(list->head == NULL && list-> tail == NULL){
			// list->head = element;
			// list->tail = element;
		// }else{
      // element->next = list->head;
			// list->head = element;
		// }
		// list->length++;
// }

// Element *List_removeLast(linkedList *list){
    // Element *element; 
    // int length;
    // if(list->head == NULL && list->tail == NULL){
        // return NULL;
    // }else if(list->head == list->tail){
      // list->head = NULL;
      // list->tail = NULL;
      // list->length--;
    // }else{
      // *(list->tail)--;
      // list->length--;      
    // }
    // return element;
// }


	
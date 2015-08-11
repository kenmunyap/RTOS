#include "unity.h"
#include "linkedList.h"
#include <malloc.h>

void setUp(){}
void tearDown(){}

void test_init_linkedlist(){
  linkedList list;
  initLinkedList(&list);
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
}

void test_add_last_with_head_and_tail_is_NULL(){
  linkedList list;
  Element elementOne = {.next = NULL , .data = 10};
  
  initLinkedList(&list);
  
  List_addLast(&list,&elementOne);
  TEST_ASSERT_EQUAL(1,list.length);
  TEST_ASSERT_EQUAL(10,elementOne.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementOne,list.tail);
}

void test_add_last_with_head_is_point_to_elementOne_and_tail_point_to_elementTwo(){
  linkedList list;
  Element elementOne = {.next = NULL , .data = 10};
  Element elementTwo = {.next = NULL , .data = 20};
  
  initLinkedList(&list);
  
  List_addLast(&list,&elementOne);
  TEST_ASSERT_EQUAL(1,list.length);
  TEST_ASSERT_EQUAL(10,elementOne.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementOne,list.tail);
  
  List_addLast(&list,&elementTwo);
  TEST_ASSERT_EQUAL(2,list.length);
  TEST_ASSERT_EQUAL(20,elementTwo.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementTwo,list.tail);
}

void test_add_last_with_head_is_point_to_elementOne_and_tail_point_to_elementTThree(){
  linkedList list;
  Element elementOne = {.next = NULL , .data = 10};
  Element elementTwo = {.next = NULL , .data = 20};
  Element elementThree = {.next = NULL , .data = 70};
  initLinkedList(&list);
  
  List_addLast(&list,&elementOne);
  TEST_ASSERT_EQUAL(1,list.length);
  TEST_ASSERT_EQUAL(10,elementOne.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementOne,list.tail);
  TEST_ASSERT_EQUAL(NULL,elementOne.next);
  
  List_addLast(&list,&elementTwo);
  TEST_ASSERT_EQUAL(2,list.length);
  TEST_ASSERT_EQUAL(20,elementTwo.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementTwo,list.tail);
  TEST_ASSERT_EQUAL(&elementTwo,elementOne.next);
  TEST_ASSERT_EQUAL(NULL,elementTwo.next);
  
  List_addLast(&list,&elementThree);
  TEST_ASSERT_EQUAL(3,list.length);
  TEST_ASSERT_EQUAL(70,elementThree.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementThree,list.tail);
  TEST_ASSERT_EQUAL(&elementTwo,elementOne.next);
  TEST_ASSERT_EQUAL(&elementThree,elementTwo.next);
  TEST_ASSERT_EQUAL(NULL,elementThree.next);
}

void test_remove_first_with_head_is_point_to_elementOne_and_tail_point_to_elementThree(){
  linkedList list;
  Element elementOne = {.next = NULL , .data = 10};
  Element elementTwo = {.next = NULL , .data = 20};
  Element elementThree = {.next = NULL , .data = 70};
  initLinkedList(&list);
  
  List_addLast(&list,&elementOne);
  TEST_ASSERT_EQUAL(1,list.length);
  TEST_ASSERT_EQUAL(10,elementOne.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementOne,list.tail);
  TEST_ASSERT_EQUAL(NULL,elementOne.next);
  
  List_addLast(&list,&elementTwo);
  TEST_ASSERT_EQUAL(2,list.length);
  TEST_ASSERT_EQUAL(20,elementTwo.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementTwo,list.tail);
  TEST_ASSERT_EQUAL(&elementTwo,elementOne.next);
  TEST_ASSERT_EQUAL(NULL,elementTwo.next);
  
  List_addLast(&list,&elementThree);
  TEST_ASSERT_EQUAL(3,list.length);
  TEST_ASSERT_EQUAL(70,elementThree.data);
  TEST_ASSERT_EQUAL(&elementOne,list.head);
  TEST_ASSERT_EQUAL(&elementThree,list.tail);
  TEST_ASSERT_EQUAL(&elementTwo,elementOne.next);
  TEST_ASSERT_EQUAL(&elementThree,elementTwo.next);
  TEST_ASSERT_EQUAL(NULL,elementThree.next);
  
  List_removeFirst(&list);
  TEST_ASSERT_EQUAL(2,list.length);
  TEST_ASSERT_EQUAL(10,elementOne.data);
  TEST_ASSERT_EQUAL(&elementTwo,list.head);
  TEST_ASSERT_EQUAL(&elementThree,list.tail);
  TEST_ASSERT_EQUAL(&elementTwo,elementOne.next);
  
  List_removeFirst(&list);
  TEST_ASSERT_EQUAL(1,list.length);
  TEST_ASSERT_EQUAL(20,elementTwo.data);
  TEST_ASSERT_EQUAL(&elementThree,list.head);
  TEST_ASSERT_EQUAL(&elementThree,list.tail);
  
  List_removeFirst(&list);
  TEST_ASSERT_EQUAL(0,list.length);
  TEST_ASSERT_EQUAL(70,elementThree.data);
  TEST_ASSERT_EQUAL(NULL,list.head);
  TEST_ASSERT_EQUAL(NULL,list.tail);
}


// void test_create_linkedList_should_return_initialized_linkedList_object(){

	// linkedList *list;
	
	// list = create_linkedList();
	// TEST_ASSERT_NOT_NULL(list);
	// TEST_ASSERT_NULL(list->head);
	// TEST_ASSERT_NULL(list->tail);
	// TEST_ASSERT_EQUAL(0,list->length);
	
// }


// void test_List_addLast_should_add_last_one_element(){

	// linkedList *list;
	
	//initialize the list
	// list = create_linkedList();
	
	//Test fixture
	// Element elemArray[]={							
							// {.next=(Element *)NULL, .data=1}
						// };

	// List_addLast(list,elemArray);
	
	// TEST_ASSERT_NULL(elemArray[0].next);
	// TEST_ASSERT_EQUAL_PTR(&elemArray[0],list->head);
	// TEST_ASSERT_EQUAL_PTR(&elemArray[0],list->tail);
	// TEST_ASSERT_EQUAL(1,elemArray[0].data);
	// TEST_ASSERT_EQUAL(1,list->length);
	
	
	
// }

// void test_List_addLast_should_add_last_second_element(){

	// linkedList *list;
	
	// initialize the list
	// list = create_linkedList();
	
	//Test fixture
	// Element elemArray[]={	
							// {.next=&elemArray[1],   .data=1},	
							// {.next=(Element *)NULL, .data=2}
						// };
						
	// list->head = &elemArray[0];
	// list->tail = &elemArray[0];
	// list->length = 1;
	
	// List_addLast(list,elemArray);
	
	// TEST_ASSERT_NULL(elemArray[1].next);
	// TEST_ASSERT_EQUAL_PTR(&elemArray[0],list->head);
	// TEST_ASSERT_EQUAL_PTR(&elemArray[1],list->tail);
	// TEST_ASSERT_EQUAL(1,elemArray[0].data);
	// TEST_ASSERT_EQUAL(2,elemArray[1].data);
	// TEST_ASSERT_EQUAL(2,list->length);	
// }


// void test_List_addLast_should_add_last_third_element(){

	// linkedList *list;
	
	// initialize the list
	// list = create_linkedList();
	
	//Test fixture
  
  // Element elemArray1 = {.next = NULL, .data = 2};
	// Element elemArray0 = {.next = NULL, .data = 1};
  // Element elemArrayA = {.next = NULL, .data = 4};
  // Element elemArrayB = {.next = NULL, .data = 7};  
	// list->head = &elemArray0;
	// list->tail = &elemArray0;
	// list->length = 1;
	
	// List_addLast(list,&elemArray0);
  // TEST_ASSERT_NULL(elemArray0.next);
	// TEST_ASSERT_EQUAL_PTR(&elemArray0,list->head);
	// TEST_ASSERT_EQUAL_PTR(&elemArray0,list->tail);
	// TEST_ASSERT_EQUAL(1,elemArray0.data);
	// TEST_ASSERT_EQUAL(1,list->length);
  
  // List_addLast(list,&elemArray1);
  // TEST_ASSERT_NULL(elemArray1.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArray0,list->head);
  // TEST_ASSERT_EQUAL_PTR(&elemArray1,list->tail);
  // TEST_ASSERT_EQUAL(1,elemArray0.data);
  // TEST_ASSERT_EQUAL(2,elemArray1.data);
  // TEST_ASSERT_EQUAL(2,list->length);
  
  // List_addFirst(list,&elemArrayA);
  // TEST_ASSERT_NULL(elemArray1.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArrayA,list->head);
  // TEST_ASSERT_EQUAL_PTR(&elemArray0,elemArrayA.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArray1,list->tail);
  // TEST_ASSERT_EQUAL(1,elemArray0.data);
  // TEST_ASSERT_EQUAL(2,elemArray1.data);
  // TEST_ASSERT_EQUAL(4,elemArrayA.data);
  // TEST_ASSERT_EQUAL(3,list->length);
  
  // List_addFirst(list,&elemArrayB);
  // TEST_ASSERT_NULL(elemArray1.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArrayB,list->head);
  // TEST_ASSERT_EQUAL_PTR(&elemArray1,list->tail);
  // TEST_ASSERT_EQUAL(1,elemArray0.data);
  // TEST_ASSERT_EQUAL(2,elemArray1.data);
  // TEST_ASSERT_EQUAL(4,elemArrayA.data);
  // TEST_ASSERT_EQUAL(7,elemArrayB.data);
  // TEST_ASSERT_EQUAL(4,list->length);
  
 // List_removeLast(list);
  // TEST_ASSERT_NULL(elemArray1.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArrayB,list->head);
  // TEST_ASSERT_EQUAL_PTR(&elemArray0,list->tail);
  // TEST_ASSERT_EQUAL(1,elemArray0.data);
  // TEST_ASSERT_EQUAL(4,elemArrayA.data);
  // TEST_ASSERT_EQUAL(7,elemArrayB.data);
  // TEST_ASSERT_EQUAL(3,list->length);
  
  // List_removeFirst(list);
  // TEST_ASSERT_NULL(elemArray1.next);
  // TEST_ASSERT_EQUAL_PTR(&elemArrayA,list->head);
  // TEST_ASSERT_EQUAL_PTR(&elemArray0,list->tail);
  // TEST_ASSERT_EQUAL(1,elemArray0.data);
  // TEST_ASSERT_EQUAL(4,elemArrayA.data);
  // TEST_ASSERT_EQUAL(2,list->length);
// }






	
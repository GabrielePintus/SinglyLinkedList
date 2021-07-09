#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node* next;
};

struct List{
	struct Node* head;
	unsigned int length;
};

typedef struct Node Node;
typedef struct List List;


/*
 *		Constructors
 */

List* new_list(){
	List* list = malloc( sizeof(List) );

	list->head = NULL;
	list->length = 0;

	return list;
}

Node* new_node( int data ){
	Node* new = malloc( sizeof(Node) );

	new->next = NULL;
	new->data = data;

	return new;
}

void free_list( List* list ){
	Node* head = list->head;

	while( head != NULL ){
		list->head = head->next;
		free(head);
	}

	free(list);
}



/*
 *		Read only methods
 */
void printList( List list ){
	Node* curr = list.head;

	printf("----| Length: %d |----\n",list.length);
	while(curr!=NULL){
		printf("%d\n",curr->data);
		curr = curr->next;
	}
}




/*
 *		Modify methods
 */

Node** findNode( List* list , Node* node ){
	
	Node** curr = &(list->head);

	while( (*curr) != node ){
		curr = &((*curr)->next);
	}

	return curr;
}

Node** findNodeAt( List* list , unsigned int index ){
	
	if(index >= list->length){
		return NULL;
	}

	Node** curr = &(list->head);

	unsigned int i = 0;
	while( i < index ){
		curr = &((*curr)->next);
		i++;
	}

	return curr;
}

Node* pop( List* list ){	
	Node* head = list->head;

	list->head = list->head->next;
	list->length--;
	head->next = NULL;

	return head;

}

void popd( List* list ){
	Node* head = pop(list);
	free(head);
}

void push( List* list , Node* node ){
	node->next = list->head;
	list->head = node;
	list->length++;
}

void append( List* list , Node* node ){
	Node** tail = findNode(list,NULL);
	*tail = node;
	list->length++;
}


int insertEntryAt( List* list , Node* new , unsigned int index ){
	if(index==list->length){
		append(list,new);
		return 1;
	}else if(index>list->length){
		return 0;
	}

	Node** node = findNodeAt(list,index);

	if(*node == NULL){
		return 0;
	}

	new->next = *node;
	*node = new;

	return 1;
}

void removeEntry( List* list , Node* entry ){
	Node** node = findNode(list,entry);

	(*node) = (*node)->next;
	list->length--;
}

Node* removeEntryAt( List* list , unsigned int index ){
	Node* node = *findNodeAt(list,index);
	Node** copy = &node;

	removeEntry(list,node);
	(*copy)->next = NULL;
	list->length--;

	return *copy;
}


void reverseList( List* list ){
	Node* prev = NULL;
	Node* curr = list->head;
	Node* next = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list->head = prev;
}


int* listToArray( List list ){
	if(list.length == 0){
		return NULL;
	}

	int* arr = malloc( list.length * sizeof(int) );

	Node* curr = list.head;
	unsigned int i = 0;
	while(curr != NULL){
		arr[i] = curr->data;
		i++;
		curr = curr->next;
	}

	return arr;
}


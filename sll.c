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

Node* getNodeAt( List* list , unsigned int index ){
	unsigned int len = list->length;
	if( len < index || index >= len ){
		return NULL;
	}

	Node** node = &(list->head);
	unsigned int i = 0;

	while( i < index ){
		(*node)++;
		i++;
	}
	
	return *node;
}


void removeEntry( List* list , Node* entry ){
	
	Node** node = findNode(list,entry);

	(*node) = (*node)->next;
	list->length--;
}
// NON FUNZIONA
Node* removeEntryAt( List* list , unsigned int index ){
	Node** node = findNodeAt(list,index);
	removeEntry(list,*node);

	(*node)->next = NULL;

	return *node;
}




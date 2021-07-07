#include <stdio.h>
#include <stdlib.h>
#include "sll.c"




int main(){
	
	Node nodo1,nodo2,nodo3;
	List lista;

	lista.head = NULL;
	lista.length = 0;

	nodo1.next=NULL;
	nodo2.next=NULL;
	nodo3.next=NULL;

	nodo1.data = 1;
	nodo2.data = 2;
	nodo3.data = 3;

	append(&lista,&nodo1);
	append(&lista,&nodo2);
	append(&lista,&nodo3);

	printList(lista);

	
	removeEntry(&lista,&nodo1);

	printList(lista);
	puts("________________");

	//printf("%d\n",NODO->data);
}


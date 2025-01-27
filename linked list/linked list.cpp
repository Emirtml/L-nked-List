#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node * head = NULL;
struct node * tail = NULL;

// add data (veri ekleme linked liste)
void Add(int data) {
	if (head == NULL) {
		struct node* temp = (struct node*)malloc(sizeof(struct  node));
		temp->data = data;
		temp->next = NULL;

		head = tail = temp;
	}
	else {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;				 
		                       
		tail->next = temp;				 
		tail = temp;
	}
}

// listeyi yazdırma
void PrintList() {
	struct node* index;
	index = head;
	
	while (index != NULL) {
		printf("%d\n", index->data);
		index = index->next;
	}
}

// data delete in the list
int pop(int data) {
	struct node* prev = NULL;
	struct node* index = head;

	//linked list is empty
	if (head == NULL) {
		printf("linked list is empty");
		return 1;
	}
	//delete the first element in the list
	if ( head->data == data ) {
		struct node* t = head;
		head = head->next; // sadece bu satırı yazarsak hafızada kalır silinen eleman
		free(t);// böyle yapınca hafızadanda silmşi oluruz
		return 1;
	}

	// if data is not head of the list
	while (index != NULL && index->data != data) {
		prev = index;
		index = index->next;
	}
	
	if (index == NULL) {
		printf("%d cant found in list \n",data);
		return 1;
	}
	prev->next = index->next;

	return 1;
}

int main() {
	
	Add(15);
	Add(16);
	Add(14);
	Add(10);

	pop(15);
	pop(14);
	pop(100);

	PrintList();
}



	











































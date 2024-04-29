#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error creating a new node.\n");
		exit(0);
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
Node* appendNode(Node* head, int data) {
	if (head == NULL)
		return createNode(data);
	Node* cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	Node* newNode = createNode(data);
	cursor->next = newNode;
	newNode->prev = cursor;
	return head;
}
Node* deleteNode(Node* head, Node* node) {
	if (node == head) {
		head = node->next;
		head->prev = NULL;
	}
	else {
		Node* prev = node->prev;
		Node* next = node->next;
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
	free(node);
	return head;
}
void printList(Node* head) {
	Node* cursor = head;
	while (cursor != NULL) {
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
	printf("\n");
}
int main() {
	Node* head = NULL;
	for (int i = 1; i <= 10; i++)
		head = appendNode(head, i);
	printList(head);
	Node* cursor = head;
	for (int i = 0; i < 5; i++)
		cursor = cursor->next;
	head = deleteNode(head, cursor);
	printList(head);
	return 0;
}
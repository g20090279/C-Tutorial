/*    === Example Queue Implemented by Linked List ===
 * Create a queue based on linked list example. A queue supports first 
 * in first out (FIFO) operation. There are two fundamental operations:
 * (1) enqueue (add node to the queue) (2) dequeue (remove node from
 * the queue.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	void *data;
	struct _node *next;  // self referential structure
} Node;

typedef struct _employee{
	char name[32];
	unsigned char age;
} Employee;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

typedef LinkedList Queue;
typedef void(*DISPLAY)(void*); // pass void and return void
typedef int(*COMPARE)(void*, void*); // pass two pointers and return int

// Initialize Queue
void initializeList(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void initializeQueue(Queue *queue) {
	initializeList(queue);
}

// Manipulate Queue: Add to Queue
void addHead(Queue *queue, void* data) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	if(queue->head == NULL) {  // if queue is empty
		queue->tail = node;
		node->next = NULL;
	} else {
		node->next = queue->head;  // if not empty, put new node before head
	}
	queue->head = node;
}

void enqueue(Queue *queue, void *node){
	addHead(queue, node);
}

// Manipulate Queue: Delete from Queue
void *dequeue(Queue *queue) {
	Node *tmp = queue->head;
	void *data;
	if (queue->head == NULL) { // no node in queue
		data = NULL;
	} else if (queue->head == queue->tail) { // only one node in queue
		queue->head = queue->tail = NULL;
		data = tmp->data;  // remember to free data in heap
		free(tmp);
	} else { // multiple nodes in queue
		while (tmp->next != queue->tail) { // traverse from head node
			tmp = tmp->next;
		}
		queue->tail = tmp;
		tmp = tmp->next;
		queue->tail->next = NULL;
		data = tmp->data;
		free(tmp);
	}
	return data;
}

// Display Linked List
void displayEmployee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}

void displayQueue(Queue *queue, DISPLAY display) {
	printf("[Queue]\n");
	Node *current = queue->head;
	while (current != NULL) {
		display(current->data);
		current = current->next;
	}
}

int main() {
	Queue queue;
	initializeQueue(&queue);	

	Employee *samuel = (Employee*) malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 32;

	Employee *sally = (Employee*) malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 28;

	Employee *susan = (Employee*) malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 45;

	enqueue(&queue, samuel);
	enqueue(&queue, sally);
	enqueue(&queue, susan);

	printf("\nAfter add Samuel, Sally, and Susan to the queue:\n");
	displayQueue(&queue, (DISPLAY)displayEmployee);

	void *data = dequeue(&queue);  // first use of data, need to be declared
	printf("\nAfter dequeue %s\n",((Employee*)data)->name);
	displayQueue(&queue, (DISPLAY)displayEmployee);
		
	data = dequeue(&queue);
	printf("\nAfter dequeue %s\n",((Employee*)data)->name);
	displayQueue(&queue, (DISPLAY)displayEmployee);
	
	data = dequeue(&queue);
	printf("\nAfter dequeue %s\n",((Employee*)data)->name);
	displayQueue(&queue, (DISPLAY)displayEmployee);
}

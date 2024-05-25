/*    === Example Single-Linked List ===
 * This code is copied from Richard Reese's book "Understanding and
 * Using C Pointer" (2013), Chapter 6.
 * A block diagram is shown below. variable with * is a pointer.
 *
 * A node contains a data (any type) pointer and an address poitner
 * ---------  ----->---------       -->---------
 * | *data |  |     | *data |          | *data |
 * |       |  |     |       |    ...   |       |
 * | *next |---     | *next |--        | *next |
 * ---------        ---------          ---------
 *    ^   1000            1008             ^
 *    |                                    |
 *  *head                                *tail
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Node
typedef struct _node {
  void *data;
  struct _node *next; // self referential structure
} Node;

// Data in A Node is Employee Information
typedef struct _employee {
  char name[32];
  unsigned char age;
} Employee;

// A Maintain List
typedef struct _linkedList {
  Node *head;
  Node *tail;
  Node *current;
} LinkedList;

// Two Function Pointers
typedef void (*DISPLAY)(void *);        // pass void and return void
typedef int (*COMPARE)(void *, void *); // pass two pointers and return int

// Initialize Maintain List
void initializeList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
}

// Add Node at Head
void addHead(LinkedList *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  if (list->head == NULL) { // if linked list is empty
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head; // if not empty, put new node before head
  }
  list->head = node;
}

// Add Node at Tail
void addTail(LinkedList *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL; // tail node, no next node
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

// Manipulate Linked List: Find Node
int compareEmployee(Employee *e1, Employee *e2) {
  return strcmp(e1->name, e2->name);
}

Node *getNode(LinkedList *list, COMPARE compare, void *data) {
  Node *node = list->head;
  while (node != NULL) {
    if (compare(node->data, data) == 0) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

// Manipulate Linked List: Delete Node
void delete(LinkedList *list, Node *node) {
  if (node == list->head) {
    if (list->head->next == NULL) { // if only one node
      list->head = list->tail = NULL;
    } else {
      list->head = list->head->next;
    }
  } else { // if not head node, find and link next node to previous node
    Node *tmp = list->head;
    while (tmp != NULL && tmp->next != node) {
      tmp = tmp->next;
    }
    if (tmp != NULL) {
      tmp->next = node->next;
    }
  }
  free(node);
  // pointer *tmp will be deleted after function ends since it is on stack
}

// Display Linked List
void displayEmployee(Employee *employee) {
  printf("%s\t%d\n", employee->name, employee->age);
}

void displayLinkedList(LinkedList *list, DISPLAY display) {
  printf("\nLinked List\n");
  Node *current = list->head;
  while (current != NULL) {
    display(current->data);
    current = current->next;
  }
}

// Main Function
int main() {
  LinkedList linkedList;

  Employee *samuel = (Employee *)malloc(sizeof(Employee));
  strcpy(samuel->name, "Samuel");
  samuel->age = 32;

  Employee *sally = (Employee *)malloc(sizeof(Employee));
  strcpy(sally->name, "Sally");
  sally->age = 28;

  Employee *susan = (Employee *)malloc(sizeof(Employee));
  strcpy(susan->name, "Susan");
  susan->age = 45;

  initializeList(&linkedList);

  addHead(&linkedList, samuel);
  addHead(&linkedList, sally);
  addTail(&linkedList, susan);

  printf("After add Samuel, Sally, and Susan:\n");
  displayLinkedList(&linkedList, (DISPLAY)displayEmployee);

  Node *node =
      getNode(&linkedList, (int (*)(void *, void *))compareEmployee, sally);
  delete (&linkedList, node);

  printf("After delete Sally:\n");
  displayLinkedList(&linkedList, (DISPLAY)displayEmployee);
}

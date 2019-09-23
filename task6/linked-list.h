/*
  linked-list.h
  Generic linked list type
*/

// Node
typedef struct _sNode
{
  // void pointer to data
  void *data;
  // node pointer
  struct _sNode* nextNode;
} _sNode;

typedef _sNode* sNode;

// Linked list
typedef struct _sLinkedList
{
  sNode first;
} _sLinkedList;

typedef _sLinkedList* sLinkedList;

// Creation linked list
sLinkedList InitLinkedList(void);
// Add new node to linked list
int push(sLinkedList, const void *data, int dataSize);
// Get last node from linked list
void* pop(sLinkedList);
// Delete linked list
void RemoveLinkedList(sLinkedList);
// Display data from linked list
void printDataFromList(sLinkedList, void (*fptr)(void *));

#include "linked-list.h"
#include <stdlib.h>

// Creation linked list
sLinkedList InitLinkedList(void)
{
  sLinkedList linkedList;

  if (((linkedList = (sLinkedList)malloc(sizeof(_sLinkedList))) == NULL))
    return NULL;

  linkedList->first = NULL;

  return linkedList;
}

// Add new node to linked list
int push(sLinkedList linkedList, const void* data, int dataSize)
{
  sNode node;
  sNode tmp;

  // Allocate memory for node
  if (((node = (sNode)malloc(sizeof(_sNode)))) == NULL)
    return -1;

  // Adding the first element
  if (linkedList->first == NULL)
  {
    linkedList->first = node;
    node->nextNode = NULL;
    node->data = malloc(sizeof(dataSize));
  }

  // Adding the rest elements
  else
  {
    tmp = linkedList->first;
    while(tmp->nextNode != NULL)
      tmp = tmp->nextNode;

    tmp->nextNode = node;
    node->nextNode = NULL;  
    node->data = malloc(sizeof(dataSize));
  }

  // Copy contents of data to newly allocated memory
  for (int i = 0; i < dataSize; i++)
  *(char*)(node->data + i) = *(char*)(data + i);

  return 0;
}

// Get a node from linked list
void* pop(sLinkedList linkedList)
{
  sNode tmp = NULL;

  if (linkedList->first != NULL)
  {
    tmp = linkedList->first;
    while(tmp->nextNode != NULL)
      tmp = tmp->nextNode;
  }

  return tmp;
}

// Delete a linked list
void RemoveLinkedList(sLinkedList linkedList)
{
  sNode tmp;

  if (linkedList->first != NULL)
  {
    tmp = linkedList->first;
    free(linkedList->first->data);
    free(linkedList->first);

    while (tmp->nextNode != NULL)
    {
      tmp = tmp->nextNode;
      free(tmp->data);
      free(tmp);
    }
  }

  free(linkedList);
}

// Print data from linked list
void printDataFromList(sLinkedList linkedList, void (*fptr)(void *))
{
  sNode tmp = NULL;

  tmp = linkedList->first;
  while (tmp->nextNode != NULL) 
  { 
      (*fptr)(tmp->data); 
       tmp = tmp->nextNode; 
  } 
}



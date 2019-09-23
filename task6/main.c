#include <stdio.h>
#include "linked-list.h"

/* Имеем чистый С. Напишите reusable API для работы со связным списком структур. Структуры могу быть разного типа, но в одном списке будут структуры одного типа.
 * Приведите пример использования вашего API.
*/

// Function to print an integer 
void printInt(void *n) 
{ 
   printf(" %d", *(int *)n); 
} 
  
// Function to print a float 
void printFloat(void *f) 
{ 
   printf(" %f", *(float *)f); 
}

int main(void) {
  
  sLinkedList integerLinkedList;
  sLinkedList floatLinkedList;

  integerLinkedList = InitLinkedList();

  // Create and print an int linked list 
  unsigned int_size = sizeof(int); 
  int arr[] = {10, 20, 30, 40, 50}, i; 
  for (i=4; i>=0; i--) 
    push(integerLinkedList, &arr[i], int_size); 
  printf("Created integer linked list is \n"); 
  printDataFromList(integerLinkedList, printInt);

  RemoveLinkedList(integerLinkedList);

  // Create and print a float linked list 
  floatLinkedList = InitLinkedList();
  unsigned float_size = sizeof(float); 
  float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5}; 
  for (i=4; i>=0; i--) 
    push(floatLinkedList, &arr2[i], float_size); 
  printf("\n\nCreated float linked list is \n"); 
  printDataFromList(floatLinkedList, printFloat); 

  RemoveLinkedList(floatLinkedList);

  return 0;
}

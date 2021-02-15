#include <stdio.h>

typedef struct Node
{
  // in the lab you will have a 
    // string -- don't forget to allocate that on the heap!
  int data;
  struct Node* next;
} Node;

typedef struct Queue
{
  Node* head;
  // This will keep the state of the queue too, updated through time
  // Make other data here for better runtime :)
} Queue;

void walk(Node* head)
{
  // is a little finicky in this editor, but good in practice
  // O(n) -- O(num_elements) since we're traversing each one
  Node* curr = head;
  while(curr->next != NULL) // just don't forget about the last element!
  {
    printf("Data: %d\n", curr->data);
    curr = curr->next;
  }
  printf("Data: %d\n", curr->data);
  
  // prints out 8,9,10,11
  // reverse would then print out 11,10,9,8
}

int main() {
  
  /*
  * This is a basic linked list to help visualize
  * Queue size is 3 in this example
  */
  
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  
  Node* element = (Node*)malloc(sizeof(Node));
  element->data = 8;
  queue->head = element;
  Node* element2 = (Node*)malloc(sizeof(Node));
  element2->data = 9;
  Node* element3 = (Node*)malloc(sizeof(Node));
  element3->data = 10;
  Node* element4 = (Node*)malloc(sizeof(Node));
  element4->data = 11;
  
  element->next = element2;
  //element->next->data = 9;
  element2->next = element3;
  element3->next = element4;
  
  // comment out to see freeing
  walk(queue->head); // show data of linked list
  
  // Note: I'm not freeing stuff here because I have access to all 
    // the pointers. To free the entire queue, you must
    // iterate through the entire thing!!
  
  free(element);
  free(element2);
  free(element3);
  free(element4);
  // Why am I freeing this last?? Think of how you use the head variable
  free(queue);
  
  return 0;
}
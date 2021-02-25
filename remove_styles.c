#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
  int value;
  struct ListNode* next;
} ListNode;

typedef struct Queue {
  struct ListNode* head;
} Queue;

void remove_list_entry(Queue* q, int val)
{
    ListNode* curr = q->head;
    ListNode* prev = NULL;
    
    if (curr == NULL)
      return;

    // Walk the list
    
    while (curr != NULL) {
      if (curr->value == val)
        break;
      prev = curr;
      curr = curr->next;
    }
    
    // check again to see if the b/c either the value isn't there,
      // or loop might not have been run
      
    if (curr->value == val)
    {
      // Remove the entry by updating the
      // head or the previous entry
  
      if (!prev)
          q->head = curr->next;
      else
          prev->next = curr->next;
          
      free(curr);
    }
}

/* The following 2 methods assume that the entry exists
    When actually coding, please put error checks */

void remove_list_entry_clean(Queue* q, ListNode* entry)
{
    // The "indirect" pointer points to the
    // *address* of the thing we'll update

    ListNode** indirect = &q->head;

    // Walk the list, looking for the thing that
    // points to the entry we want to remove

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;
        // like saying indirect = &((*indirect)->next)

    // .. and just remove it
    *indirect = entry->next;
    
    free(entry);
}

/*  
void remove_list_entry_clean(Queue* q, int val)
{
    // The "indirect" pointer points to the
    // *address* of the thing we'll update

    ListNode** indirect = &q->head;

    // Walk the list, looking for the thing that
    // points to the entry we want to remove

    while ((*indirect)->value != val)
        indirect = &(*indirect)->next;
        // like saying indirect = &((*indirect)->next)

    ListNode* eject = *indirect;
    // .. and just remove it
    *indirect = eject->next;
    
    free(eject);
}
*/

int main() {
  
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  
  ListNode* element = (ListNode*)malloc(sizeof(ListNode));
  element->value = 8;
  
  ListNode* element2 = (ListNode*)malloc(sizeof(ListNode));
  element2->value = 9;
  
  ListNode* element3 = (ListNode*)malloc(sizeof(ListNode));
  element3->value = 10;
  
  ListNode* element4 = (ListNode*)malloc(sizeof(ListNode));
  element4->value = 11;
  
  queue->head = element;
  element->next = element2;
  element2->next = element3;
  element3->next = element4;
  element4->next = NULL;
  
  //remove_list_entry(queue, 9);
  remove_list_entry_clean(queue, element3);
  //remove_list_entry_clean(queue, 10);
  
  // Note: I'm not freeing stuff here because I have access to all 
    // the pointers. To free the entire queue, you must
    // iterate through the entire thing!!
  
  free(element);
  free(element2);
  //free(element3);
  free(element4);
  free(queue);

  return 0;
}
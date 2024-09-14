#include "../../lib/SinglyLinkedList.h"

class Solution {
public:
  ListNode* partition(ListNode* head, int x)
  {
    ListNode* smaller = new ListNode();
    ListNode* smaller_head = smaller;
    ListNode* larger = new ListNode();
    ListNode* larger_head = larger;
    while (head) {
      if (head->val < x) {
        smaller->next = head;
        smaller = smaller->next;
      } else {
        larger->next = head;
        larger = larger->next;
      }
      head = head->next;
    }
    larger->next = nullptr;
    smaller->next = larger_head->next;
    head = smaller_head->next;
    delete larger_head;
    delete smaller_head;
    return head;
  }
};
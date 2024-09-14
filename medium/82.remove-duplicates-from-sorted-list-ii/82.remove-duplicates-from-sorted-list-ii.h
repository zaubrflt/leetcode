#include "../../lib/SinglyLinkedList.h"

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head)
  {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* pre = new ListNode(-1, head);
    head = pre;
    ListNode* first = head->next;
    ListNode* second = head->next->next;
    while (second) {
      if (first->val != second->val) {
        first = first->next;
        second = second->next;
        pre = pre->next;
      } else {
        do {
          ListNode* tmp = second;
          second = second->next;
          delete tmp;
        } while (second && first->val == second->val);
        pre->next = second;
        delete first;
        if (second) {
          first = second;
          second = second->next;
        }
      }
    }
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    return head;
  }
};
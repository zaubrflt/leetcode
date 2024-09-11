#include "../../lib/SinglyLinkedList.h"

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right)
  {
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* first = new_head;
    ListNode* cur = head;
    for (int i = 1; i < left; i++) {
      // 找到第left - 1那个结点
      first = first->next;
    }

    // 找到第left个结点
    cur = first->next;

    ListNode* pre = nullptr;
    while (cur && right - left + 1 > 0) {
      ListNode* tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
      first->next = pre;
      left++;
    }

    // 直接定位到新链表的尾部，将cur指向的剩余结点拼接到新链表的尾部
    while (first->next) {
      first = first->next;
    }
    first->next = cur;

    return new_head->next;
  }
};
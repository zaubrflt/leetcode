#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

#endif  // SINGLY_LINKED_LIST_H
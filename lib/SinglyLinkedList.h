#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif  // SINGLY_LINKED_LIST_H
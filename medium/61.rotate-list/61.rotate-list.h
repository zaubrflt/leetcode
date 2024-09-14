#include "../../lib/SinglyLinkedList.h"

#include <unordered_map>

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k)
  {
    if (k == 0 || head == nullptr || head->next == nullptr) return head;
    std::unordered_map<int, ListNode*> nodeMap;

    ListNode* tmp = head;
    int index = 1;
    while (tmp) {
      nodeMap[index] = tmp;
      index++;
      tmp = tmp->next;
    }
    k = k % nodeMap.size();
    if (k == 0) return head;
    int cur = nodeMap.size() - k + 1;
    int pre = cur - 1;
    ListNode* preNode = nodeMap[pre];
    ListNode* curNode = nodeMap[cur];
    ListNode* lastNode = nodeMap[nodeMap.size()];
    preNode->next = nullptr;
    lastNode->next = head;
    head = curNode;
    return head;
  }
};
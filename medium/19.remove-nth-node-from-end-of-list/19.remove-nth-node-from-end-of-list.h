#include "../../lib/SinglyLinkedList.h"
#include <vector>

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    std::vector<ListNode*> list;
    ListNode* tmp = head;
    while (tmp) {
      list.push_back(tmp);
      tmp = tmp->next;
    }
    int index = list.size() - n;
    if (index == 0) {
      // 如果要删除的结点是第一个
      tmp = head->next;
      delete head;
      return tmp;
    }

    tmp = list[index];
    list[index - 1]->next = tmp->next;
    delete tmp;
    return head;
  }
};

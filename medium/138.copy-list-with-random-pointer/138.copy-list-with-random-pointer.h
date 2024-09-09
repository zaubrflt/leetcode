#include <unordered_map>

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head)
  {
    std::unordered_map<Node*, Node*> nodeMap_;
    if (head == nullptr) return nullptr;

    Node* cur = head;
    while (cur) {
      nodeMap_[cur] = new Node(cur->val);
      cur = cur->next;
    }

    cur = head;
    while (cur) {
      nodeMap_[cur]->next = nodeMap_[cur->next];
      nodeMap_[cur]->random = nodeMap_[cur->random];
      cur = cur->next;
    }

    return nodeMap_[head];
  }
};
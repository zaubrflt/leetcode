/*
Merge two sorted linked lists and return it as a new sorted list.
The new list should be made by splicing together the nodes of
the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *rst = l3;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = (l1 == nullptr) ? l2 : l1;

        return rst->next;
    }
};
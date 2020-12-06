/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return 0;

		while (head->val == val) {
			head = head->next;
			if (head == nullptr) return 0;
		}

		ListNode* current = head->next;
		ListNode* prev = head;
		while (current != nullptr) {
			if (current->val == val) {
				prev->next = current->next;
			} else {
				prev = prev->next;
			}
			current = current->next;
		}
		return head;
    }
};
/*
Reverse a singly linked list.

Example:

Input:  1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively.
Could you implement both?

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* tmp = reverseList(head->next);
        tmp->next = head;
        head->next = nullptr;

        return tmp;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
		ListNode* cur = head;

		while (cur != nullptr) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
    }
};
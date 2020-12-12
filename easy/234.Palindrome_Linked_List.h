/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

*/

#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = vals.size() - 1; i < j; ++i, --j) {
            if (vals[i] != vals[j]) {
                return false;
            }
        }
        return true;
    }
};
// 1->3->2->1->2->3->1
// 1->3->2->1->1->3->2
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }  
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }
private:
    ListNode* endOfFirstHalf(ListNode* node) {
        ListNode* faster = node;
        ListNode* slower = node;

        while (faster->next != nullptr && faster->next->next != nullptr) {
            faster = faster->next->next;
            slower = slower->next;
        }
        return slower;
    }

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    int getLength(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        if (head == NULL) return head;

        int len = getLength(head);
        int l = k;
        int r = len - k + 1;

        if (l == r) return head;

        ListNode* left = head;
        for (int i = 0; i < l-1; i++) {
            left = left->next;
        }

        ListNode* right = head;
        for (int i = 0; i < r-1; i++) {
            right = right->next;
        }

        swap(left->val, right->val);

        return head;
    }
};
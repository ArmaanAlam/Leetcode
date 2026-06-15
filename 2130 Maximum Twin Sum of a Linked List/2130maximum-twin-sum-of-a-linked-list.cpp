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

    ListNode* reverse_list(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    int pairSum(ListNode* head) {

        int max_sum = 0;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp2 = reverse_list(slow->next);
        ListNode* temp1 = head;

        while(temp1 && temp2){
            int curr_sum = temp1->val + temp2->val;
            max_sum = max(max_sum, curr_sum);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return max_sum;
    }
};
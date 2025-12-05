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

    ListNode *reverse(ListNode *head, int k){

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *temp = NULL;

        int count = 0;

        while(count < k && curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;          
            count++;
        }

        if(temp != NULL){
            head->next = reverse(temp, 2);
        }


        return prev;
    }

public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL) return NULL;

        return reverse(head, 2);
    }
};
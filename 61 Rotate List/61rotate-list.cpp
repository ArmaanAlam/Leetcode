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

    int getLength(ListNode *head){
        ListNode *temp = head;
        int len = 0;

        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }


public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;

        int len = getLength(head);

        if(len == k) return head;

        k = k % len;
        if(k == 0) return head;

        int d = len - k - 1;

        
        ListNode *anstail = head;

        for(int i = 0; i < d; i++){
            anstail = anstail->next;
        }

        ListNode *anshead = anstail->next;
        anstail->next = NULL;

        ListNode *curr = anshead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;

        return anshead;
    }
};
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

    ListNode *reverse(ListNode *head){
        
        ListNode *curr = head;
        ListNode *prev = NULL;

        while(curr != NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *second = slow->next;
        slow->next = NULL;          
        second = reverse(second);


        


        ListNode *first = head;
        while (second != NULL) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        } 
    }
};
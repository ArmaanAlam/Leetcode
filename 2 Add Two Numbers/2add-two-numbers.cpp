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

        ListNode *prev = NULL;
        ListNode * curr = head;

        while(curr != NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head1 = l1;
        ListNode *head2 = l2;

        ListNode *anshead = NULL;
        ListNode *anstail = NULL;

        int carry = 0;

        while(head1 != NULL && head2 != NULL){
            int sum = carry + head1->val + head2->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);

            if(anshead == NULL){
                anshead = newNode;
                anstail = newNode;
            }
            else{
                anstail->next = newNode;
                anstail = newNode;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1 != NULL){
            int sum = carry + head1->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);

            anstail->next = newNode;
            anstail = newNode;

            head1 = head1->next;
        }

        while(head2 != NULL){
            int sum = carry + head2->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);

            anstail->next = newNode;
            anstail = newNode;

            head2 = head2->next;
        }

        while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);

            anstail->next = newNode;
            anstail = newNode;
        }

        return anshead;
    }
};
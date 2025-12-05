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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right) return head;

        if(left == 1){

            ListNode *rightnode = head;
            for(int i = 0; i < right-1; i++){
                rightnode = rightnode->next;
            }

            ListNode *afterright = rightnode->next;
            rightnode->next = NULL;

            ListNode *reverseNode = reverse(head);

            head->next = afterright;

            return reverseNode;   
        }

        ListNode *prevleft = head;
        for(int i = 0; i < left-2; i++){
            if(prevleft->next != NULL){
                prevleft = prevleft->next;
            }
        }
        ListNode *leftnode = prevleft->next;


        ListNode *rightnode = leftnode;
        for(int i = left; i < right; i++){
            if(rightnode->next != NULL){
                rightnode = rightnode->next;
            }
        }
        ListNode *afterright = rightnode->next;
        rightnode->next = NULL;


        ListNode *reverseNode = reverse(leftnode);

        prevleft->next = reverseNode;

        leftnode->next = afterright;

        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        
        int d = abs(len1 - len2);
        
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        if(len1 > len2){
            while(d--){
                temp1 = temp1->next;
            }
        }
        else{
            while(d--){
                temp2 = temp2->next;
            }
        }
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
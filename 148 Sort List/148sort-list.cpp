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
    ListNode* MergeSort(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *anshead = new ListNode(-1);
        ListNode *curr = anshead;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                curr->next = temp1;
                curr = temp1;
                temp1 = temp1->next;
            }
            else{
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL){
            curr->next = temp1;
            curr = temp1;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            curr->next = temp2;
            curr = temp2;
            temp2 = temp2->next;
        }
        return anshead->next;
    }

    ListNode *midnode(ListNode *head){
        ListNode *fast = head->next;
        ListNode *slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *mid = midnode(head);

        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode *sort = MergeSort(left, right);
        
        return sort;
    }
};
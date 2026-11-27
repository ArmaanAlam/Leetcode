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
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* head = list2;

        ListNode* tail = list2;
        while(tail->next){
            tail = tail->next;
        }

        ListNode* temp1 = list1;
        int position = 0;
        while(position < a-1){
            temp1 = temp1->next;
            position++;
        }

        position = 0;
        ListNode* temp2 = list1;
        while(position < b+1){
            temp2 = temp2->next;
            position++;
        }

        temp1->next = head;
        tail->next = temp2;

        return list1;
    }
};
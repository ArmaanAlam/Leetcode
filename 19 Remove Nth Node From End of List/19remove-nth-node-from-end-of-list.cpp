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

    void deleteNnode(ListNode *&head, int &n){

        if(head == NULL) return;

        deleteNnode(head->next, n);

        if(n == 1){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        n--;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        deleteNnode(head, n);
        return head;
    }
};
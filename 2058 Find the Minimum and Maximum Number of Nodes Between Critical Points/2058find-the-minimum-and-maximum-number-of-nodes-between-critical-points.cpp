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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};

        if(head == NULL || head->next == NULL || head->next->next == NULL) return ans;

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nex = head->next->next;

        int first = -1;
        int last = -1;

        int min_distance = INT_MAX;

        int i = 1;

        while(nex != NULL){

            bool CriticalPoint;

            if((curr->val > prev->val && curr->val > nex->val) || (curr->val < prev->val && curr->val < nex->val)){
                CriticalPoint = true;
            }
            else{
                CriticalPoint = false;
            }

            if(CriticalPoint && first == -1){
                first = i;
                last = i;
            }
            else if(CriticalPoint){
                min_distance = min(min_distance, i - last);
                last = i;
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nex = nex->next;
    }


    if (last == first){
        return ans;
    }
    else{
        ans[0] = min_distance;
        ans[1] = last - first;
    }

    return ans;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return NULL;

        Node *curr = head;
        while(curr != NULL){
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }


        curr = head;
        while(curr != NULL){
            Node *newNode = curr->next;
            if(curr->random != NULL){
                newNode->random = curr->random->next;
            }
            else{
                newNode->random = NULL;
            }
            curr = curr->next->next;
        }


        curr = head;
        Node *newhead = curr->next;
        while(curr != NULL){
            Node *newNode = curr->next;
            curr->next = curr->next->next;
            if(newNode->next != NULL){
                newNode->next = newNode->next->next;
            }
            curr = curr->next;
        }

        return newhead;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BST{
    public:

    stack<TreeNode*> st;
    bool reverse = true;

    BST(TreeNode* root, bool reverse){
        this->reverse = reverse;
        pushAll(root);
    }

    int element(){
        TreeNode *node = st.top();
        st.pop();

        if(reverse){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }
        return node->val;
    }


    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }

};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
        BST l(root, false);
        BST r(root, true);

        int i = l.element();
        int j = r.element();

        while(i < j){
            if(i + j == k) return true;
            else if(i + j > k) j = r.element();
            else i = l.element();
        }

        return false;
    }
};
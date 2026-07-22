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
class Solution {

    TreeNode *helper(TreeNode *node){
        if(node->left == NULL){
            return node->right;
        }
        else if(node->right == NULL){
            return node->left;
        }
        TreeNode *leftchild = node->left;
        TreeNode *rightleft = Find(node->right);
        rightleft->left = leftchild;
        return node->right;
    }

    TreeNode *Find(TreeNode *node){
        if(node->left == NULL){
            return node;
        }
        return Find(node->left);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) return NULL;

        if(root->val == key){
            return helper(root);
        }

        TreeNode *node = root;
        while(node){
            if(node->val > key){
                if(node->left && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->right && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
        }
        return root;
    }
};
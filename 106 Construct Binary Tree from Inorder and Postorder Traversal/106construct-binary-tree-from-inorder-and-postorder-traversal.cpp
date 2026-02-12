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

    int FindPosition(vector<int>& inorder, int element, int inStart, int inEnd){
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode *Build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){

        if(inStart > inEnd || postStart > postEnd) return NULL;

        int element = postorder[postEnd];
        TreeNode *node = new TreeNode(element);

        int pos = FindPosition(inorder, element, inStart, inEnd);
        int leftsize = pos - inStart;

        node->left = Build(inorder, postorder, inStart, pos - 1, postStart, postStart + leftsize - 1);
        node->right = Build(inorder, postorder, pos + 1, inEnd, postStart + leftsize, postEnd - 1);

        return node;
    }



public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inEnd = inorder.size()-1;
        int postEnd = postorder.size()-1;

        TreeNode *ans = Build(inorder, postorder, 0, inEnd, 0, postEnd);

        return ans;
    }
};
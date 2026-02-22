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
class Node{
    public:
    int sum, maxno, minno;
    bool isBST;
    Node(bool isBST, int sum, int minno, int maxno){
        this->isBST = isBST;
        this->sum = sum;
        this->maxno = maxno;
        this->minno = minno;
    }
};


class Solution {

    int ans = 0;

    Node solve(TreeNode *root){

        if(!root) return Node(true, 0, INT_MAX, INT_MIN);

        Node left = solve(root->left);
        Node right = solve(root->right);

        if(left.isBST && right.isBST && 
           root->val > left.maxno && root->val < right.minno){

            int currsum = root->val + left.sum + right.sum;
            ans = max(ans, currsum);

            return Node(true, currsum, min(root->val, left.minno), max(root->val, right.maxno));
        }

        return Node(false, 0, INT_MIN, INT_MAX);
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
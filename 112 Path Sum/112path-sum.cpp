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

    bool Path(TreeNode* root, int targetSum, int sum){

        if(root == NULL) return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool left = Path(root->left, targetSum, sum);
        bool right = Path(root->right, targetSum, sum);

        return (left || right);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum = 0;
        return Path(root, targetSum, sum);
    }
};
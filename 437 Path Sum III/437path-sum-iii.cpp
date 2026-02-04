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

    int Path(TreeNode* root, int target, long long sum){

        if(root == NULL) return 0;

        sum += root->val;

        int pathsum = 0;
        if(target == sum){
            pathsum += 1;
        }

        pathsum += Path(root->left, target, sum);
        pathsum += Path(root->right, target, sum);

        return pathsum;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return 0;

        int ans = 0;
        ans += Path(root, targetSum, 0);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};
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

    void path(TreeNode*root, string pathstring, vector<string>  &ans){
        if(root == NULL){
            return;
        }

        pathstring += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(pathstring);
            return;
        }

        pathstring += "->";

        path(root->left, pathstring, ans);
        path(root->right, pathstring, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string pathstring = "";
        path(root, pathstring, ans);
        return ans;
    }
};
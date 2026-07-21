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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode *node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            mp[x][y].push_back({node->val});

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto vertical : mp){
            vector<int> col;
            for(auto level : vertical.second){
                sort(level.second.begin(), level.second.end());
                for(int i : level.second){
                    col.push_back(i);
                }
            }
            ans.push_back(col);
        }


        return ans;
    }
};
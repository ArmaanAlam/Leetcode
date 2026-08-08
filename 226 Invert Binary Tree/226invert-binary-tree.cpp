class Solution {
    
    TreeNode* invert(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* leftnode = invert(root->right);
        TreeNode* rightnode = invert(root->left);

        root->left = leftnode;
        root->right = rightnode;

        return root;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
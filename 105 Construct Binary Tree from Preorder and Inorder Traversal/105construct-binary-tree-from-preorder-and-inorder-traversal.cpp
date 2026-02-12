class Solution {

    int FindPosition(vector<int>& inorder, int element, int inStart, int inEnd){
        for(int i = inStart; i <= inEnd; i++){
            if(element == inorder[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* Build(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd){

  
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        int element = preorder[preStart];
        TreeNode* node = new TreeNode(element);


        int position = FindPosition(inorder, element, inStart, inEnd);

  
        int leftSize = position - inStart;


        node->left = Build(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           position - 1);


        node->right = Build(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            position + 1,
                            inEnd);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        return Build(preorder, inorder,
                     0, n - 1,
                     0, n - 1);
    }
};

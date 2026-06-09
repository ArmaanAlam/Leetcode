class Solution {

    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int i = 0; i < row; i++){
            ans = ans * (row - i);
            ans = ans / (i + 1);
            ansrow.push_back(ans);
        }
        return ansrow;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
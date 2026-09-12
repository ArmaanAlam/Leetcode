class Solution {

    void solution(int k, int n, int index, vector<int>& path, vector<vector<int>>& ans) {

        if (n == 0 && k == 0) {
            ans.push_back(path);
            return;
        }

        if (k == 0 || n <= 0)
            return;

        for (int i = index; i <= 9; i++) {

            if (i > n)
                break;

            path.push_back(i);

            solution(k - 1, n - i, i + 1, path, ans);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> path;

        solution(k, n, 1, path, ans);

        return ans;
    }
};
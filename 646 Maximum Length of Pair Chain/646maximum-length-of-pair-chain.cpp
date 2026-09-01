class Solution {

    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);
        int last_element = pairs[0][1];
        int cnt = 1;

        for(int i = 1; i < n; i++){

            if(last_element < pairs[i][0]){
                cnt++;
                last_element = pairs[i][1];
            }
        }

        return cnt;
    }
};
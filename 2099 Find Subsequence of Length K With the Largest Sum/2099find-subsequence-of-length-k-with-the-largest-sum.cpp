class Solution {

    static bool comparator1(pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }

    static bool comparator2(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();
        vector<pair<int, int>> arr1;
        vector<pair<int, int>> arr2;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            arr1.push_back({nums[i], i});
        }
        sort(arr1.begin(), arr1.end(), comparator1);


        for(int i = 0; i < k; i++){
            arr2.push_back({arr1[i].first, arr1[i].second});
        }
        sort(arr2.begin(), arr2.end(), comparator2);

        for(auto it : arr2){
            ans.push_back(it.first);
        }

        return ans;
    }
};
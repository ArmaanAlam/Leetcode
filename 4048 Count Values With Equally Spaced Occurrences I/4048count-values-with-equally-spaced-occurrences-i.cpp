class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>>mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int cnt = 0;

        for (auto it : mp) {

            if (it.second.size() == 3) {

                int a = it.second[0];
                int b = it.second[1];
                int c = it.second[2];

                if (b - a == c - b) {
                    cnt++;
                }
            }
        }


        return cnt;

    }
};
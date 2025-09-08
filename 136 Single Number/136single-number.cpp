class Solution {
public:
    int singleNumber(vector<int>& nums) {

       map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for (auto pair : mp){
            if(pair.second == 1){
                return pair.first;
            }
        }
        return -1;
    }
};
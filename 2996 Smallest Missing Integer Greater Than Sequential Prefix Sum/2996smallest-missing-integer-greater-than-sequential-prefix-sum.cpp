class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end());
        int total = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] + 1 == nums[i]){
                total += nums[i];
            }
            else{
                break;
            }
        }

        while(st.find(total) != st.end()){
            total++;
        }

        return total;
    }
};
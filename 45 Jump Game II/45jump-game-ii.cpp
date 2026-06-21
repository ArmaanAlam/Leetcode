class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int left = 0;
        int right = 0;

        while(right < nums.size()-1){
            int distance = 0;
            for(int i = left; i <= right; i++){
                distance = max(distance, i + nums[i]);
            }
            left = right + 1;
            right = distance;
            jumps++;
        }

        return jumps;
    }
};
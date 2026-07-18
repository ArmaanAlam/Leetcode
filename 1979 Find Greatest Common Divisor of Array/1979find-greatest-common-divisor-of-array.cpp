class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int smallest = *min_element(nums.begin(), nums.end());
        int ans = 1;

        for(int i = smallest; i >= 1; i--) {
            if (largest % i == 0 && smallest % i == 0)
                return i;
        }
        return ans;
    }
};
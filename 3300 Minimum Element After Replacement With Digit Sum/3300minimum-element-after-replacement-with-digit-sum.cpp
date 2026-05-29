class Solution {
public:
    int minElement(vector<int>& nums) {
        
        vector<int> ans;

        for(int i : nums){
            int cnt = 0;
            while(i > 0){
                int digit = i % 10;
                cnt += digit;
                i /= 10;
            }
            ans.push_back(cnt);
        }

        int min_element = INT_MAX;
        for(int i : ans){
            if(i < min_element){
                min_element = i;
            }
        }

        return min_element;
    }
};
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int even = 0;

        for(auto num : nums){
            int length = 0;
            if(num == 0) length = 1;

            while(num > 0){
                num /= 10;
                length++;
            }

            if(! (length & 1)){
                even++;
            }
        }

        return even;
    }
};
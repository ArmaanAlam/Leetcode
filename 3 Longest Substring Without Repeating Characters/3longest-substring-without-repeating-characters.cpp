class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        vector<int> hash(256, -1);

        int left = 0;
        int right = 0;

        int len = 0;

        while(right < n){

            if(hash[s[right]] != -1){
                if(left <= hash[s[right]]){
                    left = hash[s[right]] + 1;

                }
            }
            len = max(len, right - left + 1);
            hash[s[right]] = right;
            right++;
        }
        return len;
    }
};
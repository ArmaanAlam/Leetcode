class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int>hash(26, 0);
        int freq = 0;
        int len = 0;
        int right = 0;
        int left = 0;

        while(right < s.size()){
            hash[s[right] - 'A']++;
            freq = max(freq, hash[s[right] - 'A']);

            if(((right - left + 1) - freq) > k){
                hash[s[left] - 'A']--;
                left++;
            }

            if(((right - left + 1) - freq) <= k){
                len = max(len, right - left + 1);
            }
            right++;
        }
        return len;
    }
};
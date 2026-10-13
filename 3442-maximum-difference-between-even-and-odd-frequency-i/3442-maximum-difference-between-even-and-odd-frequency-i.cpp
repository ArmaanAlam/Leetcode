class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        int odd = 0;
        int even = INT_MAX;

        for(auto [ch, freq] : mp){
            if(freq % 2){
                odd = max(odd, freq);
            }
            else{
                even = min(even, freq);
            }
        }

        return odd - even;
    }
};
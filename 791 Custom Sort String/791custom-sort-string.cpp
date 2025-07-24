class Solution {
public:
    string customSortString(string order, string s) {
        
        int hash[256] = {0};
        string ans = "";

        for(int i = 0; i < s.length(); i++){
            hash[s[i]]++;
        }

        for(int i = 0; i < order.length(); i++){

            while(hash[order[i]] > 0){
                ans += order[i];
                hash[order[i]]--;
            }
        }

        for (int i = 0; i < 256; i++) {
            while (hash[i] > 0) {
                ans += i;
                hash[i]--;
            }
        }

        return ans;
    }
};
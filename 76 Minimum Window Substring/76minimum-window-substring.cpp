class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        int minLen = INT_MAX;
        int cnt = 0;
        int index = -1;
        vector<int>hash(256, 0);

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }

        int left = 0;
        int right = 0;

        while(right < n){

            if(hash[s[right]] > 0){
                cnt++;
            }
            hash[s[right]]--;

            while(cnt == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    index = left;
                }

                hash[s[left]]++;
                if(hash[s[left]] > 0){
                    cnt--;
                }
                left++;
            }
            right++;
        }

        if(index == -1) return "";

        return s.substr(index, minLen);
    }
};
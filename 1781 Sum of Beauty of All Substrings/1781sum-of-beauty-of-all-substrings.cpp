class Solution {
public:

    int beauty(string &s){
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        int minfreq = INT_MAX;
        int maxfreq = INT_MIN;

        for(int fre : freq){
            if(fre > 0){
                maxfreq = max(maxfreq, fre);
                minfreq = min(minfreq, fre);
            }
        }

        return maxfreq - minfreq;
    }
    
    int beautySum(string s) {
        
        int cnt = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string str = s.substr(i, j-i+1);
                cnt += beauty(str);
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int total = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(mp[s[i]] < mp[s[i+1]]){
                int diff = abs(mp[s[i+1]] - mp[s[i]]);
                total += diff;
                i++; 
            }
            else{
                total += mp[s[i]];
            }
        }


        return total;
    }
};
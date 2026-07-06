class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if (s.size() < 10){
            return {};
        }
        
        unordered_map<string,int> mp;
        vector<string> ans;

        for(int i = 0; i <= s.size() - 10; i++) {

            string seq = s.substr(i, 10);

            mp[seq]++;

            if(mp[seq] == 2)
                ans.push_back(seq);
        }

        return ans;
    }
};
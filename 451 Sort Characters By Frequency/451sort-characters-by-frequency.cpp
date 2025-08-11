class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.length();

        vector<int> fre(256, 0);
        for (int i = 0; i < n; i++) {
            fre[s[i]]++;
        }

        vector<pair<int, char>> vec;
        for(int i = 0; i < 256; i++){
            if(fre[i] != 0){
                vec.push_back({fre[i], i});
            }
        }

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        int idx = 0;

        for(auto v : vec){
            int count = v.first;
            while(count--){
                s[idx] = v.second;
                idx++;
            }
        }

        return s;
    }
};
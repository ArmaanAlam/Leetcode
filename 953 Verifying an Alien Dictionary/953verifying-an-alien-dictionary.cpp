class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int hash[26] = {0};
        for(int i = 0; i < 26; i++){
            hash[order[i] - 'a'] = i;
        }

        for(int i = 0; i < words.size()-1; i++){

            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.length(), w2.length());
            int j = 0;

            while(j < len){
                if(w1[j] != w2[j]){
                    if(hash[w1[j] - 'a'] > hash[w2[j] - 'a']){
                        return false;
                    }
                    break;
                }
                j++;
            }

            if(j == len && w1.length() > w2.length()){
                return false;
            }
        }
        return true;
    }
};
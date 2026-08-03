class Solution {
public:
    bool isAnagram(string s, string t) {
        int charArr[256] = {0};

        for(char ch : s){
            charArr[ch - 'a']++;
        }

        for(char ch : t){
            charArr[ch - 'a']--;
        }

        for(int i = 0; i < 256; i++){
            if(charArr[i] != 0) return false;
        }

        return true;
    }
};
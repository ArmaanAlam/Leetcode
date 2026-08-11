class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26, 0);

        for(int i = 0; i < magazine.size(); i++){
            freq[magazine[i] - 'a']++;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            freq[ransomNote[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] < 0) return false;
        }

        return true;
    }
};
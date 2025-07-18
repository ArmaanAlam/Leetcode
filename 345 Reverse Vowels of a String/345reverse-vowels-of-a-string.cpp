class Solution {
    
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    string reverseVowels(string s) {
       int l = 0;
       int h = s.length()-1;

       while(l < h){
        if( ! isVowel(s[l])){
            l++;
        }
        else if(! isVowel(s[h])){
            h--;
        }
        else{
            swap(s[l], s[h]);
            l++;
            h--;
        }
       } 
       return s;
    }
};
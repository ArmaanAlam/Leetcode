class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> firstupper(26, -1);
        vector<int> lastlower(26, -1);

        int index = 0;

        for(char ch : word){
            
            if(islower(ch)){
                lastlower[ch - 'a'] = index;
            }
            else{
                if(firstupper[ch - 'A'] == -1){
                    firstupper[ch - 'A'] = index;
                }
            }
            index++;
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++){
            if(lastlower[i] != -1 && firstupper[i] != -1 &&
               lastlower[i] < firstupper[i]){
                cnt++;
            }
        }

        return cnt;
    }
};
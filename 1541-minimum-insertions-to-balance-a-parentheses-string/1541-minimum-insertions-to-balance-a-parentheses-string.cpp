class Solution {
public:
    int minInsertions(string s) {
        
        int need = 0;
        int insert = 0;

        for(char ch : s){
            if(ch == '('){
                if(need & 1){
                    insert++;
                    need--;
                }
                need += 2;
            }
            else{
                if(need == 0){
                    insert++;
                    need = 2;
                }
                need--;
            }
        }

        return need + insert;
    }
};
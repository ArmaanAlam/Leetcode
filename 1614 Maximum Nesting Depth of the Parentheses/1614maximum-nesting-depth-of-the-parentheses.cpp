class Solution {
public:
    int maxDepth(string s) {
        
        int max_count = 0;
        int currCount = 0;
        for(char ch : s){
            if(ch == '('){
                currCount++;
            }
            else if(ch == ')'){
                max_count = max(currCount, max_count);
                currCount--;
            }
            else{
                continue;
            }
        }

        return max_count;
    }
};
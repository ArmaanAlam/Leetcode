class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int index;

        int i = n-1;
        while(i >= 0){
            int no = num[i] - '0';
            if(no % 2 != 0){
                return num.substr(0, i + 1);
            }
            i--;
        }

        return "";
    }
};
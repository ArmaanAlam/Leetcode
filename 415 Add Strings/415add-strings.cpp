class Solution {

    void addstring(string& num1, string& num2, int i, int j, int carry, string& ans){

        if(i < 0 && j < 0){
            if( carry != 0){
                ans.push_back(carry + '0');
            }
            return ;
        }


        int n1 = (i >= 0  ? num1[i] : '0') - '0';
        int n2 = (j >= 0  ? num2[j] : '0') - '0';

        int sum = n1 + n2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        addstring(num1, num2, i-1, j-1, carry, ans);
        ans.push_back(digit + '0');

    }

public:
    string addStrings(string num1, string num2) {

        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        string ans = "";

        addstring(num1, num2, i, j, carry, ans);

        return ans;
    }
};
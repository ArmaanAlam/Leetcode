class Solution {

    void combination(vector<string>& mapping, int i, vector<string>& ans, string output, string digits){

        if(i >= digits.size()){
            ans.push_back(output);
            return;
        }


        int digit = digits[i] - '0';
        string value = mapping[digit];
        for(int j = 0; j < value.length(); j++){
            char ch = value[j];
            output.push_back(ch);
            combination(mapping, i + 1, ans, output, digits);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.length() == 0){
            return ans;
        }
        
        string output = "";

        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        combination(mapping, 0, ans, output, digits);

        return ans;
    }
};
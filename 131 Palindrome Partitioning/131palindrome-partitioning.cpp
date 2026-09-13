class Solution {

    bool isPalindrome(string str, int start, int end){
        while(start < end){
            if(str[start] != str[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void solution(string s, int index, vector<string> path, vector<vector<string>>& ans){

        if(index >= s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                string temp = s.substr(index, i - index + 1);
                path.push_back(temp);
                solution(s, i+1, path, ans);
                path.pop_back();
            }
        }

        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solution(s, 0, path, ans);
        return ans;
    }
};
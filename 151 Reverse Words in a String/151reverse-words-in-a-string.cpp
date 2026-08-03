class Solution {
public:
    string reverseWords(string s) {
        vector<string>st;
        int i = 0;
        while (i < s.size()) {
            string temp;

            while (i < s.size() && s[i] == ' ')
                i++;

            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            if (!temp.empty())
                st.push_back(temp);
        }

        string ans;
        int n = st.size();
        for(int i = n-1; i >= 0; i--){
            ans += st[i];
            if(i != 0){
                ans += ' ';
            }
        }

        return ans;
    }
};
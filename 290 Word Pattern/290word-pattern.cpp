class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> st;
        string temp;
        for (char ch : s) {
            if (ch == ' ') {
                st.push_back(temp);
                temp.clear();
            } else {
                temp += ch;
            }
        }
        st.push_back(temp);

        if(st.size() != pattern.size()) return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;


        for(int i = 0; i < pattern.size(); i++){

            if(mp1.find(pattern[i]) != mp1.end()){
                if(mp1[pattern[i]] != st[i]){
                    return false;
                }
            }
            else{
                mp1[pattern[i]] = st[i];
            }

            if(mp2.find(st[i]) != mp2.end()){
                if(mp2[st[i]] != pattern[i]){
                    return false;
                }
            }
            else{
                mp2[st[i]] = pattern[i];
            }
        }


        return true;

    }
};
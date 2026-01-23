class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();

        string ans;

        stack<char> st;


        for(int i = 0; i < n; i++){

            char ch = num[i];

            while(!st.empty() && k > 0 && st.top() > ch){
                st.pop();
                k--;
            }
            if(!st.empty() || ch != '0'){
                st.push(ch);
            }
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
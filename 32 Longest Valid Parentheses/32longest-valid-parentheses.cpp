class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        st.push(-1);

        int len = 0;
        int i = 0;

        for(char ch : s){

            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    len = max(len, i - st.top());
                }
            }
            i++;
        }
        return len;
    }
};
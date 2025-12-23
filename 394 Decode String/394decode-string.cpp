class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;

        for(char ch : s){

            if(ch == ']'){

                string temp = "";

                while(!st.empty() && st.top() != "["){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();

                string digit = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    digit = st.top() + digit;
                    st.pop();
                }

                int times = stoi(digit);

                string repeat = "";

                while(times--){
                    repeat += temp;
                }
                st.push(repeat);
            }
            else{
                st.push(string(1, ch));
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
class Solution {

    int operation(int a, int b, string op) {
        if(op == "+"){
            return a + b;
        }
        else if(op == "-"){
            return a - b;
        }
        else if(op == "*"){
            return a * b;
        }
        else {
            return a / b;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(string str : tokens){

            if(str == "+" || str == "-" || str == "/" || str == "*"){

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int ans = operation(b, a, str);
                st.push(ans);
            }
            else{
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};
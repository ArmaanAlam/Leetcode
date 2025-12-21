class Solution {

    string ReverseString(stack<string> &st) {
        if (st.empty()) return "";

        string top_str = st.top();
        st.pop();

        string ans = ReverseString(st) + top_str;
        return ans;
    }


public:
    string simplifyPath(string path) {
        
        stack<string> st;

        int i = 0;
        while(i < path.size()){
            int start = i;
            int end = i+1;

            while(end < path.size() && path[end] != '/'){
                end++;
            }
            string loc = path.substr(start, end - start);
            i = end;

            if(loc == "/" || loc == "/."){
                continue;
            }

            if(loc != "/.."){
                st.push(loc);
            }
            else if(!st.empty()){
                st.pop();
            }
        }

        
        if(st.empty()){
            return "/";
        }

        return ReverseString(st);
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int max_area = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1  : st.top();

                int area = element * (nse - pse - 1);
                max_area = max(max_area, area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int area = element * (nse - pse - 1);
            max_area = max(max_area, area); 
        }

        return max_area;
    }
};
class Solution {

    int largestRectangleArea(vector<int> height, int n){

        stack<int>st;
        int max_area = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int element = height[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? - 1 : st.top();

                int area = element * (nse - pse - 1);
                max_area = max(area, max_area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = height[st.top()];
            st.pop();

            int nse = n;
            int pse = st.empty() ? - 1 : st.top();

            int area = element * (nse - pse - 1);
            max_area = max(area, max_area);
        }

        return max_area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int max_area = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height, m);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
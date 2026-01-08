class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();
        vector<double> answer(n, -1);

        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            while(!st.empty()){
                double col_time = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

                if(answer[st.top()] == -1 || col_time < answer[st.top()]){
                    answer[i] = col_time;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
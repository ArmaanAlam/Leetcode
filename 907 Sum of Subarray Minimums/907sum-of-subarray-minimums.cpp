class Solution {

    vector<int> PreviousSmaller(vector<int> &arr, int &n){

        vector<int> ans(n);
        stack<int>st;

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }


    vector<int> NextSmaller(vector<int> &arr, int &n){

        vector<int> ans(n);
        stack<int>st;

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }


public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        
        vector<int> prev = PreviousSmaller(arr, n);
        vector<int> next = NextSmaller(arr, n);

        int sum = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int left = i - prev[i];
            int right = next[i] - i;

            long long freq = left * right * 1LL;
            int value = (freq * arr[i] * 1LL) % mod;

            sum = (sum + value) % mod; 
        }

        return sum;
    }
};
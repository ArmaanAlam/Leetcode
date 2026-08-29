class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;

        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                pge[i] = -1;
            } else {
                pge[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = n;
            } else {
                nge[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        long long sumMax = 0;
        long long sumMin = 0;

        for (int i = 0; i < n; i++) {

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            sumMax += (long long)nums[i] * leftMax * rightMax;

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            sumMin += (long long)nums[i] * leftMin * rightMin;
        }

        return sumMax - sumMin;
    }
};
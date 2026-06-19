class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n = gain.size();
        int max_height = 0;
        int current_gain = 0;

        for (int i = 0; i < n; i++) {
            current_gain += gain[i];
            max_height = max(max_height, current_gain);
        }
        return max_height;
    }
};
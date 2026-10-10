
class Solution {
    static bool comp(const pair<int, int>& a,
                     const pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for (int x : arr) {
            mp[x]++;
        }

        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), comp);

        int removed = 0;
        int count = 0;

        for (const auto& it : freq) {
            removed += it.second;
            count++;

            if (removed >= n / 2) {
                return count;
            }
        }

        return count;
    }
};

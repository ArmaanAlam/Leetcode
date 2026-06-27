class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> hash;
        int ans = 1;

        for (int x : nums) {
            hash[x]++;
        }

       
        if (hash.count(1)) {
            int cnt = hash[1];

            if (cnt % 2 == 0)
                ans = max(ans, cnt - 1);
            else
                ans = max(ans, cnt);
        }

        for (auto it : hash) {

            long long val = it.first;

            if (val == 1)
                continue;

            int len = 0;

            while (hash.count(val)) {

                if (hash[val] >= 2) {
                    len += 2;
                } else {
                    len += 1;
                    break;
                }

                val = val * val;
            }

           
            if (!hash.count(val))
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
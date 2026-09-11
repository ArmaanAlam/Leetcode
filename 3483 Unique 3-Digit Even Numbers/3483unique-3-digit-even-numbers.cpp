class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        int cnt = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[digits[i]]++;
        }

        for(int num = 100; num <= 999; num++){

            if(num % 2 != 0) continue;

            int hun = num / 100;
            int ten = (num / 10) % 10;
            int unit = num % 10;

            mp[hun]--;
            mp[ten]--;
            mp[unit]--;

            if (mp[hun] >= 0 && mp[ten] >= 0 && mp[unit] >= 0) {
                cnt++;
            }

            mp[hun]++;
            mp[ten]++;
            mp[unit]++;
        }

        return cnt;
    }
};
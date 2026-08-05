class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        int i = 0;
        string ans = "";
            while (num > 0 && i < 13) {
            if (num >= mp[i].first) {
                ans += mp[i].second;
                num -= mp[i].first;
            } else {
                i++;
            }
        }

        return ans;
    }
};
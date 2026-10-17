class Solution {

    static bool comp(const pair<int, pair<int, int>>& a,
                 const pair<int, pair<int, int>>& b) {
    if (a.second.first != b.second.first) {
        return a.second.first < b.second.first;
    }
    return a.second.second < b.second.second;
}

public:
    int minSwaps(vector<int>& nums) {
        
        vector<pair<int, pair<int, int>>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int digit = nums[i];
            int sum = 0;
            while(digit > 0){
                sum += digit % 10;
                digit /= 10;
            }
            mp.push_back({i, {sum, nums[i]}});
        }

        sort(mp.begin(), mp.end(), comp);

        int swap = 0;
        vector<bool> visit(n, false);

        for(int i = 0; i < n; i++){
            if(visit[i] || mp[i].first == i){
                continue;
            }

            int j = mp[i].first;
            int cycle = 0;

            while(!visit[j]){
                visit[j] = true;
                j = mp[j].first;
                cycle++; 
            }

            swap += cycle - 1;
        }


        return swap;
    }
};
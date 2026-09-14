class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();
        int m = img2.size();
        
        vector<pair<int, int>> matA;
        vector<pair<int, int>> matB;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(img1[i][j]){
                    matA.push_back({i, j});
                }
                if(img2[i][j]){
                    matB.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, int> mp;
        int ans = 0;

        for(auto it1 : matA){
            for(auto it2 : matB){
               int dx = it2.first - it1.first;
               int dy = it2.second - it1.second;

               mp[{dx, dy}]++;
               
               ans = max(ans, mp[{dx, dy}]);

            }
        }

        return ans;
    }
};
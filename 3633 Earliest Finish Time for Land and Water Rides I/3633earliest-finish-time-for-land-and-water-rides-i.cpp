class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans1 = INT_MAX; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int landFinish = landStartTime[i] + landDuration[i];

                int finish =
                    max(landFinish, waterStartTime[j])
                    + waterDuration[j];

                ans1 = min(ans1, finish);
            }
        }

        int ans2 = INT_MAX; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int waterFinish = waterStartTime[j] + waterDuration[j];

                int finish =
                    max(waterFinish, landStartTime[i])
                    + landDuration[i];

                ans2 = min(ans2, finish);
            }
        }

        return min(ans1, ans2);
    }
};
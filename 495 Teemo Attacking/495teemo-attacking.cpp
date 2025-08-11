class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int totaltime = 0;

        for(int i = 0; i < timeSeries.size()-1; i++){
            int interval = timeSeries[i+1] - timeSeries[i];
            totaltime += min(duration, interval);
        }
       
        totaltime += duration;
        
        return totaltime;
    }
};
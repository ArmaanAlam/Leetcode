class Solution {

    long long calculateTime(vector<int>& piles, int one_time){

        long long total_time = 0;

        for(int pile : piles){
            total_time += (pile + one_time - 1)/one_time;
        }
        return total_time;
    }

    int binarySearch(vector<int>& piles, int high, int h){
        int left = 1;
        int right = high;
        int ans = high;

        while(left <= right){
            int mid = left + (right - left)/2;

            long long time = calculateTime(piles, mid);

            if(time <= h){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max_time = *max_element(piles.begin(), piles.end());

        return binarySearch(piles, max_time, h);
    }
};
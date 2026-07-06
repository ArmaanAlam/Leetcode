class Solution {

    bool possible(vector<int>& bloomDay, int m, int k, int days){

        int cnt = 0;
        int ans = 0;

        for(int bloom : bloomDay){
            if(days >= bloom){
                cnt++;
            }
            else{
                ans += cnt/k;
                cnt = 0;
            }
        }
        ans += cnt / k;

        if(ans >= m) return true;

        return false;
    }


    int BinarySearch(vector<int>& bloomDay, int start, int end, int m, int k){
        int left = start;
        int right = end;
        int ans = end;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(possible(bloomDay, m, k, mid)){
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
    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long)m *k > bloomDay.size()) return -1;
        
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int min_day = BinarySearch(bloomDay, start, end, m, k);
        
        return min_day;
    }
};
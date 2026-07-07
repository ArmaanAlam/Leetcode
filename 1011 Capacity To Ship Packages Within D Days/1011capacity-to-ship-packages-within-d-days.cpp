class Solution {

    int Possible(vector<int>& weights, int capacity){

        int currweight = 0;
        int cnt = 1;
        for(int weight : weights){
            currweight += weight;

            if(currweight > capacity){
                cnt++;
                currweight = weight;
            }
        }

        return cnt;
    }


    int BinarySearch(vector<int>& weights, int days, int start, int end){
        int ans = end;
        int left = start;
        int right = end;

        while(left <= right){
            int mid = left + (right - left)/2;
            int min_weight = Possible(weights, mid);

            if(min_weight <= days){
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
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for(int weight : weights){
            end += weight;
        }

        int min_weight = BinarySearch(weights, days, start, end);

        return min_weight;
    }
};
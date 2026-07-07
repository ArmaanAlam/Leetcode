class Solution {

    int divisor(vector<int>&nums, int no){

        int total = 0;
        for(int num : nums){
            total += (num + no - 1)/no;
        }
        return total;
    }

    int BinarySearch(vector<int>& nums, int threshold, int start, int end){
        int left = start;
        int right = end;
        int ans = end;

        while(left <= right){
            int mid = left + (right - left)/2;
            int total = divisor(nums, mid);
            if(total <= threshold){
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        int ans = BinarySearch(nums, threshold, start, end); 
        return ans;
    }
};
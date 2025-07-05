class Solution {

    int firstOccurence(vector<int> &arr, int target){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        int mid = start + (end - start)/2;

        while(start <= end){

            if(arr[mid] == target){
                 ans = mid;
                 end = mid - 1;
            }
            else if(arr[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

            mid = start + (end - start)/2;
        }
        return ans;
    }

    int lastOccurence(vector<int> &arr, int target){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        int mid = start + (end - start)/2;

        while(start <= end){

            if(arr[mid] == target){
                 ans = mid;
                 start = mid + 1;
            }
            else if(arr[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

            mid = start + (end - start)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;

        int first = firstOccurence(nums, target);
        int last = lastOccurence(nums, target);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};
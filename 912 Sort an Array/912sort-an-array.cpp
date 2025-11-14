class Solution {

    void merge(vector<int> &arr, int start, int end){

        int total_len = end - start + 1;

        int gap = (total_len / 2) + (total_len % 2);
        
        while(gap > 0){

            int i = start;
            int j = i + gap;

            while(j <= end){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
                i++;
                j++;
            }

            if(gap <= 1){
                gap = 0;
            }
            else{
                gap = (gap / 2) + (gap % 2);
            }
        }
    }

    void mergesort(vector<int> &arr, int start, int end){

        if(start >= end) return;

        int mid = (start + end) / 2;

        mergesort(arr, start, mid); 
        mergesort(arr, mid + 1, end);
        merge(arr, start, end); 
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        mergesort(nums, start, end);
        return nums;
    }
};
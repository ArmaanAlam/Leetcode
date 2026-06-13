class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> nums3(n+m);
        int i = 0;
        int j = 0;
        int index = 0;

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                nums3[index] = nums1[i];
                i++;
            }
            else{
                nums3[index] = nums2[j];
                j++;
            }
            index++;
        }

        while(i < m){
            nums3[index] = nums1[i];
            i++;
            index++;
        }
        while(j < n){
            nums3[index] = nums2[j];
            j++;
            index++;
        }
        
        for(int i = 0; i < m + n; i++){
            nums1[i] = nums3[i];
        }
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int index = 0;

        vector<int> nums3(n+m);

        while(i < n && j < m){
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

        while(i < n){
            nums3[index] = nums1[i];
            i++;
            index++;
        }

        while(j < m){
            nums3[index] = nums2[j];
            j++;
            index++;
        }

        int total = n + m;
        int mid = total / 2;

        if (total % 2 == 0)
            return (nums3[mid] + nums3[mid - 1]) / 2.0;

        return nums3[mid];
    }
};
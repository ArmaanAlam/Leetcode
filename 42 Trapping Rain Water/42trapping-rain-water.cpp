class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int maxLeft = 0;
        int maxRight = 0;
        int total = 0;
        int left = 0;
        int right = n-1;

        while(left < right){
            if(height[left] <= height[right]){
                if(maxLeft > height[left]){
                    total += maxLeft - height[left];
                }
                else{
                    maxLeft = height[left];
                }
                left++;
            }
            else{
                if(height[left] > height[right]){
                    if(maxRight > height[right]){
                        total += maxRight - height[right];
                    }
                    else{
                        maxRight = height[right];
                    }
                    right--;
                }
            }
        }
        return total;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int leftsum = 0;
        int rightsum = 0;
        int max_sum = 0;

        for(int i = 0; i < k; i++){
            leftsum += cardPoints[i];
        }
        max_sum = leftsum;

        int rightindex = n-1;
        for(int i = k-1; i >= 0; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightindex];
            rightindex--;

            max_sum = max(max_sum, leftsum + rightsum);
        }

        return max_sum;
    }
};
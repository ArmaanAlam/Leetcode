class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int up = 0, down = 0, peak = 0;
        int sum = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                sum += up + 1;
            }
            else if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                sum += 1;
            }
            else {
                up = 0;
                down++;
                sum += down + 1;
                if (down <= peak)
                    sum--;
            }
        }

        return sum;
    }
};
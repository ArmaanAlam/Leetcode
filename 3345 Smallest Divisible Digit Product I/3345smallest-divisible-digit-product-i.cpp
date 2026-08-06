class Solution {
public:
    int smallestNumber(int n, int t) {

        int no = n;

        while (true) {

            int tempNo = no;
            int product = 1;

            while (tempNo > 0) {
                product *= (tempNo % 10);
                tempNo /= 10;
            }

            if (product % t == 0)
                return no;

            no++;
        }

        return -1;
    }
};
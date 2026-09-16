class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;
        
        int temp = n;
        string bits;

        while(temp > 0){
            if(temp % 2){
                bits += '1';
            }
            else{
                bits += '0';
            }
            temp /= 2;
        }

        reverse(bits.begin(), bits.end());

        string bits1;
        for(char ch : bits){
            if(ch == '1'){
                bits1.push_back('0');
            }
            else{
                bits1.push_back('1');
            }
        }


        int num = 0;
        int power = 1;

        for(int i = bits1.size() - 1; i >= 0; i--){

            if(bits1[i] == '1')
                num += power;

            power *= 2;
        }


        return num;
    }
};
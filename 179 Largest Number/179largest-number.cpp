class Solution {

    static bool comparator(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1 > t2;
    }
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> num;

        for(auto i : nums){
            num.push_back(to_string(i));
        } 

        sort(num.begin(), num.end(), comparator);     

        if(num[0] == "0") return "0";

        string ans;

        for(auto s : num){
            ans += s;
        }

        return ans;   
    }
};
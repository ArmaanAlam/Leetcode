class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int left = 0;
        int right = 0;
        int len = 0;

        while(right < fruits.size()){
            hash[fruits[right]]++;

            if(hash.size() > 2){
                hash[fruits[left]]--;
                if(hash[fruits[left]] == 0){
                    hash.erase(fruits[left]);
                }
                left++;
            }

            if(hash.size() <= 2){
                len = max(len, right - left + 1);
            }

            right++;
        }

        return len;
    }
};
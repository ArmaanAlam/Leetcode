class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> people;

        for(int i = 1; i <= n; i++) {
            people.push_back(i);
        }

        int index = 0;

        while(people.size() > 1) {

            index = (index + k - 1) % people.size();

            people.erase(people.begin() + index);
        }

        return people[0];
    }
};
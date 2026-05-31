class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        long long planet_mass = mass;

        sort(asteroids.begin(), asteroids.end());

        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] <= planet_mass){
                planet_mass += asteroids[i];
            }
            else{
                return false;
            }
        }

        return true;
    }
};
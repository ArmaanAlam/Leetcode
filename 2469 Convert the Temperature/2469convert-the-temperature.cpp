class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k = celsius + 273.15;
        double f = celsius * 1.8 + 32;
        vector<double> v;
        v.push_back(k);  
        v.push_back(f);
        return v;
    }
};
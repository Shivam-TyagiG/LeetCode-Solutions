class Solution {
public:
    double average(vector<int>& salary) {
        double sum =0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int count=-2;
        for(auto num : salary)
        {
            count++;
            sum = sum+num;
            mini=min(mini,num);
            maxi = max(maxi,num);
        }
        sum = (sum-mini-maxi)/count;
        return sum; 
    }
};
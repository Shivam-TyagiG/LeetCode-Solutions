class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        map<int,int> m;
        int count = 0;
        int sum = 0;
        m[sum]++;
        //m.insert({0,-1});
        for(int i=0; i<arr.size(); i++) {
            sum =sum+arr[i];
            if(m.find(sum-k)!=m.end())
            {
                count = count+m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};
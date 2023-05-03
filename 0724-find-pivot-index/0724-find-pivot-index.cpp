class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total  =  0;
        for(auto num : nums)
        {
            total =  total + num;
        }
        int curr=0,count =0;
        for(auto num : nums)
        {
            if(curr*2 == total-num){
                return count;
            }
            count++;
            curr = curr+num;
        }
        return -1;
    }
};
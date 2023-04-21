class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        long long prod=1;
        int count = 0;
        int i=0, j=0;
        while(j<nums.size()){
            prod=prod*nums[j];
            if(prod<k){
                count+=(j-i+1);
                // cout<<i<<" "<<j<<endl;
                j++;
            }
            else{
                // cout<<prod<<" prod"<<" "<<nums[i]<<endl;
                while(prod>=k){
                    // cout<<prod<<" Prod"<<endl;
                    prod = prod/nums[i];
                    i++;
                }
                if(i>j){
                    j=i;
                    prod=1;
                }
                else{
                    prod=prod/nums[j];
                }
            }
            
        }
        return count;
    }
};
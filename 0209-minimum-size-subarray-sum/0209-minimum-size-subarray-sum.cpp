class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int ans = INT_MAX;
        int i=0, j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                    ans=min(ans, j-i+1);
                    cout<<i<<" "<<j<<" Sum == "<<sum;
                    sum=sum-nums[i];
                    cout<<"  Decrement sum "<<sum<<endl;
                    i++;
                    
                }
                if(i>j) j=i;
                else sum-=nums[j];
            }
            else{
                
                j++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
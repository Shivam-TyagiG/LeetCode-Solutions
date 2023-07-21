class Solution {
public:
    vector<int> dp; //dp[i]=length of the LIS ending at index i
    vector<int> count;// # of LIS with length=dp[i]

    void LIS(int i, vector<int>& nums){
        if (i==0){
            dp[0]=1;
            count[0]=1;
            return ;
        }
        if (count[i]!=-1) return;
        dp[i]=1;
        count[i]=1;
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j]){
                LIS(j, nums);
                if (dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if (dp[i]==dp[j]+1){
                    count[i]+=count[j];   
                }    
            }      
        }
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        count.assign(n, -1);
        for(int i=0; i<n; i++)
            LIS(i, nums);
        int M=*max_element(dp.begin(), dp.end());
    //    cout<<M<<endl;
        int ans=0;
        for (int i=0; i<n; i++){
    //        cout<<dp[i]<<",";
            if (M==dp[i])
                ans+=count[i];
        }   
    //    cout<<"\n---\nans="<<ans<<endl;
        return ans;
    }
};
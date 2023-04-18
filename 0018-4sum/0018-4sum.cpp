class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int a=j+1, b=n-1;
                long long res = long(target-1*long(nums[i]+nums[j]));
                while(a<b){
                    long long sum = nums[a]+nums[b];
                    if(sum>res) b--;
                    else if(sum<res) a++;
                    else{
                        vector<int> ouput;
                        ouput.push_back(nums[i]);
                        ouput.push_back(nums[j]);
                        ouput.push_back(nums[a]);
                        ouput.push_back(nums[b]);
                        ans.push_back(ouput);
                        if(nums[a]==nums[b]) break;
                        else{
                            int p=nums[a], q=nums[b];
                            while(nums[a]==p) a++;
                            while(nums[b]==q) b--;
                        }
                        
                    }
                }
            }
        }
        return ans;
    }
};
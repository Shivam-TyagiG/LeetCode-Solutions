class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int s = nums.size();
        vector<int> ans;
        map<int,int> present;
        for(int i=0 ; i<s ; i++)
        {
            present[i+1]= 0;
        }
        for(int i=0 ; i<s ; i++)
        {
            present[nums[i]]++;
        }
        int a = 0;
        int b = 0;
        
        for(int i=0 ; i<s ; i++)
        {
           if(present[i+1] == 0)
           {
               a=i+1;
           }
            if(present[i+1] == 2)
            {
                b = i+1;
            }
        }
        
        
        ans.push_back(b);
        ans.push_back(a);
        
        return ans;
    }
};
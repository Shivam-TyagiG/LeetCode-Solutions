class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Firts way to solve the solution 
        /*int count=0;
        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]==nums[i+1]){
                count++;
                nums[i]=101;
            }
            
            
        }
        sort(nums.begin(),nums.end());
        int l=nums.size()-count;
        return l;
        */
        
        
        
        //2nd way to solve the solution faster than 100%
        int t = nums[0];
        int c = 1;
        
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]>t)
            {
                t = nums[i];
                nums[c] = t;
                c++;
            }
        }
        
        return c;
    }
};
int firstposition(vector<int> nums,int target ,int s , int e)
{
    int ans=-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            ans=mid;
            e=mid-1;
        }
        else if(nums[mid]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int lastposition(vector<int> nums,int target ,int s , int e)
{
    int ans=-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            ans=mid;
            s=mid+1;
        }
        else if(nums[mid]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s=0, e = nums.size() -1;
        int a = firstposition(nums,target,s,e);
        int b = lastposition(nums,target,s,e);
        
        vector<int> ans(2);
        ans[0]=a;
        ans[1]=b;
        return ans;
    }
};
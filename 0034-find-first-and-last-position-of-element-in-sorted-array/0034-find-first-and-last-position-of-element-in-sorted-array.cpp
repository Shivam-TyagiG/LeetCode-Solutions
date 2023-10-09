class Solution {
public:
    int solveleft(vector<int> arr, int target, int s, int e){
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                e=mid-1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{

                s=mid+1;
            }
        }
        return ans;
    }

    int solver(vector<int> arr, int target, int s, int e){
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                s=mid+1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{

                s=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int a = solveleft(nums, target, s, e);
        int b = solver(nums, target, s, e);
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};
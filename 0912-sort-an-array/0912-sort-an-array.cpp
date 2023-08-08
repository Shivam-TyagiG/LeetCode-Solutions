class Solution {
private:
    vector<int> temp;
    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low, j = mid+1;
        temp.clear();
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        
        for(i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }
    void divide(vector<int>& nums, int low, int high){
        if(low>=high) return ;
        int mid = low+(high-low)/2;
        divide(nums, low, mid);
        divide(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int k=nums.size()-1;
        divide(nums, 0, k);
        return nums;
    }
};
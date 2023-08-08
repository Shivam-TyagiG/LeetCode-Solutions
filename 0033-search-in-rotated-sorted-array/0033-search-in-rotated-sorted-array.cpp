class Solution {
 int solve(vector<int> &arr)
    {
        int low = 0;
        int n = arr.size()-1;
        int high = n;
        int mid;
        while(low<high)
        {
            mid = low+(high-low)/2;
            if(arr[mid] < arr[n])
            {
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
public:
    int search(vector<int>& arr, int target) {
        int pivot = solve(arr);
    int n = arr.size() - 1;
    int low, high;
    if (target <= arr[n]){
        low = pivot;
        high = n;
    }
    else{
        low = 0;
        high = pivot-1;
    }
    cout<<pivot<<endl;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
    }
};
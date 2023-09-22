class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int n = arr.size();
        int high = arr.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid]>=arr[0]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(low == n-1 && arr[low]>arr[0]) return arr[0];
        return arr[low];
    }
};
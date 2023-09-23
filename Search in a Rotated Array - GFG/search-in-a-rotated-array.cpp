//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int find_pivot(int arr[], int l, int h){
        int low = l, high = h;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid]>=arr[0]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    
    int find(int arr[], int l, int h, int key){
        int low = l, high = h;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid]<key){
                low = mid+1;
            }
            else high = mid-1;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
        int pivot = find_pivot(A, l, h);
        if(A[0] == key) return 0;
        else if(key<A[0]){
            // cout<<"lest than"<<endl;
            // cout<<pivot<<endl;
            return find(A, pivot, h, key);
        }else{
            // cout<<"more than"<<endl;
            // cout<<pivot<<endl;
            return find(A, 0, pivot-1, key);
        }
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
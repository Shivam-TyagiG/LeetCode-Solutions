//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long findfirst(vector<long long> arr, long long x){
        long low = 0 , high = arr.size()-1;
        long pos = -1;
        while(low<=high){
            long mid = low+(high-low)/2;
            if(arr[mid]==x){
                pos = mid;
                high = mid-1;
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return pos;
    }
    long findlast(vector<long long> arr, long long x){
        long low = 0 , high = arr.size()-1;
        long pos = -1;
        while(low<=high){
            long mid = low+(high-low)/2;
            if(arr[mid]==x){
                pos = mid;
                low = mid+1;
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return pos;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        return {findfirst(v,x), findlast(v,x)};
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
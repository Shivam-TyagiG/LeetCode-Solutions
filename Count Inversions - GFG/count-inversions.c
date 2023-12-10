//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int ans = 0;
void mergeii(long long arr[], long long int s, long long int mid, long long int end){
    long long int i = s, j = mid+1;
    long long int* a = (long long int*)malloc((end - s + 3) * sizeof(long long int));
    int k = 0;
    while(i<=mid && j<=end){
        if(arr[i] > arr[j]){
            ans += mid-i+1;
            a[k++] = arr[j++];
        }
        else a[k++] = arr[i++];
    }
    while(i <= mid){
        a[k++] = arr[i++];
    }
    while(j <= end){
        a[k++] = arr[j++];
    }
    for(int i=s; i<=end; i++){
        arr[i] = a[i-s];
    }
    return ;
    
}

void divide(long long arr[], long long int s, long long int e){
    if(s<e){
        long long int mid = s+(e-s)/2;
        divide(arr, s, mid);
        divide(arr, mid+1, e);
        mergeii(arr, s, mid, e);
    }
    return ;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    ans = 0;
    long long int i=0, j=N-1;
    divide(arr, i, j);
    return ans;
    
    
}



//{ Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}

// } Driver Code Ends
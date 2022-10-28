class Solution {
public:
    int fib(int n) {
        /*
        
        //Solved by recursion 
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans =fib(n-1)+fib(n-2);
        return ans;*/
        
        //solved by for loop 
        
        if(n==0){           //return ans if n==0 or n==1
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        //allocate heap(dynamic) memory to store data
        int *arr=new int[n+2];
        arr[0]=0;
        arr[1]=1;
        
        //for loop upto n terms
        for(int i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        
        //store the answer in static memory
        int ans=arr[n];
        
        //delete the dynamic memory which is allocate for array 
        delete []arr;
        
        //return ans
        return ans;
    }
    
};
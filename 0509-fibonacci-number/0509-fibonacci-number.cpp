class Solution {
public:
    int fib(int n) {
        
        //write base case 
        //where recursion stop
        if(n<=1)
            return n;
        //now start processing to calculate result
        //recursive call 
        int prev = fib(n-1);
        int prev_of_prev = fib(n-2);

        return  prev + prev_of_prev;
    }
};
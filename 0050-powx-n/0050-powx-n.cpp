class Solution {
public:
    double solve(double x, int n){
        if(n==0) return 1;
        if(n%2==0){
            return solve(x*x, n/2);
        }
        else{
            return x*solve(x*x, n/2);
        }
    }
    double myPow(double x, int n) {
        if(n<0) x=1/x;
        return solve(x, n);
    }
};
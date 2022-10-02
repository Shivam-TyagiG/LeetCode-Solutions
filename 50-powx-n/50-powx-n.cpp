class Solution {
public:
    /*double myPow(double x, int n) {
        double y=1;
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(n==1||x==1){
            return x;
        }
        while(n>=1){
            //y<<1;
            y=y*x;
            n--;
        }
        while(n<=-1){
            y=y/x;
            n++;
        }
        return y;
        
    }*/
    double pow(double x, int n)
    {
        if(n==0)return 1;
        else if(n%2==0)
        {
            return pow(x*x,n/2);
        }
        
        else
        {
            return x*pow(x*x,n/2);
        }
    }
    double myPow(double x, int n) {
        //as in this question we have to return the power
        
        if(n<0)
        {
            n=abs(n);
            cout<<n<<endl;
            x=1/x;
        }
        return pow(x,n);
    }

};
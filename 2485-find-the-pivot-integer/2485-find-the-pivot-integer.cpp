class Solution {
public:
    int pivotInteger(int n) {
        int startsum = 1;
        int endsum = n;
        int start= 2;
        int end = n-1;
        int ans = 1;
        while(start <= end)
        {
            if(start == end)
            {
                startsum = startsum + start;
                endsum = endsum + end;
                ans = start;
                start++;
                end--;
            }
            else if(startsum < endsum)
            {
                startsum = startsum + start;
                
                start++;
            }
            else{
                endsum = endsum + end;
                end--;
            }
        }
        if(startsum == endsum)
        {
            return ans;
        }

        return -1;
    }
};
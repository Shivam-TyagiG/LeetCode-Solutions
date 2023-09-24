class Solution {
public:
    double champagneTower(int t, int query_row, int query_glass) {
         if(t == 0)
    {
        return 0;
    }
    int n= 0;
    if(query_row > query_glass)
    {
        n = query_row;
    }
    else{
        n = query_glass;
    }
    vector<vector<double>> v(n+2, vector<double> (n+2,0));
    v[0][0] = t;
    for(long long  i=0; i<=n; i++)
    {
        for(long long j=0; j<=i; j++)
        {
            if(v[i][j] > 1.0)
            {
                double extra = v[i][j] - 1.0;
                v[i][j] = 1.0;
                v[i+1][j]+= extra/2.0;
                v[i+1][j+1]+= extra/2.0;
            }
        }
    }
    return v[query_row][query_glass];
        
    
    }
};
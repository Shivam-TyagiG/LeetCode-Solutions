class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
//         unordered_map<int,int> m;
//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         for(int i=0; i<f.size(); i++){
//             m[f[i][0]]++;
//             mini= min(f[i][0], mini);
//             maxi= max(f[i][0], maxi);
//             m[f[i][1]]++;
//             mini= min(f[i][1], mini);
//             maxi= max(f[i][1], maxi);
//         }
        
//         for(int i=0; i<s.size(); i++){
//             m[s[i][0]]++;
//             mini= min(s[i][0], mini);
//             maxi = max(s[i][0], maxi);
//             m[s[i][1]]++;
//             mini= min(s[i][1], mini);
//             maxi = max(s[i][1], maxi);
            
//         }
        
//         vector<vector<int>> ans;
//         for(int i=mini; i<=maxi; ){
//             vector<int> output;
//             if(m[i]==2){
//                 output.push_back(i);
//                 while(m[i]==2){
//                     i++;
//                 }
//                 output.push_back(i-1);
//                 ans.push_back(output);
//             }
//             i++;
//         }
//         return ans;
        
        int i=0, j=0;
        vector<vector<int>> ans;
        vector<int> output(2);
        while(i<f.size() && j<s.size()){
            int a = f[i][0];
            int b = f[i][1];
            int c = s[j][0];
            int d = s[j][1];
            int  maxi = max(a,c);
            int  mini = min(b,d);
            if(a<=d && c<=b){
                output[0] = maxi;
                output[1] = mini;
                ans.push_back(output);
            }
            if(mini == b) i++;
            else j++;
        }
        
        return ans;
        
        
    }
};
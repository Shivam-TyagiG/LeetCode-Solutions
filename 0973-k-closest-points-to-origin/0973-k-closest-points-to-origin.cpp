bool cmp(vector<int> &a, vector<int> &b){
        return ((a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]));
    }
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;
        int count = 0;
        for(auto a : points){
            count++;
            ans.push_back(a);
            if(count==k) break;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        for(int i=1 ;i<intervals.size(); i++){
            int currmini = intervals[i][0];
            int currmaxi = intervals[i][1];
            if(currmini<=maxi){
                mini = min(mini, currmini);
                maxi = max(maxi, currmaxi);
            }
            else{
                vector<int> output;
                output.push_back(mini);
                output.push_back(maxi);
                ans.push_back(output);
                mini = currmini;
                maxi = currmaxi;
            }
        }
        vector<int> output;
        output.push_back(mini);
        output.push_back(maxi);
        ans.push_back(output);
        return ans;
    }
};
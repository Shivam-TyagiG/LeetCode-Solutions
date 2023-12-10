class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> arr(col, vector<int>(row));
        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                arr[i][j] = matrix[j][i];
            }
        }
        return arr;
    }
};
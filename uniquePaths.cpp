/* Coding challenge #62 from LeetCode */

class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix, int i, int j) {
        if ((i >= 0 && i < matrix.size()) && (j >= 0 && j < matrix[0].size()))
            return true;
        
        return false;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[n-1][j] = 1;
        }
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][m-1] = 1;
        }
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--) {
                if (isSafe(matrix, i, j+1)) {
                    matrix[i][j] += matrix[i][j+1];
                }
                if (isSafe(matrix, i+1, j)) {
                    matrix[i][j] += matrix[i+1][j];
                }
            }
        }
        return matrix[0][0];
    }
};

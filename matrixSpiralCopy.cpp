/* Coding challenge #54 from LeetCode */
/* Improved code from previous version */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        
        int start_row = 0;
        int end_row = matrix.size() - 1;
        int start_column = 0;
        int end_column = matrix[0].size()-1;
              
        while (start_row <= end_row && start_column <= end_column) {
             for (int j = start_column; j <= end_column; ++j) {
            result.push_back(matrix[start_row][j]);   
            }
            start_row++;
            if (start_row > end_row) {
                break;
            }
            for (int i = start_row; i <= end_row; i++) {
                result.push_back(matrix[i][end_column]);
            }
            end_column--;
            if (start_column > end_column) {
                break;
            }
            for (int j = end_column; j >= start_column; j--) {
                result.push_back(matrix[end_row][j]);
            }
            end_row--;
            for (int i = end_row; i >= start_row; i--) {
                result.push_back(matrix[i][start_column]);
            }
            start_column++;    
        }     
        return result;
    }
};

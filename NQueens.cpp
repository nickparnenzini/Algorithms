/* Coding challenge #51 from LeetCode */
class Solution {
public:
    
    bool isSafe(vector<vector<string>> board, int row, int col) {        
        for (int i = 0; i < col; i++) {
            if (board[row][i] == "Q")
                return false;
        }
        
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == "Q")
                return false;
        }
        
        for (int i = row, j = col; j >= 0 && i < board.size(); i++, j--) {
            if (board[i][j] == "Q")
                return false;
        }
        return true;
    }
    
    bool solveNQueensUtil(vector<vector<string>>& board, int col, vector<vector<string>>& result) {
        if (col == board.size()) {  
            vector<string> matrix;            
            for (int i = 0; i < board.size(); i++) {
                string st = "";
                for (int j = 0; j < board[0].size(); j++) {
                    st += board[i][j]; 
                }
                matrix.push_back(st);
            }            
            result.push_back(matrix);
            return true;
        }
        
        bool res = false;
        
        for (int i = 0; i < board.size(); i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = "Q";
                res = solveNQueensUtil(board, col+1, result) || res;               
                board[i][col] = ".";
            }
        }
        return res;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<string>> board(n, vector<string>(n));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = ".";
            }
        } 
        solveNQueensUtil(board, 0, result);
        return result;
    }
};

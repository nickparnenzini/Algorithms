/* Code challenge #200 from LeetCode */

class Solution {
public:
    bool isSafe(vector<vector<char>> grid, int row, int col, int n, int m, vector<vector<int>>& visited) {
      return (row >= 0) && (row < n) &&     
           (col >= 0) && (col < m) &&      
           ((grid[row][col] == '1') && (visited[row][col] == 0)); 
    }
    
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y, int n, int m) {
      visited[x][y] = 1;
      int dr[] = {-1, 1, 0,  0};
      int dc[] = {0,  0, 1, -1};
      
      for (int i = 0; i < 4; i++) {
        if (isSafe(grid, x + dr[i], y + dc[i], n, m, visited))
          DFS(grid, visited, x + dr[i], y + dc[i], n, m);
      }
    }
  
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty())
        return 0;
      
      int count = 0;
      int n = grid.size();
      int m = grid[0].size();  
      vector<vector<int>> visited(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          visited[i][j] = 0;
        }
      }   
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if ((grid[i][j] == '1') && (visited[i][j] == 0)) {   
            DFS(grid, visited, i, j, n, m); 
            ++count;
          }  
        }
      }
      return count;
    }
};

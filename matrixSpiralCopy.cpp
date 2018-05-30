#include <iostream>
#include <vector>

using namespace std;

 bool isSafe(int r, int c, int n, int m) {
      return (r >= 0 && r < n) && (c >= 0 && c < m);
    }
  
vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) {
  vector<int> result;
  if (inputMatrix.empty())
    return result;

  int n = inputMatrix.size();
  int m = inputMatrix[0].size();

  bool seen[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      seen[i][j] = false;
    }
  }
  int row = 0;
  int col = 0;
  int k = 0;
  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};
  for (int i = 0; i < n*m; i++) {
    result.push_back(inputMatrix[row][col]);
    seen[row][col] = true;
    // next position
    int next_row = row + dr[k];
    int next_col = col + dc[k];
    if (isSafe(next_row, next_col, n, m) && !seen[next_row][next_col]) {
      row = next_row;
      col = next_col;
    }
    else {
      k = (k+1)%4;
      row += dr[k];
      col += dc[k];
    }
  }
  return result;
}

int main() {
  /* Example matrix to test the implementation */
  vector<vector<int>> arr(4,vector<int>(5));
  int n = arr.size();
  int m = arr[0].size();
  int count = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = count++;
    }
  } 
  vector<int> result = spiralCopy(arr); 
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  int rows = inputMatrix.size();
  int cols = inputMatrix[0].size();
  vector<int> result;
  
  int countRes = 0;
  int maxCol = cols-1;
  int minCol = 0;
  int minRow = 0;
  int maxRow = rows-1;
  int j = minCol;
  int i = minRow;
  bool inProgress = true;
  
  while (inProgress) {
    i = minRow;
    j = minCol;
    
    while (j <= maxCol) {
      result.push_back(inputMatrix[i][j++]);
    }
      
    if (minRow >= maxRow) {
      break;
    }
    
    j = maxCol;
    // go down
    i++;
    while (i <= maxRow) {
      result.push_back(inputMatrix[i++][j]);
    }
    i = maxRow;
    j--;
    // go left
    while(j >= minCol) {
      result.push_back(inputMatrix[i][j--]);
    }
    j = minCol;
    // go up, but decrease minRow first
    minRow++;
    if ((minRow >= maxRow)) {
        break;
    }
    
    i--;
    while (i >= minRow) {  
      result.push_back(inputMatrix[i--][j]);     
    }
    // decrease maxCol
    maxCol--;
    // decrease maxRow
    maxRow--;
    // increase minCol
    minCol++;
    
    if ((minRow >= maxRow) || (minCol >= maxCol)) {
        inProgress = false;
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

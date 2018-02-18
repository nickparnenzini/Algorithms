/* Problem 1.8 from "Cracking the coding interview" */
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> matrix) {
    /* matrix is supposed to be N*N */
    int n = matrix.size();
    vector<vector<int>> result(n,vector<int>(n));
    
    for ( int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                if (result[i][j] == -1) {
                    /* change whole row to 0 */
                    for (int k = 0; k < n; k++) {
                        result[i][k] = 0;
                    }
                    /* change whole column to 0 */
                    for (int k = 0; k < n; k++) {
                        result[k][j] = 0;
                    }
                }    
            }   
            else {
                if (result[i][j] == -1) {
                    result[i][j] = matrix[i][j];
                }
            }
        }
    }
    
    return result;
}

int main()
{
    vector<vector<int>> matrix(3,vector<int>(3));
    matrix[0][0] = 4;
    matrix[0][1] = 8;
    matrix[0][2] = 3;
    matrix[1][0] = 2;
    matrix[1][1] = 0;
    matrix[1][2] = 5;
    matrix[2][0] = 6;
    matrix[2][1] = 4;
    matrix[2][2] = 3;
    vector<vector<int>> result = zeroMatrix(matrix);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

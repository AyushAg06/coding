// set matrix zeroes
#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowHasZero = false, firstColHasZero = false;
    // Check if the first row has a zero
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }
    // Check if the first column has a zero
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }
    // Mark rows and columns that need to be zeroed
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Zero out cells based on the markers in the first row and column
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    // Zero out the first row if needed
    if (firstRowHasZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    // Zero out the first column if needed
    if (firstColHasZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
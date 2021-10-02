// You are given n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).

// Input:
// [
//  [1, 2, 3]
//  [4, 5, 6]
//  [7, 8, 9]
// ]

// Output:
// [
//  [7, 4, 1]
//  [8, 5, 2]
//  [9, 6, 3]
// ]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class RotateMatrix
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
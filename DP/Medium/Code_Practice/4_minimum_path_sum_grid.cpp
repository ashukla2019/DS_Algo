
Problem:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

----------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> & dp, vector<vector<int>> &grid, int row, int col) {
        if(row == 0 && col == 0) return grid[0][0];
        if(row < 0 || col < 0) return INT_MAX;
        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = grid[row][col] + min(solve(dp, grid, row - 1, col), solve(dp, grid, row, col - 1));

    }
    int minPathSum(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m , vector<int> (n , -1));

        return solve(dp, grid, m-1, n-1);

    }

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}

class Solution {
public:
    int findMaxSum(int n, int m, vector<vector<int>>& mat) {
        int mx = INT_MIN;
        // Iterate over the rows
        for (int i = 0; i <= n - 3; i++) {
            // Iterate over the columns
            for (int j = 0; j <= m - 3; j++) {
                // Calculate the sum of the hourglass submatrix starting at position (i, j)
                int sum = (mat[i][j] + mat[i][j + 1] + mat[i][j + 2]) +
                          (mat[i + 1][j + 1]) +
                          (mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2]);
                // Update the maximum sum
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};

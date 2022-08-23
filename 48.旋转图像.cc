class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom) {
            for (int k = left; k < right; ++k) {
                int tmp = matrix[top][k];
                matrix[top][k] = matrix[bottom+top-k][left];
                matrix[bottom+top-k][left] = matrix[bottom][right+left-k];
                matrix[bottom][right+left-k] = matrix[k][right];
                matrix[k][right] = tmp;
            }
            ++left; --right;
            ++top; --bottom;
        }
    }
};

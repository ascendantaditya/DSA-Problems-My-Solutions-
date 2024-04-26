class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        for (int i = 1; i < n; ++i) {
            auto [firstMinNum, firstMinIndex, secondMinNum] = getTwoMinNums(grid[i - 1]);
            for (int j = 0; j < n; ++j) {
                if (j == firstMinIndex)
                    grid[i][j] += secondMinNum;
                else
                    grid[i][j] += firstMinNum;
            }
        }

        return *min_element(grid.back().begin(), grid.back().end());
    }
    
private:
    tuple<int, int, int> getTwoMinNums(const vector<int>& A) {
        auto it1 = A.begin(), it2 = A.begin();
        int minNum = numeric_limits<int>::max(), secondMinNum = numeric_limits<int>::max();
        for (auto it = A.begin(); it != A.end(); ++it) {
            if (*it < minNum) {
                secondMinNum = minNum;
                minNum = *it;
                it2 = it1;
                it1 = it;
            } else if (*it < secondMinNum) {
                secondMinNum = *it;
                it2 = it;
            }
        }
        return {minNum, static_cast<int>(distance(A.begin(), it1)), secondMinNum};
    }
};

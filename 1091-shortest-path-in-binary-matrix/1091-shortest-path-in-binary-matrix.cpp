class Solution {
public:
    vector<vector<int>> directions = {{0, 1},  {1, 0},  {0, -1}, {-1, 0},
                                      {1, -1}, {-1, 1}, {1, 1},  {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<vector<int>> que;

        int result = INT_MAX;

        vector<int> temp = {0, 0, 1};
        que.push(temp);
        grid[0][0] = 1;

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int count = que.front()[2];
            que.pop();

            if (i == n - 1 && j == n - 1) {
                result = count;
                break;
            }

            for (auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                    grid[new_i][new_j] == 0) {

                    grid[new_i][new_j] = 1;

                    temp = {new_i, new_j, 1 + count};
                    que.push(temp);
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
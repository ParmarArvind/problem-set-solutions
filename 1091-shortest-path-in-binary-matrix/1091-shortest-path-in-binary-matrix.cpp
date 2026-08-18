// BFS better 
class Solution {
public:
    vector<vector<int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, -1}, {-1, 1}, {1, 1}, {-1, -1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> que;

        que.push({0, 0});
        grid[0][0] = 1;

        int level = 1;

        while (!que.empty()) {

            int size = que.size();

            // Process one complete level
            while (size--) {

                auto [i, j] = que.front();
                que.pop();

                // Destination
                if (i == n - 1 && j == n - 1)
                    return level;

                for (auto& dir : directions) {

                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < n &&
                        new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 0) {

                        // Mark visited when pushing
                        grid[new_i][new_j] = 1;

                        que.push({new_i, new_j});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};

// //method -2 BFS 
// class Solution {
// public:
//     vector<vector<int>> directions = {{0, 1},  {1, 0},  {0, -1}, {-1, 0},
//                                       {1, -1}, {-1, 1}, {1, 1},  {-1, -1}};

//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         int n = grid.size();

//         if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
//             return -1;

//         queue<vector<int>> que;

//         int result = INT_MAX;

//         vector<int> temp = {0, 0, 1};
//         que.push(temp);
//         grid[0][0] = 1;

//         while (!que.empty()) {
//             int i = que.front()[0];
//             int j = que.front()[1];
//             int count = que.front()[2];
//             que.pop();

//             if (i == n - 1 && j == n - 1) {
//                 result = count;
//                 break;
//             }

//             for (auto& dir : directions) {
//                 int new_i = i + dir[0];
//                 int new_j = j + dir[1];

//                 if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
//                     grid[new_i][new_j] == 0) {

//                     grid[new_i][new_j] = 1;

//                     temp = {new_i, new_j, 1 + count};
//                     que.push(temp);
//                 }
//             }
//         }

//         return result == INT_MAX ? -1 : result;
//     }
// };


// // method-1  DFS +backtracing (TLE)
// class Solution {
// public:
//     int n;
//     vector<vector<int>>directions{{0,1} ,{ 1,0} ,{ 0 ,-1 } ,{-1,0} ,{1,-1} ,{-1,1} ,{1,1} ,{-1 ,-1}};
//     int dfs(vector<vector<int>>& grid ,int i ,int j,int pathCount)
//     {
//         if(i==n-1 && j==n-1) return pathCount;
        
//         int result=INT_MAX;
//         for(auto &dir:directions)
//         {
//             int new_i=i+dir[0];
//             int new_j=j+dir[1];

//             if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && grid[new_i][new_j]==0)
//             {
//                  grid[new_i][new_j]=1;

//                 result=min(result,dfs(grid, new_i,new_j,pathCount+1));

//                  grid[new_i][new_j]=0;
//             }
//         }

//         return result;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         if(grid[0][0]==1) return -1;
//         n=grid.size();
//         int pathCount=1;
//         int result=dfs(grid,0,0,pathCount);

//         return  result==INT_MAX ? -1 : result;
//     }
// };

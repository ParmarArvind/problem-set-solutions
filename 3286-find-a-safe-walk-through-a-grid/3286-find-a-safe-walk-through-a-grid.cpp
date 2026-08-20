// method 3 01-BFS
class Solution {
public:
    vector<vector<int>>directions{{1,0} ,{0,1} ,{0,-1},{-1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        
        deque<pair<int,int>>deq;
        result[0][0]=grid[0][0];
        deq.push_front({0,0});

        while(!deq.empty())
        {
            auto [i,j]=deq.front();
            deq.pop_front();

            for(auto &dir:directions)
            {
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n)
                {
                    int wt=grid[ni][nj];
                    int prev=result[i][j];
                    if(prev+wt < result[ni][nj])
                    {
                        result[ni][nj]=prev+wt;

                        if(grid[ni][nj]==0) deq.push_front({ni,nj});
                        else  deq.push_back({ni,nj});
                    }
                }
            }
        }
        return result[m-1][n-1]>=health ? false : true;
    }
};


// // method -2  dijkstra 
// class Solution {
// public:
//     vector<vector<int>>directions{{1,0} ,{0,1} ,{0,-1},{-1,0}};
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int m=grid.size();
//         int n=grid[0].size();

//         priority_queue<
//             pair<int,pair<int,int>> ,
//             vector<pair<int,pair<int,int>>>,
//             greater<pair<int,pair<int,int>>>>pq;

//         pq.push({grid[0][0],{0,0}});

        // vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
//         while(!pq.empty())
//         {
//             int d=pq.top().first;
//             auto p=pq.top().second;
//             int i=p.first;
//             int j=p.second;
//             pq.pop();
//             for(auto &dir:directions)
//             {
//                 int ni=i+dir[0];
//                 int nj=j+dir[1];
//                 if(ni>=0 && ni<m && nj>=0 && nj<n)
//                 {
//                     int wt=grid[ni][nj];
//                     if(d+wt<cost[ni][nj])
//                     {
//                         cost[ni][nj]=d+wt;
//                         pq.push({d+wt , {ni,nj}});
//                     }
//                 }
//             }

//         }

//         return cost[m-1][n-1]>=health? false : true;
//     }
// };


// // method -1 DFS (TLE)
// class Solution {
// public:
//     int result ,n ,m;
//     vector<vector<int>>directions{{1,0} ,{0,1} ,{0,-1},{-1,0}};

//     void solve(vector<vector<int>>& grid ,int i,int j,int cost)
//     {
//         if(i==m-1 && j==n-1)
//         {
//             result=min(result,cost);
//             return ;
//         }
        
//         for(auto &dir:directions)
//         {
//             int ni=i+dir[0];
//             int nj=j+dir[1];
//             if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]!=INT_MAX)
//             {
//                 int wt=grid[ni][nj];
//                 grid[ni][nj]=INT_MAX;
//                 solve(grid,ni,nj,cost+wt);
//                 grid[ni][nj]=wt;
//             }
//         }
//     }
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         result=INT_MAX;
//         m=grid.size();
//         n=grid[0].size();
//         int val=grid[0][0];
//         grid[0][0]=INT_MAX;
//         solve(grid,0,0,val);
//         cout<<result;
//         return result>=health ? false : true;
//     }
// };


// method 2 bottom up
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int t[m+1][n+1];
        t[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            t[i][0]=t[i-1][0]+grid[i][0];
        }

        for(int j=1;j<n;j++)
        {
            t[0][j]=t[0][j-1] +grid[0][j];
        }

        for(int i=1; i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                t[i][j]=grid[i][j]+min(t[i-1][j] , t[i][j-1]);
            }
        }

        return t[m-1][n-1];
    }
};

// // method 1 recu +memo
// class Solution {
// public:
//     int t[201][201];
//     int m , n;
//     int solve(vector<vector<int>>& grid,int i,int j)
//     {
//         if(i==m-1 && j==n-1) return grid[i][j];
//         if(i>=m || j>=n) return INT_MAX;

//         if(t[i][j] !=-1) return t[i][j];

//         int down=solve(grid,i+1,j);
//         if(down != INT_MAX) down+=grid[i][j];

//         int right=solve(grid ,i,j+1);
//         if(right != INT_MAX) right+=grid[i][j];
        
//         return t[i][j]=min(right,down);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         memset(t,-1,sizeof(t));
//         return solve(grid,0,0);
//     }
// };


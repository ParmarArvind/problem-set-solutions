
//method 2 bottom up
class Solution {
public:
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        // fill first column
        for(int i=0;i<m;i++) {
            if(obstacleGrid[i][0]==1)
            {
                break;
            }
            t[i][0]=1;
        }

        // fill first row
        for(int j=0;j<n;j++) {
            if(obstacleGrid[0][j]==1)
            {
                break;
            }
            t[0][j]=1;
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    t[i][j]=0;
                else t[i][j]=t[i-1][j] +t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};

// // method 1 recu +memo
// class Solution {
// public:
//     int t[101][101];
//      int m, n;
//     int solve(vector<vector<int>>& obstacleGrid,int i,int j)
//     {
        
//         if(i>=m || j>=n || obstacleGrid[i][j] ==1) return 0;
//         if(i==m-1 && j==n-1) return 1;

//         if(t[i][j] !=-1 )return t[i][j];
//         int down=solve(obstacleGrid,i+1, j);
//         int right=solve(obstacleGrid,i,j+1);
        
//         return t[i][j]=down +right;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         m=obstacleGrid.size();
//         n=obstacleGrid[0].size();
//         memset(t,-1,sizeof(t));
//         return solve(obstacleGrid,0,0);
//     }
// };
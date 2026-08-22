// method 1 recu +memo
class Solution {
public:
    int t[101][101];
     int m, n;
    int solve(vector<vector<int>>& obstacleGrid,int i,int j)
    {
        
        if(i>=m || j>=n || obstacleGrid[i][j] ==1) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(t[i][j] !=-1 )return t[i][j];
        int down=solve(obstacleGrid,i+1, j);
        int right=solve(obstacleGrid,i,j+1);
        
        return t[i][j]=down +right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(obstacleGrid,0,0);
    }
};
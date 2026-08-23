class Solution {
public:
    int m ,n;
    int t[201][201];
    int solve(vector<vector<int>>& dungeon ,int i,int j)
    {
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) 
        {
            return dungeon[i][j] < 0 ? abs(dungeon[i][j]) +1 : 1 ;
        }

        if(t[i][j] != -1) return t[i][j]; 

        int down=solve(dungeon,i+1,j);
        int right=solve(dungeon,i,j+1);
        int requiredHealth= min(down ,right)-dungeon[i][j];

        return t[i][j]=  requiredHealth > 0 ?  requiredHealth : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        memset(t,-1,sizeof(t));
        return solve(dungeon , 0,0);
    }
};
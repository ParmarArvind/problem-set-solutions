class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>t(m,vector<int>(n));

        for(int i=m-1;i>=0 ;i--)
        {
            for(int j=n-1;j>=0 ;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    if(dungeon[i][j]>0) t[i][j]=1;
                    else t[i][j]=abs(dungeon[i][j])+1;
                }
                else{
                    int down= i+1 >=m ? 1e9 : t[i+1][j];
                    int right=j+1>=n ? 1e9 : t[i][j+1];

                    int requiredHealth= min(down ,right)-dungeon[i][j];

                    t[i][j] = requiredHealth >0 ? requiredHealth :1;
                }
            }
        }

        return t[0][0];
    }
};


// class Solution {
// public:
//     int m ,n;
//     int t[201][201];
//     int solve(vector<vector<int>>& dungeon ,int i,int j)
//     {
//         if(i>=m || j>=n) return 1e9;
//         if(i==m-1 && j==n-1) 
//         {
//             return dungeon[i][j] < 0 ? abs(dungeon[i][j]) +1 : 1 ;
//         }

//         if(t[i][j] != -1) return t[i][j]; 

//         int down=solve(dungeon,i+1,j);
//         int right=solve(dungeon,i,j+1);
//         int requiredHealth= min(down ,right)-dungeon[i][j];

//         return t[i][j]=  requiredHealth > 0 ?  requiredHealth : 1;
//     }
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         m=dungeon.size();
//         n=dungeon[0].size();
//         memset(t,-1,sizeof(t));
//         return solve(dungeon , 0,0);
//     }
// };
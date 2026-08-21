// bottom up
class Solution {
public:
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 ||j==0) dp[i][j]=i+j;

                else if (s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min({dp[i-1][j] ,dp[i][j-1] , dp[i-1][j-1]});
            }
        }

        return dp[m][n];
    }
};

// // mehtod 1 top -down 
// class Solution {
// public:
//     int dp[501][501];
//     int m , n;
//     int solve(string &s1, string &s2 ,int i ,int j)
//     {
//         if (i>=m) return n-j;
//         if(j>=n) return m-i;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s1[i] == s2[j])
//         {
//             return dp[i][j]=solve(s1,s2,i+1,j+1);
//         }
//         else {
//             int deleteChar=1+solve(s1,s2,i+1,j);
//             int insertChar=1+solve(s1,s2,i,j+1);
//             int replaceChar=1+solve(s1,s2,i+1,j+1);

//             return dp[i][j]=min({deleteChar ,insertChar,replaceChar});
//         }
//     }
//     int minDistance(string s1, string s2) {
//         m=s1.size();
//         n=s2.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(s1,s2,0,0);
//     }
// };
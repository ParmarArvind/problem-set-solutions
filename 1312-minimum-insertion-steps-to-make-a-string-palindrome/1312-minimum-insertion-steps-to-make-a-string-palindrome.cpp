// method -4 bottom up
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        
        vector<vector<int>>dp(n,vector<int>(n));

        for(int i=0;i<n;i++) dp[i][i]=0;

        for(int L=2;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;
                
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else {
                    dp[i][j]= 1+min(dp[i+1][j] ,dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};

// // method -3 recursion +memo
// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(string& s ,int i,int j)
//     {
//         if(i>=j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]= solve(s,i+1,j-1);

//         return dp[i][j]=1+min(solve(s,i+1,j) , solve(s,i,j-1));
//     }
//     int minInsertions(string s) {
//         int n=s.size();
//         memset(dp,-1, sizeof(dp));
//         return solve(s,0,n-1);
        
//     }
// };


// // method 2 using LCS bottom up 
// class Solution {
// public:
//     int minInsertions(string s1) {
//         int n=s1.size();
//         string s2=s1;
       
//         reverse(s2.begin() ,s2.end());
//         vector<vector<int>>dp(n+1,vector<int>(n+1,1));

//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=n;j++)
//             {
//                 if(i==0 || j==0)  dp[i][j]=0;
//                 else if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else {
//                     dp[i][j]= max(dp[i-1][j] ,dp[i][j-1]);
//                 }
//             }
//         }

//         return n-dp[n][n];
//     }
// };


// // method -1 using LCS (recu +memo )
// class Solution {
// public:
//     int n;
//     int t[501][501];
//     int solve(string &s1,string &s2,int i,int j)
//     {
//         if(i==n || j==n) return 0;

//         if(t[i][j] !=-1) return t[i][j];

//         if(s1[i]== s2[j]) return t[i][j]=1+solve(s1,s2,i+1,j+1);

//         return t[i][j]=max(solve(s1,s2,i+1,j) ,solve(s1,s2,i,j+1));

//     }
//     int LCS(string & s1,string &s2)
//     {
//         memset(t,-1,sizeof(t));
//         return solve(s1,s2,0,0);
//       }

//     int minInsertions(string s1) {
//         n=s1.size();
//         string s2;
//         for(int i=n-1;i>=0;i--)
//         {
//             s2.push_back(s1[i]);
//         }
//         return n-LCS(s1,s2);
        
//     }
// };
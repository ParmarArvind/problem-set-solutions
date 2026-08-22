// method -3 recursion +memo
class Solution {
public:
    int dp[1001][1001];
    int solve(string& s ,int i,int j)
    {
        if(i>j) return 0;
        else if(i==j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]= 2+solve(s,i+1,j-1);

        return dp[i][j]=max(solve(s,i+1,j) , solve(s,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        memset(dp,-1, sizeof(dp));
        return solve(s,0,n-1);
        
    }
};

// // method 2 using LCS bottom up 
// class Solution {
// public:
//     int longestPalindromeSubseq(string s1) {
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

//         return dp[n][n];
//     }
// };


// //  method -1 using LCS recu+memo tc=O(n^2) ,sc =o(n^2)
// class Solution {
// public: 
//     int n;
//     int dp[1001][1001];
//     int LCS(string &s1 ,string &s2 ,int i,int j)
//     {
//         if(i==n || j==n ) return 0;

//         if(dp[i][j] !=-1) return dp[i][j];

//         if(s1[i] ==s2[j]) return dp[i][j] =1+LCS(s1,s2,i+1,j+1);
//         // else 
//         return dp[i][j] =max( LCS(s1,s2,i,j+1) ,LCS(s1,s2,i+1,j));
//     }
//     int longestPalindromeSubseq(string s1) {
//         n=s1.size();
//         string s2=s1;
//         memset(dp,-1,sizeof(dp));
//         reverse(s2.begin() ,s2.end());
        
//         return LCS(s1,s2,0 ,0);
//     }
// };
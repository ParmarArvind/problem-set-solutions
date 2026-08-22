class Solution {
public: 
    int n;
    int dp[1001][1001];
    int LCS(string &s1 ,string &s2 ,int i,int j)
    {
        if(i==n || j==n ) return 0;

        if(dp[i][j] !=-1) return dp[i][j];

        if(s1[i] ==s2[j]) return dp[i][j] =1+LCS(s1,s2,i+1,j+1);
        // else 
        return dp[i][j] =max( LCS(s1,s2,i,j+1) ,LCS(s1,s2,i+1,j));
    }
    int longestPalindromeSubseq(string s1) {
        n=s1.size();
        string s2=s1;
        memset(dp,-1,sizeof(dp));
        reverse(s2.begin() ,s2.end());
        
        return LCS(s1,s2,0 ,0);
    }
};
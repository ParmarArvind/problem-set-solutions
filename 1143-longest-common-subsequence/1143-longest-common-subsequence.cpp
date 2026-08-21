// method -2 bottom up with  printing LIS string
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

         for(int i=0;i<m;i++) dp[i][0]=0;
         for(int j=0;j<n;j++) dp[0][j]=0;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
               
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }


        // print LIS
        string LIS;
        int i=m;
        int j=n;
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1]) {
                LIS.push_back(s1[i-1]);
                i-- ,j--;
            }
            else {
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(LIS.begin() ,LIS.end());
        cout<<LIS<<endl;

        return  dp[m][n];
    }
};



// class Solution {
// public:

//     int n , m;
//     int t[1001][1001];
//     int solve(string& s1,string& s2,int i,int j)
//     {
//         if(i>=n || j>=m) 
//             return 0;


//         if(t[i][j] != -1) 
//             return t[i][j];

        
//         if(s1[i]==s2[j] ) 
//             return t[i][j] =1+solve(s1,s2,i+1,j+1);
    
//         return t[i][j]=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         n=s1.size();
//         m=s2.size();

//         memset(t,-1,sizeof(t));

//         return solve(s1,s2,0,0);
//     }
// };
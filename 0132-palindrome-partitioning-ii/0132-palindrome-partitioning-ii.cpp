class Solution {
public:
    int minCut(string s) {
        int n=s.size();

        vector<vector<bool>>t( n ,vector<bool>(n,false));
        // state t[i][j]=true -> s[i:j] is palindrome 

        for(int i=0;i<n;i++ ) t[i][i]=true;

        for(int L=2;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;

                if(s[i]==s[j])
                {
                    if(L==2) t[i][j]=true;
                    else t[i][j]=t[i+1][j-1];
                }
            }
        }

        
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            if(t[0][i]==true) dp[i]=0;
            else {
                dp[i]=INT_MAX;
                for(int k=0;k<i;k++)
                {
                    if(t[k+1][i] ==true && 1+dp[k] <dp[i]) 
                    {
                        dp[i]= 1+dp[k];
                    }
                }
            }
        }      

        return dp[n-1];


    }
};

// // method 1 recu +memo (TLE) TC=O(n^3)
// class Solution {
// public:
//     int dp[2001][2001];
//     int t[2001][2001];
//     bool isPalindrome(string &s, int i,int j)
//     {
//         if(i>=j) return true;
//         if(t[i][j] !=-1) return t[i][j];
        
//         if(s[i]==s[j]) return  t[i][j] = isPalindrome(s,i+1,j-1);
//         return  t[i][j]= false;
//     }

//     int solve(string & s ,int i,int j)
//     {
//         if(i>=j) return 0; // no cut  required
//         if( isPalindrome(s,i,j)) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int cuts=INT_MAX;
//         for(int k=i; k<=j-1;k++) // cuts
//         {
//             int temp=1+ solve(s,i,k) + solve(s,k+1,j);
//             cuts=min( temp ,cuts);
//         }

//         return dp[i][j]=cuts;
//     }
//     int minCut(string s) {
//         int n=s.size();
//         memset(dp,-1,sizeof(dp));
//         memset(t,-1,sizeof(t));
//         return solve(s,  0 ,n-1);
//     }
// };
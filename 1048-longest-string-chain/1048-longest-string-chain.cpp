class Solution {
public:
    bool isValid(string& a,string& b)
    {
        int n=a.size();
        int m=b.size();
        if( n != m+1) return false;

        int i=0, j=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j]) {
                i++ ,j++;
            }
            else i++;
        }

        return j==m;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();

        sort(words.begin() ,words.end() ,[](auto &a ,auto &b) 
        {
            return a.size()<b.size();
        });

        vector<int>dp(n,1);
        int maxLength=1;
        for(int curr=0;curr<n;curr++)
        {
            for(int prev=0;prev<curr;prev++)
            {
                
                if(isValid(words[curr] ,words[prev]))
                {
                    dp[curr]=max(dp[curr] , 1+dp[prev]);
                    maxLength=max(maxLength ,dp[curr]);
                }
            }
        }

        return maxLength;

    }
};


// class Solution {
// public:
//     int dp[1001][1001];
//     bool isValid(string& a,string& b)
//     {
//         int n=a.size();
//         int m=b.size();
//         if( n != m+1) return false;

//         int i=0, j=0;
//         while(i<n && j<m)
//         {
//             if(a[i]==b[j]) {
//                 i++ ,j++;
//             }
//             else i++;
//         }

//         return j==m;
//     }

//     int solve(vector<string>& words ,int curr,int prev )
//     {
//         if(curr>=words.size()) return 0;

//         if(prev!=-1 && dp[curr][prev] !=-1) return dp[curr][prev];

//         int take=0;
//         if(prev==-1 || isValid(words[curr] , words[prev]) ) take = 1+solve(words , curr+1,curr);

//         int skip=solve(words,curr+1,prev);

//         if(prev==-1) return max(take,skip);
//         return dp[curr][prev] =max(take,skip);
//     }

//     int longestStrChain(vector<string>& words) {

//         sort(words.begin() ,words.end() ,[](auto &a ,auto &b)
//         {
//             return a.size()<b.size();
//         });

//         memset(dp,-1,sizeof(dp));
//         return solve(words,0,-1);
//     }
// };
// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
        
//         int n=pairs.size();
//         sort(pairs.begin(), pairs.end());
//         vector<int> t(n,1);
        
//         int maxLength=1;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(pairs[j][1] <pairs[i][0])
//                 {
//                     t[i]=max(t[i],t[j]+1);
//                     maxLength= max(maxLength,t[i]);
//                 }
//             }
//         }

//         return maxLength;

//     }
// };




class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs ,int curr,int prev)
    {
        if(curr>=pairs.size()) return 0;

        if(prev!=-1 && dp[curr][prev]!=-1) return dp[curr][prev];

        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[curr][0]) take=1+solve(pairs,curr+1,curr);
        int skip=solve(pairs,curr+1, prev);

        if(prev==-1) return max(take,skip);
        return dp[curr][prev]=max(take,skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(pairs ,0,-1);
    }
};
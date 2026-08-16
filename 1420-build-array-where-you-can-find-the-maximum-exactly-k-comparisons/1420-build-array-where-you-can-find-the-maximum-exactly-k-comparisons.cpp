class Solution {
public:
    int dp[51][51][101];
    int N , M , K ;
    int MOD=1e9+7;
    int solve(int idx, int searchCost, int maxVal)
    {
        if(idx==N)
        {
            if(searchCost==K) return 1;
            return 0;
        }

        if(maxVal!=-1 && dp[idx][searchCost][maxVal] !=-1) return dp[idx][searchCost][maxVal] ;

        int totalWays=0;
        for(int i=1;i<=M;i++)
        {
            if(i>maxVal)
            {
                totalWays = (totalWays + solve(idx+1 , searchCost+1, i))%MOD;
            }
            else totalWays= (totalWays+ solve(idx+1,searchCost,maxVal) )%MOD;
            
        }

        if(maxVal==-1) return totalWays%MOD;
        return dp[idx][searchCost][maxVal] =totalWays%MOD;
    }


    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        int searchCost=0;
        int maxVal=0;
        int idx=0;
        memset(dp,-1,sizeof(dp));
        return solve(idx,searchCost,maxVal);
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result=LLONG_MIN;
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2));


        for(int i=1 ;i<=n ;i++)
        {
            dp[i][0]= max(dp[i-1][1] - nums[i-1] , dp[i-1][0]) ; 
            dp[i][1]=max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0] ,dp[n][1]);
    }
};


// class Solution {
// public:
    
//     int n;
//     long long dp[100001][2];
//     long long solve(vector<int>&nums, int i,bool isEven )
//     {
//         if(i>=n) return 0L;

//         if(dp[i][isEven] != LLONG_MIN) return dp[i][isEven];

//         long long take=0L;
//         if(isEven) take = nums[i] + solve(nums,i+1,!isEven);
//         else  take =-nums[i] +solve(nums,i+1,!isEven);

//         long long skip=solve(nums,i+1,isEven);

//         return dp[i][isEven]= take > skip ? take :skip;

//     }
//     long long maxAlternatingSum(vector<int>& nums) {
        
//         n=nums.size();
        
//         for(int i=0;i<100000;i++)
//         {
//             dp[i][0]=dp[i][1]=LLONG_MIN;
//         }
//         solve(nums,0,true);

//         return dp[0][0] > dp[1][0] ? dp[0][0]:dp[0][1] ;
//     }
// };
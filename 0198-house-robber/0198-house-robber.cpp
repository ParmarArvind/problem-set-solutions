class Solution {
public:
    int rob(vector<int>& nums) {

        int prevPrev=0;
        int prev=nums[0];
        

        for(int i=2;i<=nums.size();i++)
        {
            int steal=nums[i-1]+prevPrev;
            int skip=prev;
            
            prevPrev=prev;
            prev= max(steal, skip);
            
        }

        return prev;
    }
};
// // method 2 bottom up
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(101);

//         dp[0]=0;
//         dp[1]=nums[0];
//         int n=nums.size();
//         for(int i=2; i<=n;i++)
//         {
//             // steal
//             int steal=nums[i-1]+dp[i-2];
//             int skip=dp[i-1];

//             dp[i]=max(skip, steal);
//         }

//         return dp[n];
//     }
// };

// // // method 1 recusion + memotization (top down)
// // class Solution {
// // public:

// //     int solve(vector<int> &nums,int i,int n,vector<int> &dp)
// //     {   
// //          if(i>=n) return 0;

// //         if(dp[i] != -1) return dp[i];

// //         int steal=nums[i]+solve(nums,i+2,n,dp);
// //         int skip=solve(nums,i+1,n,dp);

// //         return dp[i]=max(steal,skip);
// //     }

// //     int rob(vector<int>& nums) {
// //         int n= nums.size();
// //         vector<int>dp(101,-1);

// //         return solve(nums , 0 , n , dp);
        
// //     }
// // };
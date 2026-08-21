// method 3 Patience Sorting 
// TC= (nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;

        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(sorted.begin() ,sorted.end(),nums[i]);

            if(it==end(sorted)) sorted.push_back(nums[i]);
            else *it=nums[i];

        }

        return sorted.size();
    }
};

// method -2 bottom up  TC= O(n^2) SC+O(N)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>t(n+1,1);
//         int maxLIS=1;
//         for(int curr=0;curr<n;curr++)
//         {
//             for(int prev=0;prev<curr;prev++)
//             {
//                 int take=0;
//                 if(nums[prev]<nums[curr]) 
//                 {
//                     take =1+t[prev];
//                     t[curr]=max(t[curr] , take);
//                     maxLIS=max(maxLIS,t[curr]);
//                 }

//             }
//         }

//         return maxLIS;
//     }
// };

// class Solution {
// public:
//     int dp[2501][2501];
//     int solve(vector<int>&nums, int curr,int prev)
//     {
//         if(curr>=nums.size()) return 0;

//         if(prev !=-1 && dp[curr][prev] != -1) return dp[curr][prev];

//         int skip=solve(nums,curr+1,prev);

//         int take=0;
//         if(prev==-1) take=1+solve(nums,curr+1,curr);
//         else if(nums[prev]<nums[curr]) take=1+solve(nums,curr+1,curr);

//         if(prev == -1) return max(take,skip);

//         return dp[curr][prev]=max(take,skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {

//         memset(dp,-1,sizeof(dp));

//         return solve(nums , 0,-1);
//     }
// };
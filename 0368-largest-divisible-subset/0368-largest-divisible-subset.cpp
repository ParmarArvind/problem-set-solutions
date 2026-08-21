class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n , 1);
        vector<int>prevIdx(n,-1);

        int lastIdx=1;
        int maxLIS=0;
        for(int curr=0;curr<n ;curr++)
        {
            for(int prev=0;prev<curr;prev++)
            {
                if(nums[curr]%nums[prev]==0)
                {
                    if(dp[curr]<dp[prev]+1)
                    {
                        dp[curr]=dp[prev]+1;
                        prevIdx[curr]=prev;
                    }
                }
            }
            if(dp[curr]>maxLIS)
            {
                maxLIS=dp[curr];
                lastIdx=curr;
            }
        }

        vector<int>result;
        while(lastIdx!=-1)
        {
            result.push_back(nums[lastIdx]);
            lastIdx=prevIdx[lastIdx];
        }

        reverse(result.begin(),result.end());

        return result;
    }
};

// // method -2 recusion + memo
// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;

//     int solve(vector<int>& nums, int i, int prev) {
//         if (i == n)
//             return 0;

//         if (dp[i][prev + 1] != -1)
//             return dp[i][prev + 1];

//         // Option 1: Skip current element
//         int notTake = solve(nums, i + 1, prev);

//         // Option 2: Take current element
//         int take = 0;
//         if (prev == -1 || nums[i] % nums[prev] == 0) {
//             take = 1 + solve(nums, i + 1, i);
//         }

//         return dp[i][prev + 1] = max(take, notTake);
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         n = nums.size();
//         dp.assign(n, vector<int>(n + 1, -1));

//         solve(nums, 0, -1);

//         // Reconstruct answer
//         vector<int> ans;
//         int i = 0, prev = -1;

//         while (i < n) {
//             int notTake = solve(nums, i + 1, prev);

//             int take = -1;
//             if (prev == -1 || nums[i] % nums[prev] == 0)
//                 take = 1 + solve(nums, i + 1, i);

//             if (take >= notTake) {
//                 ans.push_back(nums[i]);
//                 prev = i;
//             }

//             i++;
//         }

//         return ans;
//     }
// };

// //method -1 recursive (O(2^n)  -> TLE)
// class Solution {
// public:
//     vector<int>result;
//     int n;
    
//     void solve(vector<int>&nums ,int i,vector<int>&curr,int prev)
//     {
//         if(i==n)
//         {
//             if(curr.size()>result.size())
//                 result=curr;
//             return ;
//         }

//         int take;
//         if(prev==-1|| nums[i]%prev==0)
//         {
//             curr.push_back(nums[i]);
//             solve(nums ,i+1 ,curr,nums[i]);
//             curr.pop_back();
//         }
        
//         solve(nums,i+1,curr,prev);
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         result.clear();
//         n=nums.size();
//         vector<int>curr;
        
//         solve(nums,0,curr,-1);
//         return result;
//     }
// };
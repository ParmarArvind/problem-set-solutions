class Solution {
public:

    int solve(vector<int>& nums, int idx, vector<int>& dp)
    {
        if(idx >= nums.size()-1) return 0;

        if(nums[idx] == 0) return dp[idx]=INT_MAX;

        if(dp[idx] != -1) return dp[idx];

        int result=INT_MAX;
        for(int step = 1; step <= nums[idx]; step++)
        {
            int temp=solve(nums, idx + step, dp) ;
            result =min(result,temp);
        }

        if(result==INT_MAX) return INT_MAX;
        return dp[idx] = 1 + result;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, 0, dp);
    }
};
class Solution {
public:
int t[201][20001];
    int totalSum;
    int n;
    bool solve(vector<int>&nums , int i, int currSum )
    {
        if(currSum*2==totalSum) return true;
        if(i == n || currSum*2 > totalSum )return false;

        if(t[i][currSum] != -1 ) return t[i][currSum] ;

        bool take =solve(nums, i+1 ,currSum+nums[i]);
        bool skip = solve(nums,i+1 ,currSum);

        return t[i][currSum] = (take || skip );
    }
    bool canPartition(vector<int>& nums) {
        totalSum=0;
        n=nums.size();
        for(int num:nums) totalSum += num;

        memset(t,-1,sizeof(t));

        return solve(nums , 0,0);
    }
};
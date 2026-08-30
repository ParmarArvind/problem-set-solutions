class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int mini=0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[mini]) mini=i;

            if(nums[i]>nums[maxi]) maxi=i;
        }

        return min({ mini + 1 + n-maxi , n - min(mini,maxi),  maxi+1+n-mini , max(mini,maxi )+1 });
    }
};
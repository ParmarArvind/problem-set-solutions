class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=0;
        
        int second=0;
        for(int l=0;l<nums.size();l++)
        {
            if(nums[l]>first)
            {
                second=first;
                first=nums[l];
            }
            else if(nums[l]>second)
            {
                second=nums[l];
            }
        }

        return (second-1) *(first-1);

    }
};
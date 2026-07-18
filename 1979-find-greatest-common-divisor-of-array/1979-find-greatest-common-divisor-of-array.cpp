class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=nums[0];
        int largest=nums[0];
        for(auto num:nums)
        {
            smallest=min(num,smallest);
            largest=max(num, largest);
        }
        while(smallest)
        {
            int rem=largest%smallest;
            largest=smallest;
            smallest=rem;
        }
        return largest;
    }
};
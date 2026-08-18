class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k ) return *max_element(nums.begin() ,nums.end());
        int result = -1;

        
        if(k==1) {
            unordered_map<int,int>mp;
            for(auto num:nums) mp[num]++;

            for(auto &it:mp)
            {
                if(it.second==1) result=max(result,it.first);
            }

            return result;
        }
        bool isUnique1 =false ;
        bool isUnique2=false;
        for(int i=1;i<n-1;i++) 
        {
            if(nums[0]==nums[i] ) isUnique1=true;
            
            if(nums[n-1]==nums[i]) isUnique2=true;
        }
        if(!isUnique1) result=max(result,nums[0]);
        if(!isUnique2) result=max(result,nums[n-1]);
        
        if(nums[0]==nums[n-1] ) return -1;
        return result;

    }
};
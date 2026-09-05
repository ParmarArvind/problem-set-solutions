
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
           
            mp[nums[i]]++;
        }

        int maxEle=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxEle) maxEle=nums[i];

            auto it=mp.begin();
            int minEle=it->first;

            if(maxEle-minEle <=k) return i;

            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);

        }

        return -1;
    }
};

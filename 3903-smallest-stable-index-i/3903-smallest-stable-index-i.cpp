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

// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int n=nums.size();

//         for(int i=0;i<n;i++)
//         {
//             int maxEle=nums[i];
//             int minEle=nums[i];
//             for(int j=0;j<=i;j++)
//             {
//                 maxEle=max(maxEle,nums[j]);
//             }

//             for(int j=i;j<n;j++)
//             {
//                 minEle=min(minEle,nums[j]);
//             }

//             if(maxEle-minEle<=k) return i;
//         }
//         return -1;
//     }
// };
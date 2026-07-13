class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq; // max heap
        unordered_map<int,int>mp;
        int n=nums.size();
        
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
    
        int j=k;
        int i=0;
        vector<int>result(n-k+1);
        result[i]=pq.top();
        
        while(j<n)
        {
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            pq.push(nums[j]);
            mp[nums[j]]++;

            while(!pq.empty() && mp.find(pq.top()) ==mp.end()) pq.pop();
            i++;
            j++;
            result[i]=pq.top();
        }
        return result;
    }
};
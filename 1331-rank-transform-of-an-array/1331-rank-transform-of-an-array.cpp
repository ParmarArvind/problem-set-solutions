class Solution {
public:
    // method -2  sorting 
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            int num=arr[i];

            int left=0;
            int right=temp.size()-1;
            int idx=-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(temp[mid]==num) {
                    idx=mid;
                    right=mid-1;
                }
                else if(temp[mid]>num) right=mid-1;
                else left=mid+1;
            }

            result[i]=idx+1;
        }

        return result;
    }
};
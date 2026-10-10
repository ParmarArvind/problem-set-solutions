class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>arr(1e5+1 ,0);
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            arr[abs(nums1[i]-nums2[i])]++;
        }
        int k=k1+k2;

        
        for(int i=1e5;i>0;i--)
        {
            int count=arr[i];
            if(count==0) continue;

            if(k>= count) {
                arr[i-1] += count;
                k-=count;
                arr[i]=0;
            }
            else{
                arr[i-1] += k;
                arr[i] -=k;
                break;
            }
            
        }

        long long result=0;
        for(int i=0;i<1e5+1;i++)
        {
            result += 1LL * i*i*arr[i];
        }

        return result;
    }
};

//  method 1 (brute force -> TLE )
// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         priority_queue<int>pq;
//         int n=nums1.size();
//         for(int i=0;i<n;i++)
//         {
//             pq.push(abs(nums1[i]-nums2[i]));
//         }
//         long long result=0;
//         long long k=k1+k2;
//         while(k>0 && pq.top()>0)
//         {
//             int top=pq.top();
//             pq.pop();
//             top--;
//             k--;
//             pq.push(top);
//         }

//         while(!pq.empty())
//         {
//             result +=1LL*(pq.top() )* (pq.top());
//             pq.pop();
//         }

//         return result;
//     }
// };
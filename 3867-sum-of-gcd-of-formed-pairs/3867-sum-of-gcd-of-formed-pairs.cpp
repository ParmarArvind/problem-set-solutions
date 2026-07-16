class Solution {
public:
    // int gcd(int a,int b)
    // {
    //         while(a!=0)
    //         {
    //             int rem=b%a;
    //             b=a;
    //             a=rem;
    //         }
    //         return b;
    // }
    long long gcdSum(vector<int>& nums) {
        int maxEle=nums[0];
        int n=nums.size();
        vector<int>result(n);

        for(int i=0;i<n;i++)
        {
            maxEle =max(maxEle,nums[i]);

            result[i]=gcd(maxEle,nums[i]);
        }
        sort(result.begin(),result.end());
        long long  sum=0;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            sum+= (long long)gcd(result[j],result[i]);
            i++;
            j--;
        }
        return sum;

    }
};
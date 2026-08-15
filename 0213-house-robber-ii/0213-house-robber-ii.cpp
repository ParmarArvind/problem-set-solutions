class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if(n==3) return max({nums[0],nums[1],nums[2]}) ;

        int prevPrev=0;
        int prev=nums[0];
        

        for(int i=2;i<n;i++)
        {
            int steal=nums[i-1]+prevPrev;
            int skip=prev;
            
            prevPrev=prev;
            prev= max(steal, skip);
            
        }
        int result1=prev;

        prevPrev=0;
        prev=nums[1];
         for(int i=3;i<=n;i++)
        {
            int steal=nums[i-1]+prevPrev;
            int skip=prev;
            
            prevPrev=prev;
            prev= max(steal, skip);
            
        }
        int result2=prev;

        return max(result1,result2);
        
    }
 };



// // method 2 bottom up
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
//         if (n == 2) return max(nums[0], nums[1]);

//         vector<int> dp1(n + 1, 0); // case 1: from house 0 to n-2
//         dp1[0] = 0;
//         dp1[1] = nums[0];

//         for (int i = 2; i < n; i++) {  
//             int steal = nums[i - 1] + dp1[i - 2];
//             int skip = dp1[i - 1];
//             dp1[i] = max(skip, steal);
//         }
//         int first = dp1[n - 1]; // excludes last house

//         vector<int> dp2(n + 1, 0); // case 2: from house 1 to n-1
//         dp2[0] = 0;
//         dp2[1] = 0;
//         dp2[2] = nums[1];

//         for (int i = 3; i <= n; i++) {
//             int steal = nums[i - 1] + dp2[i - 2];
//             int skip = dp2[i - 1];
//             dp2[i] = max(skip, steal);
//         }
//         int second = dp2[n]; // includes last house, excludes first

//         return max(first, second);
//     }
// };


   
// // method 1 recusion + memotization (top down)
// class Solution {
// public:
 
//     int dp[101];

//     int solve(vector<int> &nums,int i,int n)
//     {   
//          if(i>n) return 0;

//         if(dp[i] != -1) return dp[i];

//         int steal=nums[i]+solve(nums,i+2,n);
//         int skip=solve(nums,i+1,n);

//         return dp[i]=max(steal,skip);
//     }

//     int rob(vector<int>& nums) {
//         int n= nums.size();

//         if(n==1) return nums[0];

//         if(n==2) return max(nums[0],nums[1]);
//         if(n == 3) return max({nums[0], nums[1], nums[2]});

//        memset(dp,-1,sizeof(dp));
//        int take_0th_house=solve(nums , 0 , n-2);

//         memset(dp,-1,sizeof(dp));
//         int take_1st_house=solve(nums , 1 , n-1);
        

//         return max(take_0th_house, take_1st_house);
        
//     }
// };

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>t(n+1);
        t[0]=0;

        for(int i=1;i<=n;i++)
        {
            if(i==1) t[i]=costs[i-1] + 1*1;

            else if(i==2)
                t[i]=min(costs[i-1] + 1*1 +t[i-1],
                         costs[i-1] + 2*2 +t[i-2]);

            else {
                t[i]=min({costs[i-1] + 1*1 +t[i-1],
                          costs[i-1] + 2*2 +t[i-2],
                          costs[i-1] + 3*3 +t[i-3]});
            }
        }

        return t[n];
    }
};
// class Solution {
// public:
//     int N;
//     int t[100001];
//     int solve(vector<int>&costs ,int i)
//     {
//         if(i>=N) return 0;
//         if(t[i]!=-1) return t[i];

//         return t[i]=min({costs[i]+1*1+solve(costs ,i+1) ,
//                     i+1<N ? costs[i+1]+2*2+solve(costs ,i+2) :INT_MAX,
//                     i+2<N ? costs[i+2]+3*3+solve(costs ,i+3) : INT_MAX});
//     }
    
//     int climbStairs(int n, vector<int>& costs) {
//         N=n;
//         memset(t,-1,sizeof(t));
//         return solve(costs,0);
//     }
// };
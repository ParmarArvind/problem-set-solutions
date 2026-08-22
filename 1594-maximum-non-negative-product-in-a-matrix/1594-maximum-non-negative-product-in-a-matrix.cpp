// method 2 bottom up
class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<ll ,ll>>>t( m, vector<pair<ll ,ll>>(n));
        t[0][0]={grid[0][0] ,grid[0][0]};
        
        for(int i=1;i<m;i++) t[i][0]= { t[i-1][0].first*grid[i][0] ,t[i-1][0].second*grid[i][0]};
        for(int j=1;j<n;j++) t[0][j]= { t[0][j-1].first*grid[0][j] ,t[0][j-1].second*grid[0][j]};

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                ll upMax=t[i-1][j].first*grid[i][j];
                ll upMin=t[i-1][j].second*grid[i][j];

                ll leftMax=t[i][j-1].first*grid[i][j];
                ll leftMin=t[i][j-1].second*grid[i][j];

                t[i][j].first =max({upMax ,upMin ,leftMax ,leftMin});
                t[i][j].second =min({upMax ,upMin ,leftMax ,leftMin});

            }
        }


        return t[m-1][n-1].first < 0 ? -1 : t[m-1][n-1].first % MOD ;
    }
};


// // method 1
// class Solution {
// public:

//     int m , n ;
//     typedef long long ll;
//     int MOD=1e9+7;
//     pair<ll ,ll> solve(vector<vector<int>>& grid ,vector<vector<pair<ll ,ll>>>& t ,int i,int j)
//     {
//         if(i==m-1 && j==n-1) return  {grid[i][j] ,grid[i][j]};

//         if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX )) return t[i][j];

//         ll maxVal =LLONG_MIN;
//         ll minVal=LLONG_MAX;

//         if(i+1 <m)
//         {
//             auto [downMax ,downMin] =solve(grid ,t, i+1 ,j);
//             maxVal =max({maxVal,downMax*grid[i][j],downMin*grid[i][j]});
//             minVal =min({minVal ,downMax*grid[i][j],downMin*grid[i][j]});
//         }

//         if(j+1 <n)
//         {
//             auto [rightMax ,rightMin] =solve(grid ,t, i,j+1);
//             maxVal =max({maxVal,rightMax*grid[i][j],rightMin*grid[i][j]});
//             minVal =min({minVal ,rightMax*grid[i][j],rightMin*grid[i][j]});
//         }

//         return t[i][j] ={maxVal ,minVal};
//     }
//     int maxProductPath(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         vector<vector<pair<ll ,ll>>>t( m, vector<pair<ll ,ll>>(n,{LLONG_MIN ,LLONG_MAX}));

//         auto [maxVal ,minVal] =solve(grid,t,0,0);

//         return maxVal<0 ? -1 : maxVal % MOD ;
//     }
// };
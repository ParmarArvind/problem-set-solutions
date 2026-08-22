class Solution {
public:

    int m , n ;
    typedef long long ll;
    int MOD=1e9+7;
    pair<ll ,ll> solve(vector<vector<int>>& grid ,vector<vector<pair<ll ,ll>>>& t ,int i,int j)
    {
        if(i==m-1 && j==n-1) return  {grid[i][j] ,grid[i][j]};

        if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX )) return t[i][j];

        ll maxVal =LLONG_MIN;
        ll minVal=LLONG_MAX;

        if(i+1 <m)
        {
            auto [downMax ,downMin] =solve(grid ,t, i+1 ,j);
            maxVal =max({maxVal,downMax*grid[i][j],downMin*grid[i][j]});
            minVal =min({minVal ,downMax*grid[i][j],downMin*grid[i][j]});
        }

        if(j+1 <n)
        {
            auto [rightMax ,rightMin] =solve(grid ,t, i,j+1);
            maxVal =max({maxVal,rightMax*grid[i][j],rightMin*grid[i][j]});
            minVal =min({minVal ,rightMax*grid[i][j],rightMin*grid[i][j]});
        }

        return t[i][j] ={maxVal ,minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<pair<ll ,ll>>>t( m, vector<pair<ll ,ll>>(n,{LLONG_MIN ,LLONG_MAX}));

        auto [maxVal ,minVal] =solve(grid,t,0,0);

        return maxVal<0 ? -1 : maxVal % MOD ;
    }
};
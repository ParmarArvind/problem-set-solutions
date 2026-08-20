// method -1  dijkstra 
class Solution {
public:
    vector<vector<int>>directions{{1,0} ,{0,1} ,{0,-1},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        priority_queue<
            pair<int,pair<int,int>> ,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});

        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        while(!pq.empty())
        {
            int d=pq.top().first;
            auto p=pq.top().second;
            int i=p.first;
            int j=p.second;
            pq.pop();
            for(auto &dir:directions)
            {
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n)
                {
                    int wt=grid[ni][nj];
                    if(d+wt<cost[ni][nj])
                    {
                        cost[ni][nj]=d+wt;
                        pq.push({d+wt , {ni,nj}});
                    }
                }
            }

        }

        return cost[m-1][n-1]>=health? false : true;
    }
};
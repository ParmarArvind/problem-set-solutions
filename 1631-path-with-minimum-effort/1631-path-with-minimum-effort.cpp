class Solution {
public:
    vector<vector<int>>directions={{0,1} ,{1,0},{0,-1} ,{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
       
        priority_queue<pair<int,pair<int,int>> ,
            vector<pair<int,pair<int,int>>> ,
            greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty())
        {
            int prevDiff=pq.top().first;
            pair<int,int>p=pq.top().second;
            pq.pop();

            int i=p.first;
            int j=p.second;

            for(auto &dir:directions)
            {
                int ni=i+dir[0];
                int nj=j+dir[1];
                
                if(ni>=0 && ni<n && nj>=0 && nj<m )
                {
                    int diff =max(prevDiff,abs(heights[i][j]-heights[ni][nj]));

                    if(diff<result[ni][nj])
                    {
                        pq.push({diff,{ni,nj}});
                        result[ni][nj]=diff;
                    }
                   
                }
            }
        }

        return result[n-1][m-1];

    }
};
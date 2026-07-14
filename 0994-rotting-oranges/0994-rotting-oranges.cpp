class Solution {
public:
    vector<vector<int>> directions{{1,0},{0,1}, {-1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q; 
        int freshCount=0;
        for(int i=0; i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] ==2) 
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1) 
                {
                    freshCount++;
                }
            }
        }

        int minutes=0;
        if(freshCount==0) return minutes;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int ,int> curr=q.front();
                q.pop();
                
                int i=curr.first;
                int j=curr.second;
                for(auto & dir:directions)
                {
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i >=0 && new_i<m && new_j >=0 && new_j <n && grid[new_i][new_j] == 1)
                    {
                        q.push({new_i,new_j});
                        grid[new_i][new_j]=2;
                        freshCount--;
                    }
                }
            }
            minutes++;
        }

        return freshCount==0 ? minutes-1 : -1;
    }
};
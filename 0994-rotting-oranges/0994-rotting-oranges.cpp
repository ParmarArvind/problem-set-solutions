// multi source BFS TC=n*m  SC=n*m
class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges=0;
        
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>que;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) freshOranges++;
                else if(grid[i][j]==2)
                {
                    que.push({i,j});
                }
            }
        }

        if(freshOranges==0) return 0;
    
        int time=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto [i ,j ]=que.front();
                que.pop();

                for(auto &dir:directions)
                {
                    int ni= i+dir[0];
                    int nj= j+dir[1];

                    if(ni >=0 && ni<m && nj >=0 && nj<n && grid[ni][nj]==1)
                    {
                        que.push({ni,nj});
                        grid[ni][nj]=2;
                        freshOranges--;
                    }
                }
            }
            time++;
        }

        return freshOranges==0 ? time-1 : -1;
    }
};






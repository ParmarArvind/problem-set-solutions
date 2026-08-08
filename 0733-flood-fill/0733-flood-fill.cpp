class Solution {
public: 
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

       queue<pair<int,int>>que;
       que.push({sr,sc});

       while(!que.empty())
       {
            auto [i,j]=que.front();
            que.pop();
            if(image[i][j]==-1) continue;
            for(auto &dir:directions)
            {
                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && image[new_i][new_j]==image[i][j] ) 
                {
                    que.push({new_i,new_j});
                }
            }

            image[i][j]=-1;
       }

       for(int i=0;i<m;i++)
       {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]==-1) image[i][j]=color;
            }
       }
       return image;
    }
};
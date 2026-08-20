class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1} ,{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<vector<int>>que;
        for(int i=0;i<m;i++)
        {   
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1) 
                {
                    que.push({0,i,j});
                    result[i][j]=0;
                }
            }
        }

        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto &vec=que.front();
                int val=vec[0] ,i=vec[1] ,j=vec[2];
                que.pop();
                for(auto &dir:directions)
                {
                    int ni=i+dir[0];
                    int nj=j+dir[1];

                    if(ni >=0 && nj>=0 && ni<m && nj<n && result[ni][nj]==-1)
                    {
                        que.push({val+1,ni ,nj});
                        result[ni][nj]=val+1;
                    }
                }
            }
        }

        return result;
    }
};



// class Solution {
// public:
// // mutiSource BFS
//     vector<vector<int>> directions{{1,0},{0,1}, {-1,0},{0,-1}};
    
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         int m=isWater.size();
//         int n=isWater[0].size();

//         vector<vector<int>> grid(m,vector<int>(n,0));
//         queue<pair<int,int>>q;
//         for(int i=0; i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(isWater[i][j] ==1) 
//                 {
//                     q.push({i,j});
//                     grid[i][j]=0;
//                 }
//             }
//         }

//         int height=1;
//         while(!q.empty())
//         {
//             int size=q.size();
//             while(size--)
//             {
//                 pair<int ,int> curr=q.front();
//                 q.pop();
                
//                 int i=curr.first;
//                 int j=curr.second;
//                 for(auto & dir:directions)
//                 {
//                     int new_i=i+dir[0];
//                     int new_j=j+dir[1];

//                     if(new_i >=0 && new_i<m && new_j >=0 && new_j <n && isWater[new_i][new_j] ==0 )
//                     {
//                         q.push({new_i,new_j});
//                         isWater[new_i][new_j]=1;
//                         grid[new_i][new_j]=height;
//                     }
//                 }
//             }
//             height++;
//         }

//         return grid;
//     }
// };
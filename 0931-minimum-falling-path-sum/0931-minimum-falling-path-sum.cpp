class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>>t(m,vector<int>(n));

        // fill the last row
        for(int j=0;j<n;j++) t[m-1][j]=mat[n-1][j];

        for(int i=m-2;i>=0 ;i--)
        {
            for(int j=n-1;j>=0 ;j--)
            {
                int rightDia = j==n-1 ? 1e7 :t[i+1][j+1] ;
                int down   = t[i+1][j] ;
                int leftDia =j==0 ? 1e7 : t[i+1][j-1];

                t[i][j]=mat[i][j] +min({rightDia ,down ,leftDia});
            }
        }

        int result=INT_MAX;
        for(int j=0;j<n;j++) result = min(result ,t[0][j]);

        return result;
    }
};
// // method 1 recu +memo 
// class Solution {
// public:
//     int m ,n;
//     int t[101][101];
//     int solve(vector<vector<int>>& matrix ,int i,int j)
//     {
//         if( i==m-1 ) return matrix[i][j];

//         if(t[i][j] != INT_MAX) return t[i][j];

//         int rightDia=j+1 >=n ? 1e7 : matrix[i][j]+solve(matrix,i+1,j+1);
//         int down=matrix[i][j]+ solve(matrix ,i+1 ,j);
//         int leftDia = j-1 <0 ? 1e7 : matrix[i][j]+solve(matrix,i+1,j-1);

//         return t[i][j]=min({rightDia ,down ,leftDia});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         m=matrix.size();
//         n=matrix[0].size();
        
//         for (int i = 0; i < 101; i++)
//             for (int j = 0; j < 101; j++)
//                 t[i][j] = INT_MAX;

//         int result=INT_MAX;
//         for(int j=0;j<n;j++)
//         {
//             result=min(result ,solve(matrix,0,j));
//         }
//         return result;
//     }
// };
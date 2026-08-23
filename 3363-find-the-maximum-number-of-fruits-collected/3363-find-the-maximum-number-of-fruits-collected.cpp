class Solution {
public:
    int n;
    int t[1001][1001];
    int solveChild1(vector<vector<int>>& fruits ,int i)
    {
        int ans=0;
        while(i<n)
        {
            ans+= fruits[i][i];
            i++;
        }
        return ans;
    }

    int solveChild2(vector<vector<int>>& fruits ,int i ,int j)
    {
        if(i>=n || j>= n || j<0) return 0;

        // already collect by child 1
        if(i==j || i> j) return 0;

        // if(i==n-1 && j==n-1) return 0; // already collect by child 1 (no need)
        
        if(t[i][j] != -1) return t[i][j];

        int bottomLeft=solveChild2(fruits, i+1,j-1);
        int bottomRight=solveChild2(fruits, i+1,j+1);
        int bottomDown=solveChild2(fruits, i+1,j);

        return t[i][j]= fruits[i][j]+max({bottomLeft, bottomRight , bottomDown });
    }

    int solveChild3(vector<vector<int>>& fruits ,int i ,int j)
    {
        if(i<0 || i>=n || j>= n ) return 0;

        // already collect by child 1 
        if(i==j || i < j) return 0;

        // if(i==n-1 && j==n-1) return 0; // already collect by child 1 (no need)

        if(t[i][j] != -1) return t[i][j];
        
        int upRight=solveChild3(fruits, i-1 , j+1);
        int Right=solveChild3(fruits, i,j+1);
        int bottomRight=solveChild3(fruits, i+1,j+1);

        return t[i][j]= fruits[i][j]+max({upRight, Right , bottomRight });
    }


    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        memset(t,-1,sizeof(t));

        int c1=solveChild1(fruits ,0);
        int c2=solveChild2(fruits,0,n-1);
        int c3=solveChild3(fruits,n-1,0);
        
        return c1+c2+c3;
    }
};
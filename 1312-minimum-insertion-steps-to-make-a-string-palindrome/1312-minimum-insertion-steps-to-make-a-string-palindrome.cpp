class Solution {
public:
    int n;
    int t[501][501];
    int solve(string &s1,string &s2,int i,int j)
    {
        if(i==n || j==n) return 0;

        if(t[i][j] !=-1) return t[i][j];

        if(s1[i]== s2[j]) return t[i][j]=1+solve(s1,s2,i+1,j+1);

        return t[i][j]=max(solve(s1,s2,i+1,j) ,solve(s1,s2,i,j+1));

    }
    int LCS(string & s1,string &s2)
    {
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
    int LPS(string &s1)
    {
        string s2;
        for(int i=n-1;i>=0;i--)
        {
            s2.push_back(s1[i]);
        }
        return LCS(s1,s2);
    }
    int minInsertions(string s) {
        n=s.size();
        return n-LPS(s);
    }
};
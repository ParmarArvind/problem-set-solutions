// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         return true;
//     }
// };


class Solution {
public:
    int t[501][501];
    int solve(vector<int>&piles,int i,int j)
    {
        if(i>j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int takeI=piles[i] + min(solve(piles, i+2,j) , solve(piles,i+1,j-1));
        int takeJ=piles[j] + min(solve(piles, i,j-2) , solve(piles,i+1,j-1));

        return t[i][j]=max(takeI, takeJ);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin() ,piles.end(),0);
        memset(t,-1,sizeof(t));
        int aliceScore=solve(piles,0,n-1);
        return aliceScore>sum/2;
    }
};
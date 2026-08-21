
// method -2  recursion and memo TC=O(n^2)
class Solution {
public:
    int n;
    int dp[1001][1001];
    bool isPalindrome(string & s ,int i ,int j)
    {
        if(i>=j) return true;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] != s[j] )  return dp[i][j]=false;

        return dp[i][j]=isPalindrome(s,i+1 ,j-1);
    }
    int countSubstrings(string s) {
        n=s.size();
        int count=0;
        memset(dp ,-1, sizeof(dp));

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j)) count++;
            }
        }

        return count;
    }
};



// // method -1 brute force  TC=O(n^3)
// class Solution {
// public:
//     int n;
//     bool isPalindrome(string & s ,int i ,int j)
//     {
//         while(i<=j)
//         {
//             if(s[i] != s[j]) return false; 
//             i++ , j--;
//         }
//         return true;
//     }
//     int countSubstrings(string s) {
//         n=s.size();
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 if(isPalindrome(s,i,j)) count++;
//             }
//         }

//         return count;
//     }
// };
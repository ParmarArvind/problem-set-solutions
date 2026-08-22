// method -4 tc=O(n^2) sc=o(1)
class Solution {
public:
    int n;
    int check(int i,int j,string &s)
    {
        int count=0;
        while(i>=0 && j<n && s[i]==s[j])
        {
            count++;
            i-- , j++;
        }

        return count;
    }
    int countSubstrings(string s) {
        n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            count += check(i,i,s);// take ith char as mid and make a odd length palindrome substring
            count += check(i,i+1,s); // take ith and (i+1 )th char as mid and make a even length palindrome substring
            
        }

        return count;
    }
};

// /// method -3 bottom up  tc=O(n^2) ,sc=O(n^2)
// class Solution { 
// public:
//     int countSubstrings(string s) {
//         int n=s.size();
//         vector<vector<bool>>dp(n,vector<bool>(n,false));
//         //state dp[i][j] =true ->s[i:j] is palindroome sustring both i and j inclusive

//         int count=0;
//         for(int L=1;L<=n;L++)
//         {
//             for(int i=0; L+i-1 < n ;i++)
//             {
//                 int j=L+i-1;
//                 if(i==j) dp[i][j]=true;
//                 else if (i+1==j) 
//                 {
//                     dp[i][j]= (s[i]==s[j]);
//                 }
//                 else {
//                     dp[i][j]=(dp[i+1][j-1] && s[i]==s[j]);
//                 }

//                 // count increace if current substring is palindrome
//                 if(dp[i][j]==true) count++;
//             }
//         }

//         return count;
//     }
// };



// // method -2  recursion and memo TC=O(n^2)
// class Solution {
// public:
//     int n;
//     int dp[1001][1001];
//     bool isPalindrome(string & s ,int i ,int j)
//     {
//         if(i>=j) return true;
        
//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] != s[j] )  return dp[i][j]=false;

//         return dp[i][j]=isPalindrome(s,i+1 ,j-1);
//     }
//     int countSubstrings(string s) {
//         n=s.size();
//         int count=0;
//         memset(dp ,-1, sizeof(dp));

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
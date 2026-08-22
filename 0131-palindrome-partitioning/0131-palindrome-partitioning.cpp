// back-tracking + dp Time Complexity = O(n * 2^n)
class Solution {
public:
    
    void solve(string &s,vector<vector<bool>>& dp ,vector<vector<string>>&result,vector<string>&temp,int idx)
    {
        if(idx== s.size())
        {
            result.push_back(temp);
            return ;
        }

        for(int i=idx;i<s.size();i++)
        {
            if(dp[idx][i])
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,dp,result,temp,i+1);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n=s.size();

        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;

        for(int L=2;L<=n;L++)
        {
            for(int i=0;i+L-1<n ;i++)
            {
                int j=i+L-1;
                if(s[i]==s[j])
                {
                    if(L==2) dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }


        vector<vector<string>>result;
        vector<string>temp;
        solve(s,dp,result,temp,0);

        return result;
    }
};




// // back-tracking  Time Complexity = O(n * 2^n)
// class Solution {
// public:
//     bool isPalindrome(string & s ,int i,int j)
//     {
//         while(i<=j)
//         {
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }

//         return true;
//     }
//     void solve(string &s,vector<vector<string>>&result,vector<string>&temp,int idx)
//     {
//         if(idx== s.size())
//         {
//             result.push_back(temp);
//             return ;
//         }

//         for(int i=idx;i<s.size();i++)
//         {
//             if(isPalindrome(s,idx,i))
//             {
//                 temp.push_back(s.substr(idx,i-idx+1));
//                 solve(s,result,temp,i+1);
//                 temp.pop_back();
//             }
//         }

//     }
//     vector<vector<string>> partition(string s) {
//         int n=s.size();
//         vector<vector<string>>result;
//         vector<string>temp;
//         solve(s,result,temp,0);

//         return result;
//     }
// };


//    // wrong method 
// class Solution {
// public:
//     bool check(int i,int j,string& s)
//     {
//         while(i<=j)
//         {
//             if(s[i]!=s[j]) return false;
//             i++ ,j--;
//         }
//         return true;
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> result;
//         int n=s.size();

//         for(int L=1;L<=n;L++)
//         {
//             vector<string>temp1;
//             bool isAll=true;
//             int i;
//             for(i=0; i+L-1<n ; i+=L)
//             {
//                 int j=i+L-1;
//                 if(check(i,j,s)==false)
//                 {
//                     isAll=false;
//                     break;
//                 }
//                 temp1.push_back(s.substr(i,L));
//             }

//             if(i<n) {
//                 if(check(i,n-1,s)==false)
//                 {
//                     isAll=false;
//                 }
//                 else {
//                     temp1.push_back(s.substr(i,n-i));
//                 }
//             }


//             if(isAll)
//             {
//                 result.push_back(temp1);
//             }



//             vector<string>temp2;
//             isAll=true;
//            i;
//             for(i=n-1; i-L+1>=0 ; i-=L)
//             {
//                 int j=i-L+1;
//                 if(check(j,i,s)==false)
//                 {
//                     isAll=false;
//                     break;
//                 }
//                 temp2.push_back(s.substr(j,L));
//             }

//             if(i>=0) {
//                 if(check(i,0,s)==false)
//                 {
//                     isAll=false;
//                 }
//                 else {
//                     temp2.push_back(s.substr(0,i+1));
//                 }
//             }

//             if(isAll)
//             {
//                 reverse(temp2.begin() ,temp2.end());
//                 if(result.back() == temp2) continue;
//                 result.push_back(temp2);
//             }
//         }

//         return result;
//     }
// };
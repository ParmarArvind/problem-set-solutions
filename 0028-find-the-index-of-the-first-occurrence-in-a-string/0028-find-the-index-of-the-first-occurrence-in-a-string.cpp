
class Solution {
  public:
    void findLPS(string &needle  ,vector<int>&lps)
    {
        int m=needle .size();
        int left=0;
        int right=1;
        while(right<m)
        {
            if(needle [left]==needle [right])
            {
                lps[right]=left+1;
                right++;
                left++;
            }
            else{
                if(left==0) right++;
                else {
                    left=lps[left-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle ) {
        // code here
        int n=haystack.size();
        int m=needle .size();
        
        vector<int>lps(m,0);
        findLPS(needle ,lps);
        
        int first=0;
        int second=0;
        
        while(first<n )
        {
            if(haystack[first]==needle [second])
            {
                second++;
                first++;
            }
            else{
                if(second==0) first++;
                else  second=lps[second-1];
            }
            
            if(second==m)
            {
                return first-second;
            }
        }
        
        return -1;
    }
};

// class Solution {
// public:
//     int strStr(string haystack, string needle) {


//         int n=haystack.size();
//         int m=needle.size();
//         if(m>n) return -1;

//         for(int i=0;i<=n-m;i++)
//         {
//             int k=i;
//             bool isOkay=true;
//             for(int j=0;j<m;j++)
//             {
//                 if(haystack[k]!=needle[j])
//                 {
//                     isOkay=false;
//                     break;
//                 }
//                 k++;
//             }
//             if(isOkay) return i;
//         }

//         return -1;
//     }
// };
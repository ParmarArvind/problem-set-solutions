class Solution {
public:
    int strStr(string haystack, string needle) {


        int n=haystack.size();
        int m=needle.size();
        if(m>n) return -1;

        for(int i=0;i<=n-m;i++)
        {
            int k=i;
            bool isOkay=true;
            for(int j=0;j<m;j++)
            {
                if(haystack[k]!=needle[j])
                {
                    isOkay=false;
                    break;
                }
                k++;
            }
            if(isOkay) return i;
        }

        return -1;
    }
};
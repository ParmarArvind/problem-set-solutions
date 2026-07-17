class Solution {
public:
    void findLPS(string  &s,vector<int>&lps)
    {
        int pre=0;
        int suff=1;
        while(suff<s.size())
        {
            //matched
            if(s[pre]==s[suff])
            {
                lps[suff]=pre+1;
                suff++;
                pre++;
            }
        
        // not matched
            else 
            {
                if(pre==0)
                {
                    lps[suff]=0;
                    suff++;
                }
                else pre=lps[pre-1];
            }
        }
    }
     bool KMP(string &a, string &b)
     {
        vector<int>lps(b.size(),0);
        findLPS(b,lps);
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]==b[j])
            {
                i++ , j++;
            }
            else 
            {
                if(j==0) i++;
                else j=lps[j-1];
            }
        }

        if(j==b.size()) return true;
        return false;
     }
    int repeatedStringMatch(string a, string b) {
       if(a==b) return 1;
       
       int repeat=1;
       string temp=a;
       while(temp.size()<b.size())
       {
        temp+=a;
        repeat++;
       }

       // temp and b per KMP pattern serach
        if(KMP(temp, b)) return repeat;
        // temp+a and b per KMP pattern serach
        temp+=a;
        if(KMP( temp,b)) return repeat+1;

        // not possible
        return -1;

    }
};
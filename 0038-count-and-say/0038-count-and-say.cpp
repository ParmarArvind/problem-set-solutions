class Solution {
public:
    void RLE(int i,int n,string &curr)
    {
        if(i>n) return ;
        string result;
        int m=curr.size();
        int count=1;
        int j=0;
        while(j<m-1)
        {
            if(curr[j]==curr[j+1]) count++;
            else{
                result.push_back(char(count+'0'));
                result.push_back(curr[j]);
                count=1;
            }
            j++;
        }
        if(curr[m-1]!=curr[m-2])
        {
            result.push_back('1');
            result.push_back(curr[m-1]);
        }
        else {
            result.push_back(char(count+'0'));
            result.push_back(curr[m-1]);
        }

        curr=result;
        RLE(i+1,n,curr);

    }
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string curr="11";
        RLE(3,n,curr);
        return curr;
    }
};
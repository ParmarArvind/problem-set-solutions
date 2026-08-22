class Solution {
public:
    bool isPalindrome(string & s ,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void solve(string &s,vector<vector<string>>&result,vector<string>&temp,int idx)
    {
        if(idx== s.size())
        {
            result.push_back(temp);
            return ;
        }

        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,result,temp,i+1);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>result;
        vector<string>temp;
        solve(s,result,temp,0);

        return result;
    }
};
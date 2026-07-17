class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result=strs[0];
        int m=strs.size();

        for(int i=1;i<m;i++)
        {
            int n=min(strs[i].size() , result.size());
            for(int j=0;j<n;j++)
            {
                if(strs[i][j] != result[j])
                {
                    result=strs[i].substr(0, j);
                    break;
                }
            }
            if(result.size()> n ) result=strs[i].substr(0, n);
        }

        return result;
    }
};
class Solution {
public:
    string smallestSubsequence(string s) {
       
        int n = s.size();
        vector<int>lastIdx(26);
        vector<bool>visited(26,false);
        for (int i = 0; i < n; i++)
        {
           lastIdx[s[i]-'a']=i;
        }

        string result;
        int i=0;

        while (i < n)
        {
            if(visited[s[i]-'a']) {
                i++;
                continue;
            }

            while(!result.empty() && result.back()>s[i] && lastIdx[result.back()-'a'] >i) 
            {
                visited[result.back()-'a']=false;
                result.pop_back();
            }

            result.push_back(s[i]);
            visited[s[i]-'a']=true;
            i++;
        }

        return result;
    }
};
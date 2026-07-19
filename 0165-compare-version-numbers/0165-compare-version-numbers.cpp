class Solution {
public:
    // vector<string> getTokens(string version) {
    //     stringstream v(version);
    //     string token_v = "";
    //     vector<string> version_tokens;
    //     while(getline(v, token_v, '.')) {
    //         version_tokens.push_back(token_v);
    //     }
    //     return version_tokens;
    // }
    vector<string> getTokens(string &s)
    {
        vector<string>vec;
        string temp;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            if(s[i]=='.')
            {
                vec.push_back(temp);
                temp.clear();
            }else{
                temp.push_back(s[i]);
            }
            i++;
        }

        vec.push_back(temp);

        return vec;
    }
    int compareVersion(string version1, string version2) {
        vector<string>vec1= getTokens(version1);
        vector<string>vec2= getTokens(version2);

        int n=vec1.size();
        int m=vec2.size();
        int i=0;

        while(i<n || i<m)
        {
            int a=i<n ? stoi(vec1[i]) : 0;
            int b=i<m ? stoi(vec2[i]) : 0;

            if(a<b) return -1;
            if(a>b) return 1;
            i++;
        }

        return 0;
    }
};
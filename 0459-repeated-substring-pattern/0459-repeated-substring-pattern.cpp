class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 0; i <n/2; i++) {
             int m = i + 1;

            if (n % m != 0)
                continue;

            string sub = s.substr(0, m);

            string ans="";
            for (int j = 1; j <= n/m; j++)
                ans += sub;

            int j;
            for (j = 0; j < n; j++) {
                if (s[j] != ans[j]) {
                    break;
                }
            }
            // cout<<ans<<endl;
            if (j==n)
                return true;
        }

        return false;
    }
};
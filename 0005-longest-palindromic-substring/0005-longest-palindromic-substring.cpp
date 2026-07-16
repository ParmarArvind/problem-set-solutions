class Solution {
public:
    // O(n^2) time
    int t[1001][1001];
    bool isValid(int i, int j, string& s) {
        if (i >= j)
            return true;
        if (t[i][j] != -1)
            return t[i][j];
        if (s[i] == s[j]) {
            return t[i][j]=isValid(i + 1, j - 1, s);
        } else
            return false;
    }
    string longestPalindrome(string s) {
        string result;
        memset(t, -1, sizeof(t));

        for (int i = 0; i < s.size(); i++) {
            string temp;
            for (int j = i; j < s.size(); j++) {
                temp.push_back(s[j]);
                if (isValid(i, j, s)) {
                    if (result.size() < (j - i + 1))
                        result = temp;
                }
            }
        }
        return result;
    }
};
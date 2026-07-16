class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.size() - 1;

        while (i >= 0) {
           //skip space in front off string
            while (i >= 0 && s[i] == ' ') i--;
            
            if (i < 0) break; 

            string sub;
            while (i >= 0 && s[i] != ' ') {
                sub.push_back(s[i]);
                i--;
            }

            reverse(sub.begin(), sub.end());
            if (!ans.empty()) ans.push_back(' '); // Avoid adding leading space
            ans.append(sub);
        }

        return ans;
    }
};

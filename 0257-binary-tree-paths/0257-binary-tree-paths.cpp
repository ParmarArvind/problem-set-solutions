class Solution {
public:
    vector<string> result;
    void solve(TreeNode* root, string &curr)
    {
        if (!root) return;

        int len = curr.size();   // save length before change

        curr += to_string(root->val);

        if (!root->left && !root->right)
        {
            result.push_back(curr);
        }
        else
        {
            curr += "->";
            solve(root->left, curr);
            solve(root->right, curr);
        }

        curr.resize(len);   // backtracking
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        string curr = "";
        solve(root, curr);
        return result;
    }
};
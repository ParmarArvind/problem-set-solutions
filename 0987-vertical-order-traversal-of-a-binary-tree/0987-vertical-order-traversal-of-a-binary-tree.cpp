class Solution {
public:
    int left, right;

    void find(TreeNode* root, int index) {
        if (!root) return;

        left = min(left, index);
        right = max(right, index);

        find(root->left, index - 1);
        find(root->right, index + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        left = INT_MAX;
        right = INT_MIN;

        find(root, 0);

        int n = right - left + 1;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        vector<vector<int>> result(n);

        while (!que.empty()) {
            int size = que.size();

            // Stores this level only, so equal row/column values can be sorted.
            vector<vector<int>> level(n);

            while (size--) {
                auto [node, index] = que.front();
                que.pop();

                level[index - left].push_back(node->val);

                if (node->left) que.push({node->left, index - 1});
                if (node->right) que.push({node->right, index + 1});
            }

            for (int i = 0; i < n; i++) {
                sort(level[i].begin(), level[i].end());

                for(int j=0;j<level[i].size();j++)
                {
                    result[i].push_back(level[i][j]);
                }
            }
        }

        return result;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        int level=maxDepth(root);
        queue<TreeNode*>que;
        que.push(root);

        vector<vector<int>>result(level);
        int i=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto node=que.front();
                que.pop();
                result[i].push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            i++;
        }
        
        return result;
    }
};
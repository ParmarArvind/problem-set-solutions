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
    // method -2 morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>result;
        stack<pair<TreeNode* ,int>>st; // node, no_of_times_visited
        st.push({root,1});
        while(!st.empty())
        {
            auto [node,count]=st.top();
            st.pop();
            if(count==2) result.push_back(node->val);
            else {
                // first oush it right
                if(node->right) st.push({node->right,1});
                st.push({node,2});
                if(node->left) st.push({node->left,1});
            }
        }

        return result;
    }
};
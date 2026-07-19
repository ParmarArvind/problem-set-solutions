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
    // method -2 morris travesal
    vector<int> postorderTraversal(TreeNode* root) {

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
                
                st.push({node,count+1});

                if(node->right) st.push({node->right,1});

                if(node->left) st.push({node->left,1});

            }
        }
        return result;
    }
};

// class Solution {
// public:
// void postOrder(TreeNode* root, vector<int>& ans) {
//         if (!root) return; // Handle nullptr case

       
//         if (root->left) postOrder(root->left, ans);
        
//         if (root->right) postOrder(root->right, ans);

//          ans.push_back(root->val);

//     } 
//     vector<int> postorderTraversal(TreeNode* root) {
//          vector<int> ans;
//         postOrder(root, ans);
//         return ans;
        
//     }
// };
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
    // morris preorder
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            // No left child
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;

                while (pred->right != nullptr && pred->right != curr)
                    pred = pred->right;

                // First time visiting this node
                if (pred->right == nullptr) {
                    result.push_back(curr->val);   // Preorder: Root first
                    pred->right = curr;            // Create thread
                    curr = curr->left;
                }
                // Second time visiting
                else {
                    pred->right = nullptr;         // Remove thread
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     //method -2 iterative Preorder traversal
//     vector<int> preorderTraversal(TreeNode* root) {

//         if(!root) return {};

//         vector<int>result;
//         stack<TreeNode* >st; 
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode* node=st.top();
//             st.pop();
//             result.push_back(node->val);
               
//             if(node->right) st.push(node->right);
            
//             if(node->left) st.push(node->left);
        
//         }
//         return result;
//     }
// };

// method -1 recursive

// class Solution {
// public:
//     void preOrder(TreeNode* root ,vector<int>&result)
//     {
//         if(!root) return ;
        
//         result.push_back(root->val);

//         preOrder(root->left,result);
        
//         preOrder(root->right,result);

//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>result;
//         preOrder(root,result);
//         return result;
//     }
// };
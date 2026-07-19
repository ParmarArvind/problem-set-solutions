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
    // method -3 morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>result;
        TreeNode* curr=root;
        while(curr)
        {
            // we visited the left part so , print the curr 
           if(!curr->left )
           {
                result.push_back(curr->val);
                curr=curr->right;
           }
           else{
                TreeNode* leftChild=curr->left;
                while(leftChild->right) leftChild=leftChild->right;
                // make a path to come back at root 
                leftChild->right=curr;

                // now mark the curr left to null

                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=nullptr;
           }

        }

        return result;
    }
};


// class Solution {
// public:
//     // method -2 iterative inorder traversal
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root) return {};
//         vector<int>result;
//         stack<pair<TreeNode* ,int>>st; // node, no_of_times_visited
//         st.push({root,1});
//         while(!st.empty())
//         {
//             auto [node,count]=st.top();
//             st.pop();
//             if(count==2) result.push_back(node->val);
//             else {
//                 // first oush it right
//                 if(node->right) st.push({node->right,1});
//                 st.push({node,2});
//                 if(node->left) st.push({node->left,1});
//             }
//         }

//         return result;
//     }
// };


// class Solution {
// public:
//     void inorder(TreeNode* root ,vector<int>&result)
//     {
//         if(!root) return ;
//         inorder(root->left,result);
//         result.push_back(root->val);
//         inorder(root->right,result);

//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>result;
//         inorder(root,result);
//         return result;
//     }
// };
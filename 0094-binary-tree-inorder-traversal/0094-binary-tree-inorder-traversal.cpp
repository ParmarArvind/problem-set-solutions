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
    // method -2 iterative inorder traversal
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
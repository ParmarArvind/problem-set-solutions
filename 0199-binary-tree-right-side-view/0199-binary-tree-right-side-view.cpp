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
    void inorder(TreeNode * root ,vector<int>&result ,int i)
    {
        if(!root) return ;
        result[i]=root->val;
        inorder(root->left,result,i+1);
        inorder(root->right,result,i+1);

    }
    int findHeight(TreeNode* root)
    {
        if(!root) return 0;
        
        int left=findHeight(root->left);
        int right=findHeight(root->right);

        return 1+max(left,right);
    }
    vector<int> rightSideView(TreeNode* root) {
       
        int H=findHeight(root);
        vector<int>result(H);
        
        inorder(root,result,0);
        return result;
    }

};
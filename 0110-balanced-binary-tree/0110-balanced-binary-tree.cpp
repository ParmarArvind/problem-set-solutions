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
    int balanceFactor;
    int find(TreeNode* root)
    {
        if(!root) return 0;
       int left=find(root->left);
       int right=find(root->right);
       balanceFactor=max(balanceFactor,abs(left-right));
       if(balanceFactor>1) return 0;
       return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        balanceFactor=0;
        find(root);
        return balanceFactor >1 ? false : true;
    }
};
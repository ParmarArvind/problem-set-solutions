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
    void inorder(TreeNode* root,vector<int>&nums)
    {
        if(!root) return ;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        inorder(root,nums);
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            if((long long)(nums[i]+nums[j])==1LL*k) return true;
            else if((long long)(nums[i]+nums[j])>1LL*k) j--;
            else i++;
        }

        return false;
    }
};
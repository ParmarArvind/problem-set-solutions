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
    bool result;
    TreeNode* Root;

    bool isAvailable(TreeNode* root, long target)
    {
        if(!root) return false;

        if((long)root->val == target) return true;

        if((long)root->val < target) return isAvailable(root->right, target);
        
        return isAvailable(root->left, target);
    }

    void inorder(TreeNode* curr, int k)
    {
        if(!curr) return;
        if(result) return;

        inorder(curr->left, k);

        long need = (long)k - curr->val;
        if(curr->val != need && isAvailable(Root, need))
        {
            result = true;
            return;
        }

        inorder(curr->right, k);
    }

    bool findTarget(TreeNode* root, int k)
    {
        result = false;
        Root = root;

        inorder(root, k);

        return result;
    }
};

//  // method -1
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&nums)
//     {
//         if(!root) return ;
//         inorder(root->left,nums);
//         nums.push_back(root->val);
//         inorder(root->right,nums);
//     }
//     bool findTarget(TreeNode* root, int k) {
//         vector<int>nums;
//         inorder(root,nums);
//         int i=0;
//         int j=nums.size()-1;
//         while(i<j)
//         {
//             if((long long)(nums[i]+nums[j])==1LL*k) return true;
//             else if((long long)(nums[i]+nums[j])>1LL*k) j--;
//             else i++;
//         }
//
//         return false;
//     }
// };
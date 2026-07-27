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
    TreeNode* solveFlatten(TreeNode* root)
    {
        if(!root) return nullptr;
        
        TreeNode* left=solveFlatten(root->left);
        root->left=nullptr;

        TreeNode* right=solveFlatten(root->right);
        root->right=left;

        TreeNode* temp=root;
        while(temp->right)
        {
            temp=temp->right;
        }
        temp->right=right;
        return root;
    }
    void flatten(TreeNode* root) {
        root=solveFlatten(root);

    }
};


//  //method -1 using preorder 
// class Solution {
// public:
//     void Preorder(TreeNode* root,vector<int>&result)
//     {
//         if(root==nullptr) return;
//         result.push_back(root->val);
//         Preorder(root->left,result);
//         Preorder(root->right,result);

//     }
//     void flatten(TreeNode* root) {
//         if(!root) return ;
//         vector<int>result;
//         Preorder(root,result);

//         int n=result.size();
//         root->val=result[0];
//         TreeNode* temp=root;
//         for(int i=1;i<n;i++)
//         {
//             TreeNode* newNode=new TreeNode(result[i]);
//             temp->right=newNode;
//             temp->left=nullptr;
//             temp=temp->right;
//         }
//     }
// };
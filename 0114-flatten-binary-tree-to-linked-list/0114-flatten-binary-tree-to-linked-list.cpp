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
 // method -2 
class Solution {
public:
    TreeNode* nextRight=NULL;
    void flatten(TreeNode* root) {
        if(!root) return ;
        flatten(root->right);
        flatten(root->left);

        root->left=nullptr;
        root->right=nextRight;
        nextRight=root;
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
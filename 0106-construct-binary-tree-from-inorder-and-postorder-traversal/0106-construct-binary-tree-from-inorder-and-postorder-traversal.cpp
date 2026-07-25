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
    int n;
    TreeNode* makeTree(vector<int>& postorder ,unordered_map<int,int> &mp ,int &postIdx ,int i,int j)
    {
        
        if(i>j)
        {
            return nullptr;
        }
        int idx=mp[postorder[postIdx]];

        TreeNode* root=new TreeNode(postorder[postIdx]);

        postIdx++;
        // builde right first 
        root->right = makeTree(postorder, mp, postIdx, idx+1, j);
        //then left
        root->left  = makeTree(postorder, mp, postIdx, i, idx-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=inorder.size();
        // reverse the postOrder 
        reverse(postorder.begin() ,postorder.end());

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int postIdx=0;
        return makeTree(postorder , mp , postIdx ,0 ,n-1);
    }
};
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
    TreeNode* makeTree(vector<int>& preorder ,int left,int right)
    {
        if(left>right) return NULL;

        TreeNode* root=new TreeNode(preorder[left]);

        int partionPoint=-1;
        
        int rootVal=root->val;
        int i=left+1 , j =right;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(preorder[mid]<rootVal)
            {
                i=mid+1;
                partionPoint=mid;
            }else j=mid-1;
        }

        if(partionPoint != -1 ){
            root->left=makeTree(preorder,left+1,partionPoint);
            root->right=makeTree(preorder,partionPoint+1,right);
        }
        else root->right=makeTree(preorder,left+1,right);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeTree(preorder,0,preorder.size()-1);
    }
};
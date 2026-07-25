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

 //clearner code 
 class Solution {
public:
    int result;

    int solve(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        result = max(result, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        result = INT_MIN;

        solve(root);

        return result;
    }
};


// class Solution {
// public:
//     int result;
//     int solve(TreeNode* root)
//     {
        
//         int left=INT_MIN;
//         if(root->left) left=solve(root->left);

//         int right=INT_MIN;
//         if(root->right) right=solve(root->right);


//         result=max({result , root->val, 
//                     root->val +(right==INT_MIN? 0: right),
//                     root->val +(left==INT_MIN? 0: left ),
//                     root->val +(right==INT_MIN? 0: right) + (left==INT_MIN? 0: left)
//                     });


//         return max({ root->val ,
//                     root->val +(right==INT_MIN? 0: right),
//                     root->val +(left==INT_MIN? 0: left )
//                     });
//     }


//     int maxPathSum(TreeNode* root) {
//       result=INT_MIN;

//        solve(root);
//        return result;
//     }
// };
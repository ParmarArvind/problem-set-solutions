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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,ll>>que;
        que.push({root,0});
        ll result=0;
        while(!que.empty())
        {
            int size=que.size();
            ll  left=que.front().second;
            ll  right=que.back().second;
            if(result<right-left+1) result=right-left+1;
            while(size--)
            {
                auto [node ,index]=que.front();
                que.pop();

                if(node->left)
                {
                    que.push({node->left,2*index+1});
                }
                if(node->right)
                {
                    que.push({node->right,2*index+2});
                }
            }
            
        }

        return result;
    }
};
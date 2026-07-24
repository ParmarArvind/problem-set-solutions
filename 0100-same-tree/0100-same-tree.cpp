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

 //method -2 BFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q ) return true;
        if( (!p && q ) || (p && !q) ) return false;

        queue<pair<TreeNode*,TreeNode*>>que;
        que.push({p,q});

        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto [a,b]=que.front();
                que.pop();
                if(a->val != b->val) return false;
                if(a->left && b->left) 
                {
                    que.push({a->left ,b->left});
                }
                else if(a->left || b->left) return false;

                if(a->right && b->right) 
                {
                    que.push({a->right ,b->right});
                }
                else if(a->right || b->right)  return false;
            }
        }

        return true;
    }
};

//method -1 dfs traversal
// class Solution {
// public:

//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p && !q) return true;
//         if(p && q) 
//         {
//             if(p->val==q->val) return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
//             else return false;
//         }
//         return false;
//     }
// };
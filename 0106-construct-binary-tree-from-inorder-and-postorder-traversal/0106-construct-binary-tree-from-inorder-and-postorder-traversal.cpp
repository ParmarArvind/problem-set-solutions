class Solution {
public:

    TreeNode* makeTree(vector<int>& postorder,unordered_map<int, int>& mp,int& postIdx,int left ,int right)
    {
        if (left > right)
            return nullptr;

        int rootVal = postorder[postIdx];
        postIdx--;
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        // Build right subtree first
        root->right = makeTree(postorder, mp, postIdx, mid + 1, right);

        // Then build left subtree
        root->left = makeTree(postorder, mp, postIdx, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int postIdx = postorder.size() - 1;

        return makeTree(postorder, mp, postIdx, 0, inorder.size() - 1);
    }
};
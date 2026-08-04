class Solution {
public:
    int result ;

    tuple<int, bool, int, int> solve(TreeNode* root) {
        // sum, isBST, min, max
        if (!root) return {0, true, INT_MAX, INT_MIN};

        auto [leftSum, leftIsBST, leftMin, leftMax] = solve(root->left);
        auto [rightSum, rightIsBST, rightMin, rightMax] = solve(root->right);

        if (!leftIsBST || !rightIsBST ||
            root->val <= leftMax ||
            root->val >= rightMin) {
            return {0, false, 0, 0};
        }

        int sum = leftSum + root->val + rightSum;
        result = max(result, sum);

        return {
            sum,
            true,
            min(root->val, leftMin),
            max(root->val, rightMax)
        };
    }

    int maxSumBST(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};
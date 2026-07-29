class Solution {
public:
    bool isValid;

    pair<long long, long long> check(TreeNode* root)
    {
        // {maximum, minimum}
        if(!root) return {LLONG_MIN, LLONG_MAX};

        auto [leftLargest, leftSmallest] = check(root->left);

        if(root->val <= leftLargest)
        {
            isValid = false;
            return {LLONG_MAX, LLONG_MIN};
        }

    
        auto [rightLargest, rightSmallest] = check(root->right);

        if(root->val >= rightSmallest)
        {
            isValid = false;
            return {LLONG_MAX, LLONG_MIN};
        }

        long long mx = max((long long)root->val, max(leftLargest, rightLargest));
        long long mn = min((long long)root->val,min(leftSmallest, rightSmallest));

        return {mx, mn};
    }

    bool isValidBST(TreeNode* root)
    {
        isValid = true;
        check(root);
        return isValid;
    }
};
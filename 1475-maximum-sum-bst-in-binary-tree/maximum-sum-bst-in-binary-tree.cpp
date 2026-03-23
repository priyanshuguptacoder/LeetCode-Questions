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
    int maxSum = 0;

    struct Info{
        int minVal, maxVal, sum;
        bool isBST;
    };

    Info helper(TreeNode* root){
        if(root == NULL){
            return {INT_MAX, INT_MIN, 0, true};
        }

        auto left = helper(root -> left);
        auto right = helper(root -> right);

        if(left.isBST && right.isBST && root -> val > left.maxVal && root -> val < right.minVal){
            int currSum = left.sum + right.sum + root -> val;
            maxSum = max(maxSum, currSum);

            return {min(root -> val, left.minVal), max(root -> val, right.maxVal), currSum, true};
        }
        return {INT_MIN, INT_MAX, 0, false};
    }
    
    int maxSumBST(TreeNode* root){
        helper(root);
        return maxSum;
    }
};
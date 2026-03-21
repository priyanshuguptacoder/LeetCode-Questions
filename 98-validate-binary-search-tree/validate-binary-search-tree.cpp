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
private:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL){
            return true;
        }

        if(min != NULL && root -> val <= min -> val){ //Left wale me root ka min se compare usse choota hona chahiye
            return false;
        }
        if(max != NULL && root -> val >= max -> val){ //Right wale me root ke max se bada hona chahiye
            return false;
        }

        return helper(root -> left, min, root) && helper(root -> right, root, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
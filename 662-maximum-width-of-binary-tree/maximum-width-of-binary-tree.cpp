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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); //Root and corresponding index
        int maxWidth = 0;

        while(q.size() > 0){
            int currLevelSize = q.size();
            unsigned long long strIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - strIdx + 1)); //Length of that corresponding level

            for(int i=0; i<currLevelSize; i++){
                auto curr = q.front();
                q.pop();

                if(curr.first -> left){ //Curr ka left exist karta hai toh
                    q.push({curr.first -> left, curr.second*2+1}); //Curr->left and uska corresponding idx
                }
                if(curr.first -> right){ //Curr ka right exist karta hai toh
                    q.push({curr.first -> right, curr.second*2+2}); //Curr->right and uska corresponding idx
                }
            }
        }
        return maxWidth;
    }
};
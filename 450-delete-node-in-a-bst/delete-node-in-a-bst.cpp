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
    TreeNode* getInorderSuccessor(TreeNode* root){ //Leftmost node in the right subtree
        while(root != NULL && root -> left != NULL){
            root = root -> left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else{ //key == root
            if(root -> left == NULL){ //0 or 1 children
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }

            else if(root -> right == NULL){ //0 or 1 children
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }

            else{ //2 children
                TreeNode* IS = getInorderSuccessor(root -> right);
                root -> val = IS -> val;
                root -> right = deleteNode(root -> right, IS -> val); 
            }
        }
        return root;
    }
};
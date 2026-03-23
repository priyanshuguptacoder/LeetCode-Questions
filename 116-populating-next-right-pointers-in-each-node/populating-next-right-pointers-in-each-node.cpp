/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root -> left == NULL){
            return root;
        }

        //Level order Traversal
        queue<Node*> q;
        q.push(root);
        q.push(NULL); //Mark at the end of level

        Node* prev = NULL;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){ //Har level ke baad
                if(q.size() == 0){ //When q will empty at last
                    break;
                } 
                q.push(NULL); //Level ke baad NULL daal dete hai so pata chal jaye wo wali level kab khatam ho rahi hai
            }
            
            else{
                if(curr -> left != NULL){
                    q.push(curr -> left);
                }
                if(curr -> right != NULL){
                    q.push(curr -> right);
                }

                if(prev != NULL){
                    prev -> next = curr;
                }
            }
            prev = curr; //prev == NULL
        }
        return root;
    }
};
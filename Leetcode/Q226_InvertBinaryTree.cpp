
// Two solutions
/*Ver 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        TreeNode* tmpNode = root;
        if(root!= NULL){
            tmpNode = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tmpNode);
        }
        return root;
    }
};
*/
//-------------------------------------
//Ver2
class Solution{
public:
   std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);            // right node is processed first
            std::swap(p->left, p->right);  // exchange current root's left and right
        }
    }
}
//-----------------------------------
/* Debug mode
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        if(p!=NULL) cout << "pop node value = " << p->val << endl;
        else cout << "pop NULL" << endl;
        stk.pop();
        if (p) {
            if(p->left!=NULL) cout << "p->left->val = " << p->left->val << endl;
            else cout << "p->left is NULL" << endl;
            stk.push(p->left);
            
            if(p->right!=NULL) cout << "p->right->val = " << p->right->val << endl;
            else cout << "p->right is NULL" << endl;
            stk.push(p->right);
            swap(p->left, p->right);
            cout << "after change: " ;
            if(p->left!=NULL) cout << "p->left->val = " << p->left->val ;
            else cout << ", p->left is NULL" ;
            if(p->right!=NULL) cout << ", p->right->val = " << p->right->val << endl;
            else cout << ", p->right is NULL" << endl;
        }
    }
        return root;
    }
};
*/

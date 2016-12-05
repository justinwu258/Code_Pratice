#include<iostream>
using namespace std;

//ref: https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode* > bufferStack;
        while((root!=NULL || !bufferStack.empty())  ){
            if(root!=NULL) {
                    bufferStack.push(root);
                    root = root->left;
            } else {
                ans.push_back(bufferStack.top()->val);
                root = bufferStack.top();
                bufferStack.pop();
                root = root->right; 
            }
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
    ref: https://leetcode.com/problems/validate-binary-search-tree/
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> buffer;
        while(root != NULL || !buffer.empty()){
            if(root!=NULL){
                buffer.push(root);
                root = root->left;
            } else {
                ans.push_back(buffer.top()->val);
                root = buffer.top();
                buffer.pop();
                root = root->right;
            }
        }
        int smallest = INT_MIN;
        int tmpMIN = INT_MIN;
        // cout << "ans.size = " << ans.size()<< endl;
        //cout << (-2147483647 > 2147483646) << endl;
        for(int i=0;i<ans.size();++i){
            // cout << "ans.at(i) = " << ans.at(i) << ", smallest = " << smallest << "ans.at(i)>smallest = " << (ans.at(i)>smallest) << endl;
            if(ans.size() == i+1) ;
            else if(ans.at(i) == ans.at(i+1)) return false; //there are same nodes in tree
            
            if(ans.at(i)>smallest) smallest = ans.at(i);
            else if(smallest==tmpMIN) {++smallest; ++tmpMIN;}
            else return false; //in-order visit, if there is node small than previous then it is not BST
        }
        return true;
    }
};
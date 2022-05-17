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
    TreeNode *temp,*result;
public:
    void inorder(TreeNode* original,TreeNode* cloned){
        if(original!=NULL){
            inorder(original->left,cloned->left);
            if(original==temp)      result = cloned;
            inorder(original->right,cloned->right);
        }
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        temp = target;
        inorder(original,cloned);
        return result;
    }
};
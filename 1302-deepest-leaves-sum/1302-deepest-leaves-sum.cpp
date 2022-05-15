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
    int sum = 0;    
private:
    int depth(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        return 1+max(depth(node->left),depth(node->right));
    }
public:
    void total_sum(TreeNode* node,int curr,int d){
        if(node!=NULL){
            if(curr==d)     sum += node->val;
            total_sum(node->left,curr+1,d);
            total_sum(node->right,curr+1,d);
        }
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)      return 0;
        int max_depth = depth(root);
        total_sum(root,1,max_depth);
        return sum;
    }
};
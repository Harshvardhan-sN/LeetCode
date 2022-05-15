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
    int maxi = 0;
private:
    int depth(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        return 1+max(depth(node->left),depth(node->right));
    }
public:
    void total_sum(TreeNode* node,int curr){
        if(node!=NULL){
            if(curr>maxi){
                sum = 0;
                maxi = curr;
            }
            if(curr==maxi){
                sum += node->val;
            }
            total_sum(node->left,curr+1);
            total_sum(node->right,curr+1);
        }
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)      return 0;
        // int max_depth = depth(root);
        total_sum(root,1);
        return sum;
    }
};